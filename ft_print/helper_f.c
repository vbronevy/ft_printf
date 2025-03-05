/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbronevy <vbronevy@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-05 16:27:16 by vbronevy          #+#    #+#             */
/*   Updated: 2025-03-05 16:27:16 by vbronevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "libft/libft.h"


void	put_str(char* str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	put_nbr(int n)
{
	int		i;
	char*	nbr;

	i = 0;
	nbr = ft_itoa(n);
	while(nbr[i])
	{
		write(1, &nbr[i], 1);
		i++;
	}
}

void	put_char(int c)
{
	unsigned char ch;

	ch = c;
	write(1, &ch, 1);
}