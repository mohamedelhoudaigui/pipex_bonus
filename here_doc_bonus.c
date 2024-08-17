/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 02:05:53 by mel-houd          #+#    #+#             */
/*   Updated: 2023/12/22 00:36:28 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	here_doc(t_pipex *args)
{
	char	*str;
	int		here_doc[2];
	int		len;

	if (args->av[2][0] == '\0')
		args->av[2][0] = 10;
	len = ft_strlen(args->av[2]);
	if (pipe(here_doc) < 0)
		return (perror("pipe"), -1);
	ft_printf("heredoc> ");
	str = get_next_line(0);
	while (str != NULL && ((str[0] == 10 && args->av[2][0] != 10)
		|| ft_strncmp(str, args->av[2], ft_strlen(str) - 1) != 0))
	{
		ft_printf("heredoc> ");
		write(here_doc[1], str, ft_strlen(str));
		free(str);
		str = get_next_line(0);
		if (str != NULL && str[0] == 10 && args->av[2][0] == '\0')
			break ;
	}
	free(str);
	close(here_doc[1]);
	args->input = here_doc[0];
	return (0);
}
