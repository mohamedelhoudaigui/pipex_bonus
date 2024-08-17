/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_handler_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 03:31:06 by mel-houd          #+#    #+#             */
/*   Updated: 2023/12/22 00:36:25 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	init_args(t_pipex *args)
{
	int	i;

	if (args->str == NULL)
	{
		args->exec_args = NULL;
		return ;
	}
	args->exec_args = (char ***)ft_calloc(sizeof(char **), args->ac - 2);
	if (!args->exec_args)
		return ;
	i = 0;
	while (args->str[i])
	{
		args->exec_args[i] = args->str[i];
		i++;
	}
	args->exec_args[i] = NULL;
}

void	init_pipes(t_pipex *args)
{
	int	i;

	i = 0;
	args->fd = (int **)ft_calloc(sizeof(int *), args->ac - 3);
	if (!args->fd)
		return ;
	while (i < args->ac - 4)
	{
		args->fd[i] = (int *)ft_calloc(sizeof(int), 2);
		pipe(args->fd[i]);
		i++;
	}
}

void	init_pid(t_pipex *args)
{
	args->pid = (pid_t *)malloc(sizeof(int) * args->ac - 3);
	if (!args->pid)
		return ;
}

void	change_av(t_pipex *args)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	args->change_av = (char **)ft_calloc(sizeof(char *), args->ac - 1);
	if (!args->change_av)
		return ;
	while (args->av[i])
	{
		if (i == 2)
			i++;
		args->change_av[j] = args->av[i];
		j++;
		i++;
	}
}
