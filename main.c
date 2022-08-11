/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili < yismaili@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:22:19 by souchen           #+#    #+#             */
/*   Updated: 2022/08/10 17:23:43 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		gl_var.g_status = 1;
		ft_putstr_fd("\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else if (sig == SIGQUIT)
	{
		ft_putstr_fd("\n", 1);
	}
}

void	signals(void)
{
	if (signal(SIGINT, sig_handler) == SIG_ERR)
		ft_putstr_fd(RED"Error cnrtl-C", 2);
	if (signal(SIGQUIT, sig_handler) == SIG_ERR)
		ft_putstr_fd(RED"Error cntrl-\\", 2);
}

int	main(void)
{
	t_struct	shell;
	int			size;

	gl_var.g_status = 0;
	print_welcome();
	start_create_env(&shell);
	signals();
	while (1)
	{
		commande_tape(&shell, &size);
		if (shell.commande_tape && !is_empty(shell.commande_tape))
		{
			if (shell.commande_tape[0])
			{
				divise_commande(&shell, shell.commande_tape);
				if (shell.commands[0][0] != '|' && shell.commande_tape
					[size - 1] != '|' && shell.dup_pipe == 0)
					run_commands(&shell);
				else
					ft_putstr_fd(PIPE_ERROR, 2);
			}
		}
		free(shell.commande_tape);
	}
}	

void	print_welcome(void)
{
	printf("%s*****************************************************\n", RED);
	printf("%s|                                                   |\n", RED);
	printf("%s|     Welcome to Souchen && Yismaili Minishell      |\n", RED);
	printf("%s|                                                   |\n", RED);
	printf("%s*****************************************************\n", RED);
}

int	commande_tape(t_struct	*shell, int *size)
{
	shell->quote = 0;
	shell->double_quote = 0;
	shell->indice = 0;
	shell->right = 0;
	shell->output_fd = 1;
	shell->input_fd = 0;
	rl_catch_signals = 0;
	shell->commande_tape = readline(GREEN"Minishell-1.0$ "WHITE);
	*size = ft_strlen(shell->commande_tape);
	if (shell->commande_tape && is_empty(shell->commande_tape) != 1)
		add_history(shell->commande_tape);
	if (!shell->commande_tape)
		exit(1);
	return (1);
}
