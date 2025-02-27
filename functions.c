/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronevy <vbronevy@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-25 13:52:43 by vbronevy          #+#    #+#             */
/*   Updated: 2025-02-25 13:52:43 by vbronevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "libft/libft.h"
#include "header.h"

int	count_args(const char *str)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == '%')
		{
			sum++;
			i = i + 2;
			continue ;
		}
		else if (str[i] == '%' && str[i + 1] != '%')
			sum++;
		i++;
	}
	return (sum);
}

char	get_specifier(const char *str, int start)
{
	int		i;
	int		count;
	char	specifier;

	specifier = 's';
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
				continue ;
			}
			if (str[i + 1] == 'i')
				specifier = 'i';
			else if (str[i + 1] == 'c')
				specifier = 'c';
			else if (str[i + 1] == '%')
				specifier = '%';
			// else
			// 	break;
			break ;
		}
		i++;
	}
	return (specifier);
}

char	*put_string(const char *format, char *str)
{
	int		i;
	char	*copy;
	char	*result;
	char	*start;

	result = NULL;
	i = 0;
	while (format[i + 1] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '%')
		{
			start = ft_substr(format, 0, i);
			copy = ft_strjoin(start, str);
			result = ft_strjoin(copy, format + i + 2);
			free(copy);
			free(start);
			break ;
		}
		i++;
	}
	return (result);
}

char	*put_number(const char *format, int num)
{
	int		i;
	char	*copy;
	char	*result;
	char	*start;
	char	*arg;

	result = NULL;
	i = 0;
	arg = ft_itoa(num);
	while (format[i + 1] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '%')
		{
			start = ft_substr(format, 0, i);
			copy = ft_strjoin(start, arg);
			result = ft_strjoin(copy, format + i + 2);
			free(arg);
			free(copy);
			free(start);
			break ;
		}
		i++;
	}
	return (result);
}

char	*put_char(const char *format, int c)
{
	int		i;
	char	*result;
	char	*start;

	result = NULL;
	i = 0;
	while (format[i + 1] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '%')
		{
			start = ft_substr(format, 0, i + 1);
			start[i] = (char)c;
			result = ft_strjoin(start, format + i + 2);
			free(start);
			break ;
		}
		i++;
	}
	return (result);
}
char	*put_pt_sn(const char *format)
{
	int		i;
	char	*result;
	char	*start;

	result = NULL;
	i = 0;
	while (format[i + 1] != '\0')
	{
		if (format[i] == '%' && format[i + 1] == '%')
		{
			start = ft_substr(format, 0, i + 1);
			start[i] = '%';
			result = ft_strjoin(start, format + i + 2);
			free(start);
			break ;
		}
		i++;
	}
	return (result);
}

void	print_result(const char *result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		write(1, &result[i], 1);
		i++;
	}
}

char	*get_result(char *result, char *holder, char specifier, va_list args)
{
	if (specifier == 's')
		result = put_string(holder, va_arg(args, char *));
	else if (specifier == 'i')
		result = put_number(holder, va_arg(args, int));
	else if (specifier == 'c')
		result = put_char(holder, va_arg(args, int));
	else if (specifier == '%')
		result = put_pt_sn(holder);
	return (result);
}
