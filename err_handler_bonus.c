/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_handler_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 02:51:55 by mel-houd          #+#    #+#             */
/*   Updated: 2023/12/22 00:36:38 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	error_handler(t_pipex *args)
{
	if (args->input == -1 || args->output == -1)
	{
		ft_printf("problem in generating fd\n");
		return (1);
	}
	if (!args->fd)
	{
		ft_printf("problem generating pipes !\n");
		return (1);
	}
	if (!args->splited_path || !args->str || !args->exec_args)
	{
		ft_printf("command not found !\n");
		close(args->input);
		close(args->output);
		return (1);
	}
	return (0);
}

int	check_pid(int pid)
{
	if (pid == -1)
	{
		perror("fork error\n");
		return (1);
	}
	return (0);
}

void	free_help(t_pipex *args)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (args->exec_args)
	{
		while (args->exec_args[i])
		{
			j = 0;
			while (args->exec_args[i] && args->exec_args[i][j])
				free(args->exec_args[i][j++]);
			free(args->exec_args[i]);
			i++;
		}
	}
	free(args->exec_args);
	free(args->str);
	free(args->pid);
	if (args->change_av != NULL)
		free(args->change_av);
}

void	free_dpointer(t_pipex *args)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (args->fd)
	{
		while (i < args->ac - 4)
		{
			close(args->fd[i][0]);
			close(args->fd[i][1]);
			free(args->fd[i++]);
		}
		free(args->fd);
	}
	free_help(args);
	i = 0;
	if (args->splited_path)
	{
		while (args->splited_path[i])
			free(args->splited_path[i++]);
		free(args->splited_path);
	}
	args->freed = 1;
}
