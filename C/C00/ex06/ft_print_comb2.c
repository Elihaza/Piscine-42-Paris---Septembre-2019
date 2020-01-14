/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 09:16:56 by ellarbi           #+#    #+#             */
/*   Updated: 2019/08/27 20:42:44 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_puta(char a)
{
	ft_putchar(a / 10 + '0');
	ft_putchar(a % 10 + '0');
}

void	ft_putb(char b)
{
	ft_putchar(b / 10 + '0');
	ft_putchar(b % 10 + '0');
}

void	ft_putspace(void)
{
	ft_putchar(',');
	ft_putchar(' ');
}

void	ft_print_comb2(void)
{
	int a;
	int b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			ft_puta(a);
			ft_putchar(' ');
			ft_putb(b);
			if (!(a == 98 && b == 99))
				ft_putspace();
			b++;
		}
		a++;
	}
}
