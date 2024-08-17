/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 21:12:38 by mel-houd          #+#    #+#             */
/*   Updated: 2023/12/21 12:21:48 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(const char *s, ...);
int		ft_parsing(va_list *args, const char *s);
void	regular_cases(const char *s, int *i, int *res, va_list args);
void	ft_putchar(char c, int *res);
void	ft_putchar_normal(char c);
void	ft_putstr(char *s, int *res);
void	ft_putnbr(int n, int *res);
void	ft_putnbr_unsigned(unsigned int n, int *res);
void	ft_hex_len(unsigned	int num, int *res);
void	ft_put_hex(unsigned int num, const char format);
void	ft_print_hex(unsigned int num, const char format, int *res);
void	ft_ptr_len(intptr_t num, int *res);
void	ft_put_ptr(intptr_t num);
void	ft_print_ptr(unsigned long long ptr, int *res);

#endif
