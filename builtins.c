/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili < yismaili@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:21:06 by souchen           #+#    #+#             */
/*   Updated: 2022/08/03 19:42:11 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	builtin_exist(t_struct	*shell)
{
	if (!ft_strcmp(shell->arguments[0], "exit"))
		shell->builtin_exist = 1;
	else if (!ft_strcmp(shell->arguments[0], "unset"))
		shell->builtin_exist = 1;
	else if (!ft_strcmp(shell->arguments[0], "env"))
		shell->builtin_exist = 1;
	else if (!ft_strcmp(shell->arguments[0], "cd"))
		shell->builtin_exist = 1;
	else if (!ft_strcmp(shell->arguments[0], "pwd"))
		shell->builtin_exist = 1;
	else if (!ft_strcmp(shell->arguments[0], "echo"))
		shell->builtin_exist = 1;
	else if (!ft_strcmp(shell->arguments[0], "export"))
		shell->builtin_exist = 1;
	else
		shell->builtin_exist = 0;
	return (0);
}

void	run_builtin(t_struct *shell)
{
	if (!ft_strcmp(shell->arguments[0], "exit"))
		ft_exit(shell);
	else if (!ft_strcmp(shell->arguments[0], "unset"))
		ft_unset(shell);
	else if (!ft_strcmp(shell->arguments[0], "env"))
		ft_env(shell);
	else if (!ft_strcmp(shell->arguments[0], "cd"))
		ft_cd(shell);
	else if (!ft_strcmp(shell->arguments[0], "pwd"))
		ft_pwd(shell);
	else if (!ft_strcmp(shell->arguments[0], "echo"))
		ft_echo(shell);
	else if (!ft_strcmp(shell->arguments[0], "export"))
		ft_export(shell);
}
