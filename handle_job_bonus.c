/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_job_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:04:23 by mel-houd          #+#    #+#             */
/*   Updated: 2023/12/22 00:36:31 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	first_proc(t_pipex *args, int i)
{
	pipe_ctl(args, i);
	dup2(args->fd[0][1], 1);
	dup2(args->input, 0);
	close(args->fd[0][1]);
	close(args->input);
	close(args->output);
	execve(args->exec_args[0][0], args->exec_args[0], args->env);
	perror("execve error");
	exit(0);
}

void	last_proc(t_pipex *args, int i)
{
	pipe_ctl(args, i);
	dup2(args->output, 1);
	dup2(args->fd[i - 1][0], 0);
	close(args->fd[i - 1][0]);
	close(args->input);
	close(args->output);
	execve(args->exec_args[i][0], args->exec_args[i], args->env);
	perror("execve error");
	exit(0);
}

void	middle_proc(t_pipex *args, int i)
{
	pipe_ctl(args, i);
	dup2(args->fd[i - 1][0], 0);
	dup2(args->fd[i][1], 1);
	close(args->fd[i][1]);
	close(args->fd[i - 1][0]);
	close(args->output);
	close(args->input);
	execve(args->exec_args[i][0], args->exec_args[i], args->env);
	perror("execve error");
	exit(0);
}
