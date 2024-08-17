/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 02:50:08 by mel-houd          #+#    #+#             */
/*   Updated: 2023/12/22 01:00:18 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include "./libft/printf/ft_printf.h"

typedef struct s_pipex
{
	int		input;
	int		output;
	char	**str;
	char	**str2;
	int		fd[2];
	int		pid;
	int		pid2;
	char	**exec_args;
	char	**exec_args2;
	char	**splited_path;
}	t_pipex;

int		check_only_spaces(char *str);
int		mini_parser(char **av, int ac);
char	**check_command(char *command, char **path_splited);
char	**check_command_help(char **com, char **path_splited, int key);
int		error_handler(t_pipex *args);
int		check_pid(int pid);
void	free_dpointer(t_pipex *args_add);
void	free_help(t_pipex *args);
int		init_variables(t_pipex *args, char **av, char **env);
void	process_job(int *fd, char **exec_args, int inout, char str);
char	**split_path(char **env_addrs);
t_pipex	*pipex(int ac, char **av, char **env);

#endif