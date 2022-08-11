/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili < yismaili@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:20:16 by souchen           #+#    #+#             */
/*   Updated: 2022/08/08 21:28:36 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

#include "includes/minishell.h"

void	arguments_func(t_struct	*shell)
{
	t_arg	*arg;

	arg = init_arg();
	shell->arguments = NULL;
	if (shell->line_commande)
	{
		arg->position = find_char(shell->line_commande, ' ');
		arg_func(shell);
	}
	free(shell->line_commande);
	free(arg);
}

int	ft_check_quote(t_struct *shell)
{
	int		i;

	i = 0;
	while (i < (int)ft_strlen(shell->line_commande))
	{
		if (shell->line_commande[i] == QUOTE)
			shell->quote++;
		else if (shell->line_commande[i] == DOUBLE_QUOTE)
			shell->double_quote++;
		i++;
	}
	i = 0;
	while (shell->line_commande[i] != '\0')
	{
		if (ft_isalpha(shell->line_commande[i]) || \
			shell->line_commande[i] == '\"' || shell->line_commande[i] == '\'')
			return (i);
		i++;
	}
	return (0);
}

void	ft_check_space(t_struct *shell, int size, int pos)
{
	int		i;

	i = 1;
	shell->space = 0;
	while (i < size && (&shell->line_commande[pos])[i] != '\"')
	{
		if ((&shell->line_commande[pos])[i] == ' ')
		{
			shell->space = 1;
			break ;
		}
		i++;
	}
}

void	ft_check_quote_pos(t_struct *shell, int pos, int size, char	*cmd_joined)
{
	if (((&shell->line_commande[pos])[0] == '\"' \
		&& (&shell->line_commande[pos])[size - 2] == '\"') \
		|| ((&shell->line_commande[pos])[0] == '\'' && \
		(&shell->line_commande[pos])[size - 2] == '\''))
		shell->indice++;
	if (((&shell->line_commande[pos])[0] == '\"' \
		&& (&shell->line_commande[pos])[size - 1] == '\"') \
		|| ((&shell->line_commande[pos])[0] == '\'' \
		&& (&shell->line_commande[pos])[size - 1] == '\''))
		shell->indice++;
	if (shell->space == 1 && shell->indice == 1)
		shell->right = 1;
	if (((&shell->line_commande[pos])[0] == '\"') || \
	((&shell->line_commande[pos])[0] == '\'') || \
		((&shell->line_commande[pos])[size - 1] == '\"') || \
		((&shell->line_commande[pos])[size - 1] == '\''))
	{
		cmd_joined = ft_split_cmd(shell->line_commande);
		shell->arguments = ft_split(cmd_joined, ' ');
		free(cmd_joined);
	}
	else
		shell->arguments = ft_split(shell->line_commande, ' ');
}

void	arg_func(t_struct *shell)
{
	int		size;
	char	*cmd_joined;
	int		pos;

	shell->indice = 0;
	cmd_joined = NULL;
	size = ft_strlen(shell->line_commande);
	pos = ft_check_quote(shell);
	size = ft_strlen(&shell->line_commande[pos]);
	ft_check_space(shell, size, pos);
	ft_check_quote_pos(shell, pos, size, cmd_joined);
}
