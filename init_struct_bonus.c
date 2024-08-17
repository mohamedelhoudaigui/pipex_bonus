/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:59:24 by mel-houd          #+#    #+#             */
/*   Updated: 2023/12/22 00:36:23 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	init_helper(t_pipex *args, char **av, char **env, int ac)
{
	args->freed = 0;
	args->av = av;
	args->ac = ac;
	args->env = env;
	args->change_av = NULL;
	args->splited_path = split_path(env);
}

int	init_variables(t_pipex *args, char **av, char **env, int ac)
{
	init_helper(args, av, env, ac);
	if (here_doc_parse(av) == 0)
	{
		if (here_doc(args) != 0)
			return (1);
		change_av(args);
		args->av = args->change_av;
		args->ac = args->ac - 1;
		args->output = open(av[ac - 1], O_RDWR | O_CREAT | O_APPEND, 0644);
	}
	else
	{
		args->input = open(av[1], O_RDWR, 0644);
		args->output = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	}
	args->str = all_commands(args);
	init_pipes(args);
	init_args(args);
	init_pid(args);
	if (error_handler(args) == 1)
		return (1);
	return (0);
}
