/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarie-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:36:21 by amarie-c          #+#    #+#             */
/*   Updated: 2021/10/01 13:55:45 by amarie-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_switch(char c, va_list args)
{
	if (c == 'c')
		ft_print_char(va_arg(args, int));
	else if (c == 's')
		ft_print_chain(va_arg(args, char *));
	else if (c == 'p')
		ft_printpoint(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		ft_un_putnbr(va_arg(args, unsigned int));
	else if (c == 'x')
		ft_puthexa(va_arg(args, int));
	else if (c == 'X')
		ft_puthexa_maj(va_arg(args, int));
	else
		return ;
}

int	ft_printf(const char *text, ...)
{
	int		i;
	va_list	args;

	i = 0;
	g_count_char = 0;
	va_start(args, text);
	while (text[i] != '\0')
	{
		if (text[i] == '%')
		{
			if ((i < 0 && text[i - 1] == '\\') || text[i + 1] == '%')
				ft_print_char('%');
			else
				ft_switch(text[i + 1], args);
			i++;
		}
		else
			ft_print_char(text[i]);
		i++;
	}
	va_end(args);
	return (g_count_char);
}
