/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 08:30:18 by mel-houd          #+#    #+#             */
/*   Updated: 2023/12/22 00:36:10 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	f(void)
{
	system("leaks pipex");
}

void	process_job(t_pipex *args, int i)
{
	if (i == 0)
		first_proc(args, i);
	else if (i == args->ac - 4)
		last_proc(args, i);
	else
		middle_proc(args, i);
}

void	main_helper(t_pipex *args)
{
	int	i;

	i = 0;
	while (i < args->ac - 4)
	{
		close(args->fd[i][0]);
		close(args->fd[i][1]);
		i++;
	}
	close(args->input);
	close(args->output);
}

t_pipex	*pipex(int ac, char **av, char **env)
{
	t_pipex	*args;
	int		i;

	if (mini_parser(av) == 1)
		return (NULL);
	args = (t_pipex *)malloc(sizeof(t_pipex));
	if (!args)
		return (NULL);
	if (init_variables(args, av, env, ac) == 1)
		return (args);
	i = 0;
	while (i < args->ac - 3)
	{
		args->pid[i] = fork();
		if (check_pid(args->pid[i]) == 1)
			return (args);
		if (args->pid[i] == 0)
			process_job(args, i);
		i++;
	}
	main_helper(args);
	i = 0;
	while (i < args->ac - 4)
		waitpid(args->pid[i++], NULL, 0);
	return (args);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	*args;

	atexit(f);
	if (ac >= 5)
	{
		args = pipex(ac, av, env);
		if (args == NULL)
			return (1);
		else
		{
			if (args->freed == 0)
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
