/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <souchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:30:46 by souchen           #+#    #+#             */
/*   Updated: 2022/08/11 15:36:26 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdbool.h>
# include \
	</Users/souchen/goinfre/.brew/opt/readline/include/readline/readline.h>
# include \
	</Users/souchen/goinfre/.brew/opt/readline/include/readline/history.h>
# include <sys/wait.h>
# include <signal.h>
# include <fcntl.h>
# include <dirent.h>

# define DOUBLE_QUOTE '\"'
# define QUOTE '\''
# define D_QUOTE_S "\""
# define QUOTE_S "\'"
# define WHITE "\001\033[0m\002"
# define GREEN "\001\033[1;32m\002"
# define RED "\033[0;31m"
# define PIPE_ERROR "Minishell: syntax error near unexpected token `|'\n"

typedef struct s_gl
{
	int	g_var;
	int	g_status;
}	t_gl;

t_gl	gl_var;

typedef struct s_env
{
	char	**env;
	int		len;
	char	**tmp_var;
	char	**tmp_con;
	int		position;
}	t_env;

typedef struct s_divise
{
	int	number_command;
	int	initial;
	int	len;
	int	quote;
	int	pipe;
}	t_divise;

typedef struct s_arg
{
	char	*all_cmd;
	char	*to_exec;
	char	*txt_toprint;
	char	quote;
	char	*seconde;
	char	*first;
	int		i;
	int		init;
	int		len;
	int		position;
}			t_arg;

typedef struct s_struct
{
	int			builtin_exist;
	int			last_redir;
	int			output_fd;
	int			input_fd;
	int			cmp;
	char		*line_commande;
	char		*commande_tape;
	char		*home;
	pid_t		pid;
	char		*commands[600000];
	char		**arguments;
	int			i;
	int			len;
	t_env		env_aux;
	t_env		env;
	t_divise	divise;
	t_arg		arg;
	int			q1;
	int			q2;
	int			dup_pipe;
	int			quote;
	int			double_quote;
	int			space;
	int			right;
	int			indice;
	char		**path;
}				t_struct;

int		builtin_exist(t_struct *shell);
void	run_builtin(t_struct *shell);
int		count_len_env(t_struct *shell);
void	ft_exit(t_struct *shell);
void	free_line(char *line_read);
void	ft_unset(t_struct *shell);
void	remove_env(t_struct *shell);
void	print_welcome(void);
void	run_commands(t_struct *shell);
void	run_commande_next(t_struct *shell);
int		fun_redirection(t_struct *shell);
void	execution(t_struct *shell);
void	divise_commande(t_struct *shell, char *in);
void	arguments_func(t_struct *shell);
int		argument_find_char(char *string, char needle);
void	free_arg(t_arg *arg);
void	finish_put_arg(t_struct *shell, t_arg *arg);
void	init_divise_struct(t_struct *shell);
void	ft_env(t_struct *shell);
void	ft_export(t_struct *shell);
bool	there_is_home(t_struct *shell);
int		ft_cd(t_struct *shell);
void	ft_pwd(t_struct *shell);
void	ft_echo(t_struct *shell);
int		init_echo(t_struct *shell, int n);
void	print_echo(t_struct *shell, char *shell_print);
void	ft_export(t_struct *shell);
void	verify_if_env_exists(t_struct *shell, char **env_aux);
void	export_to_env(t_struct *shell, char *tab1, char *tab2);
void	pipe_next(t_struct *shell, int i, char *command);
int		inredirection(t_struct *shell);
int		outredirection(t_struct *shell);
void	next_run_commands(t_struct *shell);
void	next(t_struct *shell, char*commande_read);
char	*execute_cmd(t_struct *shell);
void	output_input(t_struct *shell);
void	check_to_execute(t_struct *shell);
void	sig_handler(int signum);
void	cmd_not_found(t_struct *shell);
int		check_export(t_struct *export);
int		ft_search(t_struct *env, char *var);
int		malloc_env_tmp(t_struct *shell);
char	*find_env_tmp(t_struct *shell, char *search);
int		commande_tape(t_struct	*shell, int *size);
int		malloc_env_aux_tmp(t_struct *shell);
void	ft_die(char *str);
int		create_env_tmp(t_struct *shell, char **my_env);
int		start_create_env(t_struct *shell);
void	ft_die_malloc(char *str);
void	ft_check_env(char	**env);
void	ft_free_env(char **env);
void	ft_free_cmd(char **cmd);
int		is_empty(char *input);
void	ft_not_found(char *dir);
char	*ft_split_cmd(char *cmd);
int		ft_search_in_env(t_struct *env, char	*var, char *con);
void	ft_wait_pid(t_struct *shell);
void	ft_free(t_struct *shell);
void	get_exit_code(int status);
char	**get_path(t_struct *ptr);
void	next_execute_cmd(char **cmd_path);
void	process_shild_execute(char **path, t_struct *shell);
void	print_cmd_not_f(t_struct *shell);
void	signals(void);
void	restore_prompt(int sig);
void	ctrl_c(int sig);
void	back_slash(int sig);
int		ft_cd_tool(t_struct *shell);
char	*ft_oldpath(t_struct *shell);
void	ft_change_dir(t_struct *shell, char *chpath);
int		ft_check_cd(t_struct *shell);
void	replace_oldpwd(t_struct *env);
void	replace_pwd(t_struct *env);
void	ft_echo_tool(t_struct *shell, char *echo_print);
char	*remplir(char *s1, char c, int len);
void	arg_func(t_struct *shell);
int		find_char(char *string, char c);
char	*ft_split_cmd(char *cmd);
char	*ft_remove_quot(char *s1, char c);
int		next_inredirection(t_struct *shell);
t_arg	*init_arg(void);
void	echo_with_quote(char *echo_print, t_struct *shell);
void	echo_with_dollar(t_struct *shell, char **splt_quot);
void	swap_env(char **dup_env);
void	export_with_arg(t_struct *shell);
void	sort_env(t_struct *shell);
void	ft_print_export(char **exp, t_struct *shell);
void	next_export(t_struct *shell, char *new_elem_tab1, char *new_elem_tab2);
void	next_execute_commands(t_struct *shell, int i, char *command);
void	ft_cmd(char **env);
void	cmd_not_found2(t_struct *shell);
void	create_process(t_struct *shell);
char	*find_env(t_struct *shell, char *search);
#endif
