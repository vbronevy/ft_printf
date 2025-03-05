/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronevy <vbronevy@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-05 16:19:33 by vbronevy          #+#    #+#             */
/*   Updated: 2025-03-05 16:19:33 by vbronevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "libft/libft.h"
#include "header.h"

void	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;

	va_start(args, format);
	i = 0;
	while(format[i])
	{
		if(format[i] == '%')
		{
			if(format[i + 1] == 's')
			{
				put_str(va_arg(args, char*));
				i = i + 2;
				continue;
			}
			else if(format[i + 1] == 'i')
			{
				put_nbr(va_arg(args, int));
				i = i + 2;
				continue;
			}
			else if(format[i + 1] == 'c')
			{
				put_char(va_arg(args, int));
				i = i + 2;
				continue;
			}
		}
		if(format[i] != '\0')
			write(1, &format[i], 1);
		i++;
	}
	va_end(args);
}

int main(void)
{
	ft_printf("Hello, %s", "world\n");

    printf("\nTest Case 1: Simple Integer\n");
	ft_printf("The number is: %i\n", 42);

    printf("\nTest Case 2: Simple String\n");
	ft_printf("Hello, %s!\n", "world");

    printf("\nTest Case 3: Multiple Integers\n");
	ft_printf("Numbers: %i, %i, and %i\n", 1, 2, 3);

    printf("\nTest Case 4: Multiple Strings\n");
	ft_printf("%s %c %s\n", "This", 'c', "a test");

    printf("\nTest Case 5: Mixed Strings and Integers\n");
	ft_printf("%s has %i apples and %c oranges.\n", "Alice", 5, '3');

    printf("\nTest Case 6: Empty String\n");
	ft_printf("This is an empty string: '%s'\n", "");

    printf("\nTest Case 7: Edge Case - Integer Limits\n");
	ft_printf("Min: %i, Max: %i\n", -2147483648, 2147483647);

    printf("\nTest Case 8: Edge Case - Large String\n");
	ft_printf("%s\n", "Lorem ipsum dolor sit amet, consectetur adipiscing elit.");

    printf("\nTest Case 9: No Specifiers\n");
	ft_printf("This is a test with no specifiers.\n");

    printf("\nTest Case 10: Consecutive Specifiers\n");
	ft_printf("%i%i%i%i\n", 1, 2, 3, 4);
	return (0);
}