/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 08:30:18 by mel-houd          #+#    #+#             */
/*   Updated: 2023/12/22 00:58:33 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	process_job(int *fd, char **exec_args, int inout, char str)
{
	if (str == 'i')
	{
		close(fd[0]);
		dup2(fd[1], 1);
		dup2(inout, 0);
		close(fd[1]);
		close(inout);
		execve(exec_args[0], exec_args, NULL);
		perror("execve error");
		exit(0);
	}
	else if (str == 'o')
	{
		close(fd[1]);
		dup2(fd[0], 0);
		dup2(inout, 1);
		close(fd[0]);
		close(inout);
		execve(exec_args[0], exec_args, NULL);
		perror("execve error");
		exit(0);
	}
}

void	main_helper(t_pipex *args)
{
	close(args->fd[0]);
	close(args->fd[1]);
	close(args->input);
	close(args->output);
	waitpid(args->pid, NULL, 0);
	waitpid(args->pid2, NULL, 0);
}

t_pipex	*pipex(int ac, char **av, char **env)
{
	t_pipex	*args;

	if (mini_parser(av, ac) == 1)
		return (NULL);
	args = (t_pipex *)malloc(sizeof(t_pipex));
	if (!args)
		return (NULL);
	if (init_variables(args, av, env) == 1)
		return (args);
	args->pid = fork();
	if (check_pid(args->pid) == 1)
		return (args);
	if (args->pid == 0)
		process_job(args->fd, args->exec_args, args->input, 'i');
	args->pid2 = fork();
	if (check_pid(args->pid2) == 1)
		return (args);
	if (args->pid2 == 0)
		process_job(args->fd, args->exec_args2, args->output, 'o');
	if (args->pid != 0 && args->pid2 != 0)
		main_helper(args);
	return (args);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	*args;

	if (ac == 5)
	{
		args = pipex(ac, av, env);
		if (args == NULL)
			return (1);
		else
		{
			free_dpointer(args);
			free(args);
			return (0);
		}
	}
	else
	{
		ft_printf("usage : infile cmd1 cmd2 outfile\n");
		return (1);
	}
	return (0);
}
