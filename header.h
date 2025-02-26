/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronevy <vbronevy@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-25 13:53:06 by vbronevy          #+#    #+#             */
/*   Updated: 2025-02-25 13:53:06 by vbronevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include "libft/libft.h"

int		count_args(const char *str);
char	get_specifier(const char *str, int start);
char	*put_string(const char *format, char *str);
char	*put_number(const char *format, int num);
void	print_result(const char *result);
void	simple_printf(const char *format, ...);
char	*get_result(char *result, char *holder, char specifier, va_list args);

#endif