/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <souchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:21:38 by souchen           #+#    #+#             */
/*   Updated: 2022/08/11 16:25:43 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_echo(t_struct *shell)
{
	int	i;

	i = 1;
	shell->q1 = 0;
	shell->q2 = 0;
	shell->i = 0;
	if (shell->arguments[1] == NULL)
	{
		ft_putstr_fd("\n", shell->output_fd);
		return ;
	}
	if (!ft_strncmp(shell->arguments[1], "-n", 2))
			i++;
	while (shell->arguments[i])
	{
		if (shell->arguments[i])
		{
			print_echo(shell, shell->arguments[i]);
			ft_putstr_fd(" ", shell->output_fd);
		}
		i++;
	}
	if (ft_strncmp(shell->arguments[1], "-n", 2))
		ft_putstr_fd("\n", shell->output_fd);
}

void	print_echo(t_struct *shell, char *echo_print)
{
	size_t	i;
	char	**splt_quot;

	i = 0;
	splt_quot = ft_split(echo_print, '"');
	printf("splt[0]=%s\n", splt_quot[0]);
	if (splt_quot[0] == NULL)
	{
		ft_putstr_fd(" ", shell->output_fd);
		return ;
	}
	if (!ft_strcmp(echo_print, "$?"))
	{
		ft_putnbr_fd(gl_var.g_status, shell->output_fd);
		printf("\n");
	}
	else if (!ft_strncmp(splt_quot[0], "$", 1))
	{
		echo_with_dollar(shell, splt_quot);
	}
	if (splt_quot[0] != NULL && ft_strncmp(splt_quot[0], "$", 1))
	{
		ft_putstr_fd(splt_quot[0], shell->output_fd);
	}
	ft_free_cmd(splt_quot);
}

void	echo_with_dollar(t_struct *shell, char **splt_quot)
{
	char	**splted;
	int		i;

	i = 0;
	if (!shell->path)
		return ;
	splted = ft_split(splt_quot[0], '$');
	while (shell->env.tmp_var[i])
	{
		if (!ft_strcmp(shell->env.tmp_var[i], splted[0]))
		{
			ft_free_cmd(splted);
			ft_putstr_fd(shell->env.tmp_con[i], shell->output_fd);
			return ;
		}
		i++;
	}
	ft_free_cmd(splted);
	return ;
}
