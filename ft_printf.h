/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronevy <vbronevy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:27:35 by vbronevy          #+#    #+#             */
/*   Updated: 2025/03/07 14:42:55 by vbronevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <unistd.h>

int		put_str(char *str);
int		put_char(int c);
int		put_nbr(int n);
int		put_unbr(unsigned int n);
int		put_hexidec_low(unsigned int n);
int		put_hexidec_up(unsigned int n);
int		put_ptr(unsigned long ptr);
int		ft_printf(const char *format, ...);

#endif