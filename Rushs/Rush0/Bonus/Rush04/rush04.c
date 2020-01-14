/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 09:24:35 by ellarbi           #+#    #+#             */
/*   Updated: 2019/08/31 12:20:27 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	start(int x, int y)
{
	int cntx;
	int cnty;

	cntx = 0;
	cnty = 0;
	if (cntx < x && cnty < y)
	{
		if (cntx == 0)
			ft_putchar('A');
		cntx++;
		while (cntx < x - 1)
		{
			ft_putchar('B');
			cntx++;
		}
		if (cntx == x - 1)
			ft_putchar('C');
		ft_putchar('\n');
	}
}

void	middle(int x, int y)
{
	int cntx;
	int cnty;

	cnty = 2;
	while (cnty < y && x > 0)
	{
		cntx = 0;
		if (cntx == 0)
			ft_putchar('B');
		cntx++;
		while (cntx < x - 1)
		{
			ft_putchar(' ');
			cntx++;
		}
		if (cntx == x - 1)
			ft_putchar('B');
		ft_putchar('\n');
		cnty++;
	}
}

void	end(int x, int y)
{
	int cntx;
	int cnty;

	cntx = 0;
	cnty = 0;
	if (y >= 2 && x > 0)
	{
		if (cntx == 0)
			ft_putchar('C');
		cntx++;
		while (cntx < x - 1)
		{
			ft_putchar('B');
			cntx++;
		}
		if (cntx == x - 1)
			ft_putchar('A');
		ft_putchar('\n');
	}
}

void	rush(int x, int y)
{
	start(x, y);
	middle(x, y);
	end(x, y);
}
