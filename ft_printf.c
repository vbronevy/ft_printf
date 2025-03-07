/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_printf.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: vbronevy <vbronevy@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/03/05 16:19:33 by vbronevy		  #+#	#+#			 */
/*   Updated: 2025/03/07 13:58:35 by vbronevy		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "ft_printf.h"

int	put_str(char *str)
{
	int	count;

	count = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*str)
	{
		write(1, str, 1);
		str++;
		count++;
	}
	return (count);
}

int	put_char(int c)
{
	write(1, &c, 1);
	return (1);
}

static int	put_format(va_list args, char c)
{
	if (c == 's')
		return (put_str(va_arg(args, char *)));
	else if (c == 'c')
		return (put_char(va_arg(args, int)));
	else if (c == 'd' || c == 'i')
		return (put_nbr(va_arg(args, int)));
	else if (c == 'u')
		return (put_unbr(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (put_hexidec_low(va_arg(args, unsigned int)));
	else if (c == 'X')
		return (put_hexidec_up(va_arg(args, unsigned int)));
	else if (c == '%')
		return (put_char('%'));
	else if (c == 'p')
		return ((put_ptr((unsigned long)va_arg(args, void *))));
	else
		return (-1);
}

static int	handle_char(const char *f, va_list a, int *i)
{
	int	printed;

	if (f[*i] == '%' && f[*i + 1])
	{
		(*i)++;
		printed = put_format(a, f[*i]);
		if (printed != -1)
		{
			(*i)++;
			return (printed);
		}
	}
	write(1, &f[*i], 1);
	(*i)++;
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		total;

	va_start(args, format);
	i = 0;
	total = 0;
	while (format && format[i])
		total += handle_char(format, args, &i);
	va_end(args);
	return (total);
}
