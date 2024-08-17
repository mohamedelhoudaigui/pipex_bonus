/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_ctl_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:39:58 by mel-houd          #+#    #+#             */
/*   Updated: 2023/12/22 00:36:36 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	close_for_init(t_pipex *args)
{
	int	j;

	close(args->fd[0][0]);
	j = 1;
	if (args->fd[j] != NULL)
	{
		while (j < args->ac - 4)
		{
			close(args->fd[j][0]);
			close(args->fd[j][1]);
			j++;
		}
	}
}

void	close_for_last(t_pipex *args, int i)
{
	int	j;

	close(args->fd[i - 1][1]);
	j = 0;
	while (j < args->ac - 5)
	{
		close(args->fd[j][0]);
		close(args->fd[j][1]);
		j++;
	}
}

void	close_for_middle(t_pipex *args, int i)
{
	int	j;

	j = 0;
	while (j < args->ac - 4)
	{
		close(args->fd[i - 1][1]);
		close(args->fd[i][0]);
		if (j < i - 1 || j > i)
		{
			close(args->fd[j][0]);
			close(args->fd[j][1]);
		}
		j++;
	}
}

void	pipe_ctl(t_pipex *args, int i)
{
	if (i == 0)
		close_for_init(args);
	else if (i == args->ac - 4)
		close_for_last(args, i);
	else
		close_for_middle(args, i);
}
