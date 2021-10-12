/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarie-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 13:54:43 by amarie-c          #+#    #+#             */
/*   Updated: 2021/10/01 13:54:45 by amarie-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(char carl)
{
	write(1, &carl, sizeof(char));
	g_count_char ++;
}

void	ft_print_chain(char *chain)
{
	int	i;

	if (!chain)
		chain = "(null)" ;
	i = 0;
	while (chain[i] != '\0')
	{
		ft_print_char(chain[i++]);
	}
}

void	ft_putnbr(int n)
{
	int	rest;

	if (n / 10 == 0)
	{
		if (n < 0)
		{
			ft_print_char('-');
			n = -n;
		}
		ft_print_char(n + '0');
	}
	else
	{
		ft_putnbr(n / 10);
		rest = n % 10;
		if (rest < 0)
			rest = -rest;
		ft_print_char('0' + rest);
	}
}

void	ft_un_putnbr(unsigned int n)
{
	unsigned int	rest;

	if (n / 10 == 0)
		ft_print_char(n + '0');
	else
	{
		ft_putnbr(n / 10);
		rest = n % 10;
		ft_print_char('0' + rest);
	}
}

void	ft_puthexa(long int n)
{
	int	rest;

	if (n < 0)
		ft_puthexa(ft_puthexa_neg(-n));
	else if (n / 16 == 0)
	{
		if (n > 9)
			ft_print_char('a' + (n - 10));
		else
			ft_print_char(n + '0');
	}
	else
	{
		ft_puthexa(n / 16);
		rest = n % 16;
		if (rest < 0)
			rest = -rest;
		if (rest > 9)
			ft_print_char('a' + (rest - 10));
		else
			ft_print_char(rest + '0');
	}
}
