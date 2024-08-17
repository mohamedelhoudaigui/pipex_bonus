/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 02:49:12 by mel-houd          #+#    #+#             */
/*   Updated: 2023/12/22 00:56:08 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

int	mini_parser(char **av, int ac)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (i == 1)
		{
			if (av[i][0] == '\0' || av[ac - 1][0] == '\0')
			{
				ft_printf("invalid files\n");
				return (1);
			}
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

char	**check_command_help(char **com, char **path_splited, int key)
{
	int		i;
	char	*str;

	i = 0;
	while (path_splited[i])
	{
		str = ft_strjoin(path_splited[i], com[0]);
		if (access(str, X_OK) == 0)
		{
			free(com[0]);
			com[0] = str;
			key = 1;
			break ;
		}
		i++;
		free(str);
	}
	if (key == 1)
		return (com);
	i = 0;
	while (com[i])
		free(com[i++]);
	free(com);
	return (NULL);
}

char	**check_command(char *command, char **path_splited)
{
	char	**com;
	char	*padded;
	int		key;

	com = ft_split(command, " \t");
	if (com[0][0] == '/' || com[0][0] == '.')
	{
		if (access(com[0], X_OK) == 0)
			return (com);
		else
			return (NULL);
	}
	key = 0;
	if (path_splited == NULL)
		return (NULL);
	padded = ft_strjoin("/", com[0]);
	free(com[0]);
	com[0] = padded;
	return (check_command_help(com, path_splited, key));
}
