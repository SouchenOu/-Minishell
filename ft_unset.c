/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili < yismaili@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:22:05 by souchen           #+#    #+#             */
/*   Updated: 2022/08/09 22:58:38 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_unset(t_struct *shell)
{
	int	i;

	i = 1;
	while (shell->arguments[i])
	{
		if (find_env_tmp(shell, shell->arguments[i]))
		{
			remove_env(shell);
		}
		i++;
	}
}

void	remove_env(t_struct *shell)
{
	int	i;
	int	j;

	shell->env.len--;
	if (!malloc_env_aux_tmp(shell))
		ft_die_malloc("No spece lift\n");
	i = 0;
	j = 0;
	while (i < shell->env.len)
	{
		if (i != shell->env.position)
		{
			shell->env_aux.tmp_var[j] = ft_strdup(shell->env.tmp_var[i]);
			shell->env_aux.tmp_con[j] = ft_strdup(shell->env.tmp_con[i]);
			j++;
		}
		i++;
	}
	shell->env_aux.tmp_var[j] = NULL;
	shell->env_aux.tmp_con[j] = NULL;
	ft_free_env(shell->env.tmp_var);
	ft_free_env(shell->env.tmp_con);
	shell->env.tmp_var = shell->env_aux.tmp_var;
	shell->env.tmp_con = shell->env_aux.tmp_con;
}

int	malloc_env_aux_tmp(t_struct *shell)
{
	shell->env_aux.tmp_var = malloc(sizeof(char *) * (shell->env.len + 1));
	if (!shell->env_aux.tmp_var)
		return (0);
	shell->env_aux.tmp_con = malloc(sizeof(char *) * (shell->env.len + 1));
	if (!shell->env_aux.tmp_con)
		return (0);
	return (1);
}
