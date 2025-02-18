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

int	count_args(const char* str)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (str[i])
	{
		if(str[i] == '%')
		{
			sum++;
		}
		i++;
	}
	return(sum);
}	

char	get_specifier(const char* str, int start)
{
	int		i;
	int		count;
	char	specifier;
	
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			count++;
			if (count <= start && start > 0)
			{
				i++;
				continue;
			}
			if (str[i + 1] == 's')
				specifier = 's';
			else if (str[i + 1] == 'i')
				specifier = 'i';
			break;
		}
		i++;
	}
	return (specifier);
}

char*	put_string(const char* format, char* str)
{
	int		i;
	char*	copy;
	char*	result;
	char*	start;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			start = ft_substr(format, 0, i);
			copy = ft_strjoin(start, str);
			result = ft_strjoin(copy, format + i + 2);
			free(copy);
			free(start);
			break;
		}
		i++;
	}
	return (result);
}
char	*put_number(const char* format, int num)
{
	int		i;
	char*	copy;
	char*	result;
	char*	start;
	char*	arg;

	i = 0;
	arg = ft_itoa(num);
	while (format[i])
	{
		if (format[i] == '%')
		{
			start = ft_substr(format, 0, i);
			copy = ft_strjoin(start, arg);
			result = ft_strjoin(copy, format + i + 2);
			free(arg);
			free(copy);
			free(start);
			break;
		}
		i++;
	}
	return (result);
}

void print_result(const char* result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		write(1, &result[i], 1);
		i++;
	}
}

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
