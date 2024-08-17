/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 05:11:45 by mel-houd          #+#    #+#             */
/*   Updated: 2023/11/17 10:12:03 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hex_len(unsigned	int num, int *res)
{
	while (num != 0)
	{
		*res += 1;
		num = num / 16;
	}
}

void	ft_put_hex(unsigned int num, const char format)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, format);
		ft_put_hex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_putchar_normal(num + '0');
		else
		{
			if (format == 'x')
				ft_putchar_normal(num - 10 + 'a');
			if (format == 'X')
				ft_putchar_normal(num - 10 + 'A');
		}
	}
}

void	ft_print_hex(unsigned int num, const char format, int *res)
{
	if (num == 0)
		return (ft_putchar('0', res));
	else
		ft_put_hex(num, format);
	ft_hex_len(num, res);
}
