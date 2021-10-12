/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarie-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 13:59:29 by amarie-c          #+#    #+#             */
/*   Updated: 2021/10/01 14:01:02 by amarie-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexa_maj(long int n)
{
	int	rest;

	if (n < 0)
		ft_puthexa_maj(ft_puthexa_neg(-n));
	else if (n / 16 == 0)
	{
		if (n > 9)
			ft_print_char('A' + (n - 10));
		else
			ft_print_char(n + '0');
	}
	else
	{
		ft_puthexa_maj(n / 16);
		rest = n % 16;
		if (rest < 0)
			rest = -rest;
		if (rest > 9)
			ft_print_char('A' + (rest - 10));
		else
			ft_print_char(rest + '0');
	}
}

void	unsign_hex(unsigned long n)
{
	unsigned long	rest;

	if (n / 16 == 0)
	{
		if (n > 9)
			ft_print_char('a' + (n - 10));
		else
			ft_print_char(n + '0');
	}
	else
	{
		unsign_hex(n / 16);
		rest = n % 16;
		if (rest > 9)
			ft_print_char('a' + (rest - 10));
		else
			ft_print_char(rest + '0');
	}
}

void	ft_printpoint(void *point)
{
	ft_print_char('0');
	ft_print_char('x');
	unsign_hex((unsigned long)point);
}

int	ft_strlen(const char *text)
{
	int	i;
	int	count;

	if (!text || !(*text))
		return (0);
	i = 0;
	count = 0;
	while (text[i++])
	{
		if (text[i] != '"' && ((i == 0 ) || text[i + 1] == '\0'))
			count++;
	}
	return (count);
}

long int	ft_puthexa_neg(long int n)
{
	long int	conversion;

	conversion = 4294967295 - n + 1;
	return (conversion);
}
