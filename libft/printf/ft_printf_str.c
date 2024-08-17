/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:14:07 by mel-houd          #+#    #+#             */
/*   Updated: 2023/11/17 10:07:11 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *res)
{
	write(1, &c, 1);
	*res += 1;
}

void	ft_putchar_normal(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s, int *res)
{
	int	i;

	if (s == NULL)
	{
		ft_putstr("(null)", res);
		return ;
	}
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i++], res);
	}
}
