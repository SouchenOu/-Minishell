/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili < yismaili@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:22:00 by souchen           #+#    #+#             */
/*   Updated: 2022/08/08 21:33:19 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

char	*get_current_dir(void)
{
	size_t	size;
	char	*buf;

	size = 2000;
	buf = NULL;
	buf = getcwd(buf, size);
	return (buf);
}

void	ft_pwd(t_struct *shell)
{
	char	*buf;

	buf = get_current_dir();
	if (!buf)
		return ;
	ft_putstr_fd(buf, shell->output_fd);
	ft_putstr_fd("\n", shell->output_fd);
	free(buf);
}
