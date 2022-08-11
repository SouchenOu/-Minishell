/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili < yismaili@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:20:16 by souchen           #+#    #+#             */
/*   Updated: 2022/08/10 17:38:52 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

char	*ft_split_cmd(char	*cmd)
{
	char	*join;

	join = NULL;
	if (ft_strchr(cmd, '\"'))
		join = ft_remove_quot(cmd, '\"');
	else if (ft_strchr(cmd, '\''))
		join = ft_remove_quot(cmd, '\'');
	return (join);
}

void	cmd_not_found2(t_struct *shell)
{
	gl_var.g_status = 127;
	if (shell->arguments[0][0] != '|')
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(shell->arguments[0], 2);
		ft_putstr_fd(": command not found\n", 2);
	}
	else if (shell->arguments[1])
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(shell->arguments[1], 2);
		ft_putstr_fd(": command not found\n", 2);
	}
}

void	next_execute_commands(t_struct *shell, int i, char *command)
{
	char	*aux;
	char	**test;
	int		k;

	k = 0;
	aux = NULL;
	if (shell->arguments[1] && (shell->arguments[1][0] == QUOTE || \
		shell->arguments[1][0] == DOUBLE_QUOTE))
	{
		while (k < (int)ft_strlen(shell->arguments[1]))
		{
			if (shell->arguments[1][k] == '"' \
				|| shell->arguments[1][k] == QUOTE)
				shell->arguments[1][k] = '<';
			aux = ft_strtrim(shell->arguments[1], "<");
			k++;
		}
		test = ft_split(aux, '<');
		shell->arguments[1] = test[0];
	}
	command = ft_strjoin(command, shell->arguments[i - 1]);
	execve(command, &shell->arguments[i - 1], shell->env.env);
}

void	cmd_not_found(t_struct *shell)
{
	gl_var.g_status = 127;
	if (shell->arguments[0][0] != '|')
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(shell->arguments[0], 2);
		ft_putstr_fd(": command not found\n", 2);
	}
	else if (shell->arguments[1])
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(shell->arguments[1], 2);
		ft_putstr_fd(": command not found\n", 2);
	}
	exit(gl_var.g_status);
}

char	*find_env(t_struct *shell, char *search)
{
	int	i;

	i = 0;
	shell->env.position = 0;
	if (gl_var.g_var == 0)
		return (NULL);
	while (shell->env.tmp_var[i] && i <= shell->env.len)
	{
		if (!ft_strcmp(shell->env.tmp_var[i], search))
		{
			shell->env.position = i;
			return (shell->env.tmp_con[i]);
		}
		i++;
	}
	return (NULL);
}
