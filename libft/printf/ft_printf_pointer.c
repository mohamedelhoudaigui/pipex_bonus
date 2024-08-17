/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 05:11:42 by mel-houd          #+#    #+#             */
/*   Updated: 2024/08/18 00:40:54 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ptr_len(intptr_t num, int *res)
{
	while (num != 0)
	{
		*res += 1;
		num = num / 16;
	}
}

void	ft_put_ptr(intptr_t num)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_normal(num + '0');
		else
			ft_putchar_normal(num - 10 + 'a');
	}
}

void	ft_print_ptr(unsigned long long ptr, int *res)
{
	ft_putstr("0x", res);
	if (ptr == 0)
		ft_putchar('0', res);
	else
	{
		ft_put_ptr(ptr);
		ft_ptr_len(ptr, res);
	}
}
