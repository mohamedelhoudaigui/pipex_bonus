/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 02:49:12 by mel-houd          #+#    #+#             */
/*   Updated: 2023/12/22 00:36:19 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	check_only_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' || (str[i] >= 9 && str[i] <= 13))
			return (0);
		i++;
	}
	return (1);
}

int	mini_parser(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (ft_strncmp(av[1], "here_doc", ft_strlen(av[1])) == 0
			&& ft_strlen(av[1]) == 8)
		{
			if (i == 2)
				if (av[2][0] == '\0')
					i++;
		}
		else if (av[i][0] == '\0' || check_only_spaces(av[i]) == 1)
		{
			ft_printf("invalid input\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	here_doc_parse(char **av)
{
	int		i;

	i = 1;
	if (ft_strncmp(av[1], "here_doc", ft_strlen(av[1])) == 0
		&& ft_strlen(av[1]) == 8)
	{
		i += 2;
		while (av[i])
		{
			if (av[i][0] == '\0' || check_only_spaces(av[i]) == 1)
			{
				ft_printf("invalid input\n");
				return (1);
			}
			i++;
		}
		return (0);
	}
	return (2);
}

void	free_all_command(char ***all_command)
{
	int	i;
	int	j;

	i = 0;
	while (all_command[i])
	{
		j = 0;
		while (all_command[i] && all_command[i][j])
			free(all_command[i][j++]);
		free(all_command[i]);
		i++;
	}
	free(all_command);
}

char	***all_commands(t_pipex *args)
{
	int		i;
	char	***all_command;

	all_command = (char ***)malloc(sizeof(char **) * args->ac - 3);
	if (!all_command)
		return (NULL);
	i = 0;
	while (i < args->ac - 3)
	{
		all_command[i] = check_command(args->av[i + 2], args->splited_path);
		if (!all_command[i])
		{
			free_all_command(all_command);
			return (NULL);
		}
		i++;
	}
	all_command[i] = NULL;
	return (all_command);
}
