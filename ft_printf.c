/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronevy <vbronevy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:03:51 by vbronevy          #+#    #+#             */
/*   Updated: 2025/02/05 01:50:33 by vbronevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "libft/libft.h"
#include "header.h"

void simple_printf(const char* format, ...)
{
	va_list	args;
	int		i;
	int		count;
	char	f_specifier;
	char	*result;
	char 	*holder;
	
	i = 0;
	holder = (char*)format;
	count = count_args(format);
	va_start(args, format);
	while (i < count)
	{
		f_specifier = get_specifier(format, i);
		if (f_specifier == 's')
		{
			result = put_string(holder, va_arg(args, char*));
		}
		else if(f_specifier == 'i')
		{
			result = put_number(holder, va_arg(args, int));
		}
		if(i > 0 && i - 1 < count)
		{
			free(holder);
		}
		holder = result;
		result = NULL;
		free(result);
		i++;
	}
	print_result(holder);
	free(holder);
	va_end(args);
}

int main()
{
	simple_printf("String: %s, my friends %s", "25", "24");

    printf("Test Case 1: Simple Integer\n");
    simple_printf("The number is: %i\n", 42);

    printf("\nTest Case 2: Simple String\n");
    simple_printf("Hello, %s!\n", "world");

    printf("\nTest Case 3: Multiple Integers\n");
    simple_printf("Numbers: %i, %i, and %i\n", 1, 2, 3);

    printf("\nTest Case 4: Multiple Strings\n");
    simple_printf("%s %s %s\n", "This", "is", "a test");

    printf("\nTest Case 5: Mixed Strings and Integers\n");
    simple_printf("%s has %i apples and %i oranges.\n", "Alice", 5, 3);

    printf("\nTest Case 6: Empty String\n");
    simple_printf("This is an empty string: '%s'\n", "");

    printf("\nTest Case 7: Edge Case - Integer Limits\n");
    simple_printf("Min: %i, Max: %i\n", -2147483648, 2147483647);

    printf("\nTest Case 8: Edge Case - Large String\n");
    simple_printf("%s\n", "Lorem ipsum dolor sit amet, consectetur adipiscing elit.");

    // printf("\nTest Case 9: No Specifiers\n");
    // simple_printf("This is a test with no specifiers.\n");

    printf("\nTest Case 10: Consecutive Specifiers\n");
    simple_printf("%i%i%i%i\n", 1, 2, 3, 4);
}
