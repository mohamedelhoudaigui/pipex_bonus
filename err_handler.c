/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 02:51:55 by mel-houd          #+#    #+#             */
/*   Updated: 2023/12/22 00:54:23 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	error_handler(t_pipex *args)
{
	if (args->input == -1 || args->output == -1)
	{
		ft_printf("problem in generating fd\n");
		return (1);
	}
	if (pipe(args->fd) == -1)
	{
		perror("pipe error\n");
		close(args->input);
		close(args->output);
		return (1);
	}
	if (!args->str || !args->str2
		|| !args->splited_path || !args->exec_args || !args->exec_args2)
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

	i = 0;
	while (args->exec_args[i])
		free(args->exec_args[i++]);
	free(args->exec_args);
	i = 0;
	while (args->exec_args2[i])
		free(args->exec_args2[i++]);
	free(args->exec_args2);
	i = 0;
	while (args->splited_path[i])
		free(args->splited_path[i++]);
	free(args->splited_path);
}

void	free_dpointer(t_pipex *args)
{
	int	i;

	if (args->str && args->str2)
	{
		free(args->str2);
		free(args->str);
	}
	else if (args->str && !args->str2)
	{
		i = 0;
		while (args->str[i])
			free(args->str[i++]);
		free(args->str);
	}
	else if (args->str2 && !args->str)
	{
		i = 0;
		while (args->str2[i])
			free(args->str2[i++]);
		free(args->str2);
	}
	free_help(args);
}
