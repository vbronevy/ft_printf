/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_printf_helper.c								 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: vbronevy <vbronevy@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/03/05 16:27:16 by vbronevy		  #+#	#+#			 */
/*   Updated: 2025/03/07 14:04:19 by vbronevy		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "ft_printf.h"

int	put_nbr(int n)
{
	int		count;
	char	c;

	count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		count += put_nbr(n / 10);
	c = (n % 10) + '0';
	count += put_char(c);
	return (count);
}

int	put_unbr(unsigned int n)
{
	int		count;
	char	c;

	count = 0;
	if (n >= 10)
		count += put_unbr(n / 10);
	c = (n % 10) + '0';
	count += put_char(c);
	return (count);
}

int	put_hexidec_low(unsigned int n)
{
	char			buffer[16];
	int				i;
	int				count;
	unsigned int	remainder;

	i = 0;
	count = 0;
	if (n == 0)
		return (put_char('0'));
	while (n > 0)
	{
		remainder = n % 16;
		if (remainder < 10)
			buffer[i++] = '0' + remainder;
		else
			buffer[i++] = 'a' + (remainder - 10);
		n /= 16;
	}
	while (i > 0)
		count += put_char(buffer[--i]);
	return (count);
}

int	put_hexidec_up(unsigned int n)
{
	char			buffer[16];
	int				i;
	int				count;
	unsigned int	remainder;

	i = 0;
	count = 0;
	if (n == 0)
		return (put_char('0'));
	while (n > 0)
	{
		remainder = n % 16;
		if (remainder < 10)
			buffer[i++] = '0' + remainder;
		else
			buffer[i++] = 'A' + (remainder - 10);
		n /= 16;
	}
	while (i > 0)
		count += put_char(buffer[--i]);
	return (count);
}

int	put_ptr(unsigned long ptr)
{
	char			buf[16];
	int				i;
	int				count;
	unsigned long	r;

	i = 0;
	count = 0;
	if (!ptr)
		return (write(1, "(nil)", 5));
	count += write(1, "0x", 2);
	while (ptr)
	{
		r = ptr % 16;
		if (r < 10)
			buf[i++] = r + '0';
		else
			buf[i++] = (r - 10) + 'a';
		ptr /= 16;
	}
	while (i--)
		count += write(1, &buf[i], 1);
	return (count);
}
