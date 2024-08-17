/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 08:25:37 by mel-houd          #+#    #+#             */
/*   Updated: 2023/12/22 00:44:20 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**split_path(char **env)
{
	int		i;
	char	*path;
	char	**splited_path;

	i = 0;
	if (env == NULL || env[i] == NULL)
		return (NULL);
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 6))
			break ;
		i++;
	}
	path = ft_strtrim(env[i], "PATH=");
	if (!path)
		return (NULL);
	splited_path = ft_split(path, ":");
	if (!splited_path)
	{
		free(path);
		return (NULL);
	}
	free(path);
	return (splited_path);
}
