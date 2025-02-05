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

// char* concat_strings(int count, ...)
// {
// 	va_list args;
// 	char*	str;
// 	int 	i;
	
// 	va_start(args, count);
// 	i = 0;
// 	str = va_arg(args, char*);
// 	while(i < count - 1)
// 	{
// 		str = ft_strjoin(str, va_arg(args, char*));
// 		i++;
// 	}
// 	va_end(args);
	
// 	return(str);
// }

// int product_of(int count, ...)
// {
// 	va_list	args;
// 	int		i;
// 	int		sum;
	
// 	va_start(args, count);
// 	i = 0;
// 	sum = 1;
// 	while(i < count)
// 	{
// 		sum = sum * va_arg(args, int);
// 		i++;
// 	}
// 	va_end(args);
// 	return(sum);
// }

// void print_mixed(int count, ...)
// {
// 	va_list args;
// 	int		i;
// 	int		type;
	
// 	va_start(args, count);
// 	i = 0;
// 	while(i < count)
// 	{
// 		type = va_arg(args, int);
// 		if(type == 'i')
// 		{
// 			printf("Integer: %d\n", va_arg(args, int));
// 		}
// 		if(type == 'c')
// 		{
// 			char c = va_arg(args, int);
// 			printf("Character: %c\n", c);
// 		}
// 		if(type == 'f')
// 		{
// 			printf("Float: %f\n", va_arg(args, double));
// 		}
// 		i++;
// 	}
// 	va_end(args);
// }

// void reverse_print(int count, ...)
// {
// 	va_list args;
// 	int		i;
// 	int		arr[count];
	
// 	va_start(args,count);
// 	i = 0;
// 	while(i < count)
// 	{
// 		arr[i] = va_arg(args, int);
// 		i++;
// 	}
// 	while(i > 0)
// 	{
// 		i--;
// 		printf("%d ", arr[i]);
// 	}
// 	printf("\n");
// 	va_end(args);
// }

int	count_args(const char* str)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while(str[i])
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
	while(str[i])
	{
		if(str[i] == '%')
		{
			count++;
			if(count <= start && start > 0)
			{
				i++;
				continue;
			}
			if(str[i + 1] == 's')
				specifier = 's';
			else if(str[i + 1] == 'i')
				specifier = 'i';
			break;
		}
		i++;
	}
	return(specifier);
}

char*	get_result(const char* format, char* str)
{
	int		i;
	char*	copy;
	char*	result;

	i = 0;
	result = malloc(ft_strlen(format) + ft_strlen(str) + 1);
	copy = (char*)format;
	while(format[i])
	{
		result[i] = format[i];
		if(format[i] == '%')
		{
			result[i] = '\0';
			result = ft_strjoin(result, str);
			result = ft_strjoin(result, format + i + 2);
			break;
		}
		i++;
	}
	return(result);
}
void print_result(const char* result)
{
	int	i;

	i = 0;
	while(result[i])
	{
		write(1, &result[i], 1);
		i++;
	}
}

void simple_printf(const char* format, ...)
{
	va_list args;
	int		i;
	int		count;
	char	f_specifier;
	char	*result;
	
	i = 0;
	result = (char*)format;
	count = count_args(format);
	va_start(args, format);
	while(i < count)
	{
		f_specifier = get_specifier(format, i);
		if(f_specifier == 's')
		{
			result = get_result(result, va_arg(args, char*));
		}
		i++;
	}
	print_result(result);
	free(result);
	va_end(args);
}

int main()
{
	simple_printf("String: %s", "Goodbye");
	// char *str = "Hello, world!";
	// str = str + 7;
	// printf("%s\n", str);
}
