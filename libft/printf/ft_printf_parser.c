/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:14:49 by mel-houd          #+#    #+#             */
/*   Updated: 2023/12/21 19:28:14 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parsing(va_list *args, const char *s)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
			regular_cases(s, &i, &res, *args);
		else
		{
			ft_putchar(s[i], &res);
			i += 1;
		}
	}
	return (res);
}

void	regular_cases(const char *s, int *i, int *res, va_list args)
{
	if (s[*i + 1] == 'c')
		ft_putchar((char)va_arg(args, int), res);
	else if (s[*i + 1] == 's')
		ft_putstr(va_arg(args, char *), res);
	else if (s[*i + 1] == 'd' || s[*i + 1] == 'i')
		ft_putnbr(va_arg(args, int), res);
	else if (s[*i + 1] == 'u')
		ft_putnbr_unsigned(va_arg(args, unsigned int), res);
	else if (s[*i + 1] == 'p')
		ft_print_ptr(va_arg(args, uintptr_t), res);
	else if (s[*i + 1] == 'x')
		ft_print_hex(va_arg(args, int), 'x', res);
	else if (s[*i + 1] == 'X')
		ft_print_hex(va_arg(args, int), 'X', res);
	else if (s[*i + 1] == '%')
		ft_putchar('%', res);
	*i += 2;
}
