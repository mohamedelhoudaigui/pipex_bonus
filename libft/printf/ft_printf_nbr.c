/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:13:28 by mel-houd          #+#    #+#             */
/*   Updated: 2023/12/21 12:28:14 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_unsigned(unsigned int n, int *res)
{
	if (n > 9)
		ft_putnbr_unsigned(n / 10, res);
	ft_putchar((n % 10) + '0', res);
}

void	ft_putnbr(int n, int *res)
{
	if (n == -2147483648)
	{
		ft_putchar('-', res);
		ft_putchar('2', res);
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar('-', res);
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10, res);
	ft_putchar((n % 10) + '0', res);
}
