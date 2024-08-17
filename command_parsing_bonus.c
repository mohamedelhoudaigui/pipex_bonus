/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_parsing_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 21:21:22 by mel-houd          #+#    #+#             */
/*   Updated: 2023/12/22 00:36:41 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
