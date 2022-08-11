/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divise_commande.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili < yismaili@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:21:25 by souchen           #+#    #+#             */
/*   Updated: 2022/08/03 15:34:04 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	initial_divise(t_struct *shell)
{
	shell->divise.number_command = 0;
	shell->divise.initial = 0;
	shell->divise.quote = 0;
	shell->divise.pipe = 0;
	shell->cmp = 0;
	shell->i = 0;
	shell->len = 0;
	shell->dup_pipe = 0;
}

void	command(t_struct *shell, char *commande_read)
{
	if (shell->i > 1)
	{
		shell->commands[shell->divise.number_command] = \
			ft_substr(commande_read, shell->divise.initial, shell->len);
		shell->divise.initial = shell->i;
		shell->len = 0;
		shell->divise.number_command++;
	}
}

void	divise_commande(t_struct *shell, char *commande_read)
{
	initial_divise(shell);
	while (shell->i < (int)ft_strlen(commande_read))
	{
		if (commande_read[shell->i] == '|' || \
			commande_read[shell->i] == '<' || commande_read[shell->i] == '>')
		{
			if (commande_read[shell->i] == '|')
				shell->divise.pipe++;
			if (commande_read[shell->i] == '|'
				&& commande_read[shell->i +1] == '|')
				shell->dup_pipe = 1;
			command(shell, commande_read);
			if (commande_read[shell->i + 1] == commande_read[shell->i])
			{
				shell->i++;
				shell->len = 1;
			}
		}
		shell->i++;
		shell->len++;
	}
	next (shell, commande_read);
}

void	next(t_struct *shell, char *commande_read)
{
	if (ft_strlen(commande_read) > 0)
	{
		shell->commands[shell->divise.number_command] = \
			ft_substr(commande_read, shell->divise.initial, shell->i);
		shell->divise.number_command++;
	}
	shell->commands[shell->divise.number_command] = NULL;
}
