/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili < yismaili@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:21:18 by souchen           #+#    #+#             */
/*   Updated: 2022/08/09 22:45:54 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	create_env_tmp(t_struct *shell, char **my_env)
{
	int		i;
	char	**env_divise;

	shell->env.env = my_env;
	count_len_env(shell);
	if (!malloc_env_tmp(shell))
		ft_die_malloc("No spece lift\n");
	i = 0;
	while (shell->env.env[i])
	{
		env_divise = ft_split(shell->env.env[i], '=');
		shell->env.tmp_var[i] = ft_strdup(env_divise[0]);
		if (env_divise[1])
			shell->env.tmp_con[i] = ft_strdup(env_divise[1]);
		else
			shell->env.tmp_con[i] = ft_strdup("");
		if (env_divise)
			ft_free_env(env_divise);
		i++;
	}
	shell->env.tmp_var[i] = 0;
	shell->env.tmp_con[i] = 0;
	return (1);
}
