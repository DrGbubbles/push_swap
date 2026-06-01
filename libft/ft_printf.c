/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaher <ktaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:56:05 by ktaher            #+#    #+#             */
/*   Updated: 2026/06/01 17:51:10 by ktaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ptr_handler(uintptr_t value, int *count)
{
	if (!value)
		*count += ft_putstr("(nil)");
	else
	{
		*count += ft_putstr("0x");
		*count += ft_putnbr_base(value, "0123456789abcdef");
	}
}

static void	hex_handler(unsigned int value, char c, int *count)
{
	if (c == 'x')
		*count += ft_putnbr_base(value, "0123456789abcdef");
	else if (c == 'X')
		*count += ft_putnbr_base(value, "0123456789ABCDEF");
	else if (c == 'u')
		*count += ft_putnbr_base(value, "0123456789");
}

static void	txt_handler(va_list args, char c, int *count)
{
	char	*str;

	if (c == 's')
	{
		str = va_arg(args, char *);
		if (!str)
			*count += ft_putstr("(null)");
		else
			*count += ft_putstr(str);
	}
	else if (c == 'c')
		*count += ft_putchar(va_arg(args, int));
	else if (c == '%')
		*count += ft_putchar('%');
}

static void	num_handler(va_list args, char c, int *count)
{
	if (c == 'd' || c == 'i')
		*count += ft_putnbr(va_arg(args, int));
	else if (c == 'x' || c == 'X' || c == 'u')
		hex_handler(va_arg(args, unsigned int), c, count);
	else if (c == 'p')
		ptr_handler(va_arg(args, uintptr_t), count);
	else if (c == 'f' || c == '.')
		float_handler(va_arg(args, uintptr_t), count);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;

	count = 0;
	if (!s)
		return (-1);
	va_start(args, s);
	while (*s)
	{
		if (*s == '%' && *(++s))
		{
			if (*s == 's' || *s == 'c' || *s == '%')
				txt_handler(args, *s, &count);
			else
				num_handler(args, *s, &count);
		}
		else
			count += ft_putchar(*s);
		if (*s)
			s++;
	}
	va_end(args);
	return (count);
}
