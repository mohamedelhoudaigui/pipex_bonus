/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 03:31:06 by mel-houd          #+#    #+#             */
/*   Updated: 2023/12/21 23:31:42 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	init_variables(t_pipex *args, char **av, char **env)
{
	args->splited_path = split_path(env);
	args->exec_args = (char **)ft_calloc(3, sizeof(char *));
	args->exec_args2 = (char **)ft_calloc(3, sizeof(char *));
	args->str = check_command(av[2], args->splited_path);
	args->str2 = check_command(av[3], args->splited_path);
	args->input = open(av[1], O_RDWR | O_CREAT, 0777);
	args->output = open(av[4], O_RDWR | O_TRUNC | O_CREAT, 0777);
	if (error_handler(args) == 1)
		return (1);
	args->exec_args[0] = args->str[0];
	args->exec_args2[0] = args->str2[0];
	if (args->str[1] != NULL)
		args->exec_args[1] = args->str[1];
	if (args->str2[1] != NULL)
		args->exec_args2[1] = args->str2[1];
	return (0);
}
