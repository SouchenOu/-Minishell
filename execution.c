/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili < yismaili@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:22:25 by souchen           #+#    #+#             */
/*   Updated: 2022/08/10 15:07:56 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	ft_check_quotes(t_struct *shell)
{
	if (shell->quote % 2 != 0 || shell->double_quote % 2 != 0
		|| (shell->right == 1))
	{
		cmd_not_found2(shell);
		return (1);
	}
	run_builtin(shell);
	ft_free_cmd(shell->arguments);
	return (0);
}

void	execution(t_struct *shell)
{
	int		i;

	i = 0;
	builtin_exist(shell);
	if (shell->builtin_exist == 1)
	{
		if (ft_check_quotes(shell) == 1)
			return ;
	}
	else if (!shell->path)
		print_cmd_not_f(shell);
	else
		create_process(shell);
}

void	create_process(t_struct *shell)
{
	shell->pid = fork();
	if (shell->pid < 0)
	{
		ft_putstr_fd("Minishell: fork: Resource", 2);
		ft_putstr_fd(" temporarily unavailable\n", 2);
		exit (1);
	}
	else if (shell->pid == 0)
	{
		output_input(shell);
		if (shell->arguments[0] != NULL)
			execute_cmd(shell);
	}
	ft_free_cmd(shell->arguments);
}

void	ft_check_arg(t_struct *shell, char *cmd_path)
{
	if (shell->arguments[0][0] == '|' && shell->arguments[1])
	{
		if (!shell->arguments[0][1])
			next_execute_commands(shell, 2, cmd_path);
		else
		{
			shell->arguments[0] = &shell->arguments[0][1];
			next_execute_commands(shell, 1, cmd_path);
		}
	}
	else if (shell->arguments[0][0] == '|' && shell->arguments[1] == NULL)
	{
		shell->arguments[0] = &shell->arguments[0][1];
		next_execute_commands(shell, 1, cmd_path);
	}
	else
		next_execute_commands(shell, 1, cmd_path);
}

char	*execute_cmd(t_struct *shell)
{
	int		i;
	char	*cmd_path;

	i = 0;
	cmd_path = NULL;
	execve(shell->arguments[0], &shell->arguments[0], shell->env.env);
	while (shell->path[i])
	{
		cmd_path = ft_strjoin(shell->path[i], "/");
		if (shell->quote % 2 != 0 || shell->double_quote % 2 != 0
			|| (shell->right == 1))
		{
			cmd_not_found(shell);
		}
		ft_check_arg(shell, cmd_path);
		i++;
	}
	cmd_not_found(shell);
	return (NULL);
}
