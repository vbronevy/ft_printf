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
	char 	holder[200];
	
	i = 0;
	strcpy(holder, format);
	result = (char*)format;
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
		strcpy(holder, result);
		free(result);
		result = NULL;
		i++;
	}
	print_result(holder);
	// free(holder);
	va_end(args);
}

int main()
{
	simple_printf("String: %s, my friends %s", "25", "dfa");

	printf("Test Case 1: Simple Integer\n");
    simple_printf("The number is: %i\n", 42);
	printf("\nTest Case 2: Simple String\n");
    simple_printf("Hello, %s!\n", "world");
	printf("\nTest Case 3: Multiple Integers\n");
    simple_printf("Numbers: %i, %i, and %i\n", 1, 2, 3);
}
