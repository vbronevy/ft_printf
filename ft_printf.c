/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronevy <vbronevy@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-28 16:03:51 by vbronevy          #+#    #+#             */
/*   Updated: 2025-01-28 16:03:51 by vbronevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

// int max_of(int count, ...)
// {
// 	va_list args;
// 	int		num;
// 	int		n;
// 	int		i;

// 	va_start(args, count);
// 	num = va_arg(args, int);
// 	i = 0;
// 	while(i < count)
// 	{
// 		n = va_arg(args, int);
// 		if (num < n)
// 		{
// 			num = n;
// 		}
// 		i++;
// 	}

// 	va_end(args);

// 	return (num);
// }

// float average_of(int count, ...)
// {
// 	va_list args;
// 	int		i;
// 	float	num;

// 	va_start(args, count);
// 	i = 0;
// 	num = 0;
// 	while(i < count)
// 	{
// 		num = num + va_arg(args, double);
// 		i++;
// 	}
// 	num = num / count;
// 	va_end(args);

// 	return (num);
// }


int main()
{
	printf("Average of 3.5, 4.5, 2.0: %.2f\n", average_of(3, 3.5, 4.5, 2.0));
}
