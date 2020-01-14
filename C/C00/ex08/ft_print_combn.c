/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 15:59:27 by ellarbi           #+#    #+#             */
/*   Updated: 2019/08/27 17:31:45 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	affich(int n, int *tab)
{
	int	i;
	int	a;

	a = 1;
	i = 0;
	while (++i < n)
		if (tab[i - 1] >= tab[i])
			a = 0;
	if (!a)
		return ;
	i = -1;
	while (++i < n)
		ft_putchar(tab[i] + 48);
	if (tab[0] < (10 - n))
		write(1, ", ", 2);
}

void	ft_print_combn(int n)
{
	int	i;
	int	tab[10];

	if (n > 10 || n < 0)
		return ;
	i = -1;
	while (++i < n)
		tab[i] = i;
	while (tab[0] <= (10 - n) && n >= 1)
	{
		affich(n, tab);
		if (n == 10)
			break ;
		tab[n - 1]++;
		i = n;
		while (i && n > 1)
		{
			i--;
			if (tab[i] > 9)
			{
				tab[i - 1]++;
				tab[i] = 0;
			}
		}
	}
}
