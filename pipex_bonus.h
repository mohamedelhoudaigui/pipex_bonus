/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 02:50:08 by mel-houd          #+#    #+#             */
/*   Updated: 2023/12/22 00:34:13 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include "./libft/get_next_line.h"
# include "./libft/printf/ft_printf.h"

typedef struct s_pipex
{
	int		input;
	int		output;
	int		ac;
	pid_t	*pid;
	int		freed;
	int		**fd;
	char	**av;
	char	**change_av;
	char	**env;
	char	**splited_path;
	char	***str;
	char	***exec_args;
}	t_pipex;

void	first_proc(t_pipex *args, int i);
void	last_proc(t_pipex *args, int i);
void	middle_proc(t_pipex *args, int i);
int		check_only_spaces(char *str);
int		mini_parser(char **av);
int		here_doc_parse(char **av);
char	**check_command(char *command, char **path_splited);
char	**check_command_help(char **com, char **path_splited, int key);
char	***all_commands(t_pipex *args);
void	free_all_commands(char ***all_command);
int		error_handler(t_pipex *args);
int		check_pid(int pid);
void	free_dpointer(t_pipex *args_add);
void	free_help(t_pipex *args);
void	init_args(t_pipex *args);
int		init_variables(t_pipex *args, char **av, char **env, int ac);
void	init_helper(t_pipex *args, char **av, char **env, int ac);
void	process_job(t_pipex *args, int i);
char	**split_path(char **env_addrs);
t_pipex	*pipex(int ac, char **av, char **env);
void	pipe_ctl(t_pipex *args, int i);
int		here_doc(t_pipex *args);
void	change_av(t_pipex *args);
void	init_pipes(t_pipex *args);
void	init_pid(t_pipex *args);

#endif