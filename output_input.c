/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <souchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:56:43 by souchen           #+#    #+#             */
/*   Updated: 2022/08/11 16:37:20 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	outredirection(t_struct *shell)
{
	char	*fichier1;

	if (shell->commands[shell->cmp][1] == '>')
	{
		fichier1 = ft_strtrim(&shell->commands[shell->cmp][2], " ");
		printf("fichier1= %s\n", fichier1);
		if(((fichier1[0] == '\"' || fichier1[0] == '\'') || (fichier1[ft_strlen(fichier1) - 1] == '\"' || fichier1[ft_strlen(fichier1) - 1] == '\'')) && ((ft_strlen(fichier1)== 2) || ft_strlen(fichier1) == 0))
		{
			gl_var.g_status = 258;
			ft_putstr_fd("bash: : No such file or directory\n", 2);
			return 0;
		}
		else if(((fichier1[0] == '\"' || fichier1[0] == '\'') || (fichier1[ft_strlen(fichier1) - 1] == '\"' || fichier1[ft_strlen(fichier1) - 1] == '\'')) && (ft_strlen(fichier1) > 2))
		{
			fichier1=ft_split_cmd(fichier1);
		}
		shell->output_fd = open(fichier1, O_CREAT | O_WRONLY | O_APPEND, 0777);
		if (shell->output_fd == -1)
			printf("Open Error\n");
		free(fichier1);
	}
	else
	{
		fichier1 = ft_strtrim(&shell->commands[shell->cmp][1], " ");
		if(((fichier1[0] == '\"' || fichier1[0] == '\'') || (fichier1[ft_strlen(fichier1) - 1] == '\"' || fichier1[ft_strlen(fichier1) - 1] == '\'')) && ((ft_strlen(fichier1)== 2)|| ft_strlen(fichier1) == 0))
		{
			printf("hna\n");
			gl_var.g_status = 258;
			ft_putstr_fd("bash: : No such file or directory\n", 2);
			return 0;
		}
		else if(((fichier1[0] == '\"' || fichier1[0] == '\'') || (fichier1[ft_strlen(fichier1) - 1] == '\"' || fichier1[ft_strlen(fichier1) - 1] == '\'')) && (ft_strlen(fichier1) > 2))
		{
			fichier1=ft_split_cmd(fichier1);
		}
		shell->output_fd = open(fichier1, O_CREAT | O_WRONLY | O_TRUNC , 0777);
		if (shell->output_fd == -1)
			printf("Open error\n");
		free(fichier1);
	}
	return 1;
}

int	inredirection(t_struct	*shell)
{
	char	*fichier2;
	char	*line;

	if (shell->commands[shell->cmp][1] == '<')
	{
		fichier2 = ft_strtrim(&shell->commands[shell->cmp][2], " ");
		if(((fichier2[0] == '\"' || fichier2[0] == '\'') || (fichier2[ft_strlen(fichier2) - 1] == '\"' || fichier2[ft_strlen(fichier2) - 1] == '\'')) && ((ft_strlen(fichier2)== 2)|| ft_strlen(fichier2) == 0))
		{
			gl_var.g_status = 258;
			ft_putstr_fd("bash: : No such file or directory\n", 2);
			return 0;
		}
		else if(((fichier2[0] == '\"' || fichier2[0] == '\'') || (fichier2[ft_strlen(fichier2) - 1] == '\"' || fichier2[ft_strlen(fichier2) - 1] == '\'')) && (ft_strlen(fichier2) > 2))
		{
			fichier2=ft_split_cmd(fichier2);
		}
		line = ft_strdup("");
	    if (ft_strncmp(fichier2, "$", 1) == 0)
		{
			if(find_env_tmp(shell, (&fichier2[1])) != NULL)
			{
					while(ft_strcmp(line, shell->env.tmp_con[shell->env.position]))
					{
						free(line);
						line = readline("herDoc> ");	
					}
					free(line);
			}
		}
		else
		{
			while (ft_strcmp(line, fichier2))
			{
				free(line);
				line = readline("herDoc> ");
			}
			free(line);
		}
	}
	else
	{
		if (next_inredirection(shell) == 0)
			return 0;
	}
	return 1;
}

int	next_inredirection(t_struct *shell)
{
	char	*fichier2;

	fichier2 = ft_strtrim(&shell->commands[shell->cmp][2], " ");
	if(((fichier2[0] == '\"' || fichier2[0] == '\'') || (fichier2[ft_strlen(fichier2) - 1] == '\"' || fichier2[ft_strlen(fichier2) - 1] == '\'')) && ((ft_strlen(fichier2)== 2)|| ft_strlen(fichier2) == 0))
	{
			gl_var.g_status = 258;
			ft_putstr_fd("bash: : No such file or directory\n", 2);
			return 0;
	}
	else if(((fichier2[0] == '\"' || fichier2[0] == '\'') || (fichier2[ft_strlen(fichier2) - 1] == '\"' || fichier2[ft_strlen(fichier2) - 1] == '\'')) && (ft_strlen(fichier2) > 2))
	{
			fichier2=ft_split_cmd(fichier2);
	}
	shell->input_fd = open(fichier2, O_RDONLY, 0777);
	if (shell->input_fd == -1)
		printf("Open error\n");
	return 1;
}

int	fun_redirection(t_struct *shell)
{
	shell->line_commande = ft_strdup(shell->commands[shell->cmp]);
	if (shell->divise.number_command > 1)
		shell->cmp++;
	while (shell->commands[shell->cmp] && \
			(shell->commands[shell->cmp][0] == '<' || \
			shell->commands[shell->cmp][0] == '>'))
	{
		if (shell->commands[shell->cmp][0] == '>')
		{
			if (outredirection(shell) == 0)
				return 0;
		}
		else if (shell->commands[shell->cmp][0] == '<')
		{
			if(inredirection(shell) == 0)
				return 0;
		}
		shell->cmp++;
	}
	return 1;
}

void	output_input(t_struct	*shell)
{
	if (shell->output_fd != 1)
	{
		dup2(shell->output_fd, STDOUT_FILENO);
		close(shell->output_fd);
	}
	if (shell->input_fd != 0)
	{
		dup2(shell->input_fd, STDIN_FILENO);
		close(shell->input_fd);
	}
}
