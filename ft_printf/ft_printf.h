/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:37:57 by jsauvain          #+#    #+#             */
/*   Updated: 2022/05/09 16:42:44 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stddef.h>

int	ft_printf(const char *format, ...);
int	ft_formatting(const char *str, va_list arg);
int	ft_format(const char *format, va_list arg);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int n, int i);
int	to_find(const char *format, char c, va_list arg);
int	low_hexa(unsigned int n, int i);
int	up_hexa(unsigned int n, int i);
int	put_hexa_ptr(unsigned long long ptr, int i);

#endif
