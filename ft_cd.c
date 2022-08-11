/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili < yismaili@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:21:32 by souchen           #+#    #+#             */
/*   Updated: 2022/08/10 17:49:50 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	replace_oldpwd(t_struct *env)
{
	char	*buff;
	int		i;

	buff = NULL;
	buff = getcwd(buff, sizeof(buff));
	if (gl_var.g_var == 0)
	{
		env->env.tmp_con[0] = ft_strdup(buff);
		free(buff);
		return ;
	}
	i = 0;
	while (env->env.tmp_var[i])
	{
		if (!ft_strcmp(env->env.tmp_var[i], "OLDPWD"))
		{
			env->env.tmp_con[i] = ft_strdup(buff);
			free(buff);
			return ;
		}
		i++;
	}
	free(buff);
}

void	replace_pwd(t_struct *env)
{
	char	*buff;
	int		i;

	buff = NULL;
	buff = getcwd(buff, sizeof(buff));
	if (gl_var.g_var == 0)
	{
		env->env.tmp_con[0] = ft_strdup(buff);
		return ;
	}
	i = 0;
	while (env->env.tmp_var[i])
	{
		if (!ft_strcmp(env->env.tmp_var[i], "PWD"))
		{
			free(env->env.tmp_con[i]);
			env->env.tmp_con[i] = ft_strdup(buff);
			free(buff);
			return ;
		}
		i++;
	}
	free(buff);
}

int	ft_cd(t_struct *shell)
{
	char	*arg_aux;

	arg_aux = NULL;
	if (!ft_check_cd(shell))
		return (0);
	if (shell->arguments[1])
		arg_aux = ft_strdup(shell->arguments[1]);
	else if (!shell->arguments[1])
	{
		arg_aux = find_env(shell, "HOME");
		if (!arg_aux)
		{
			ft_putstr_fd("Minishell: cd: HOME not set\n", 2);
			return (1);
		}
	}
	ft_change_dir(shell, arg_aux);
	free(arg_aux);
	return (0);
}

int	ft_check_cd(t_struct *shell)
{
	if (shell->arguments[1] && !ft_strcmp(shell->arguments[1], "-"))
	{
		ft_cd_tool(shell);
		return (0);
	}
	return (1);
}

int	ft_cd_tool(t_struct *shell)
{
	char	*current_path;
	char	*old_path;
	char	*tmp;

	tmp = NULL;
	current_path = getcwd(NULL, sizeof(NULL));
	old_path = ft_oldpath(shell);
	if (!ft_strcmp(current_path, old_path))
		ft_putstr_fd("Minishell: cd: OLDPWD not set\n", 2);
	else
	{
		if (ft_strcmp(old_path, current_path))
		{
			ft_change_dir(shell, old_path);
			tmp = getcwd(NULL, sizeof(NULL));
			ft_putstr_fd(tmp, shell->output_fd);
			printf("\n");
			free(tmp);
		}
	}
	free(current_path);
	return (0);
}
