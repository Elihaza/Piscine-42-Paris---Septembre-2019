/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 15:47:53 by ellarbi           #+#    #+#             */
/*   Updated: 2019/09/09 11:31:08 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		verif_base(char *base)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (base[i] != '\0')
	{
		if ((base[i] < 47 || (base[i] > 58 && base[i] < 64)
					|| (base[i] > 91 && base[i] < 96) || base[i] > 123))
			return (0);
		while (base[i + j] != '\0')
		{
			if (base[i] == base[i + j])
				return (0);
			j++;
		}
		i++;
		j = 1;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int lenbase;
	int i;
	int res[100];

	lenbase = 0;
	i = 0;
	while (base[lenbase])
		lenbase++;
	if (lenbase > 1 && verif_base(base) == 1)
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			ft_putchar('-');
		}
		while (nbr)
		{
			res[i] = nbr % lenbase;
			nbr = nbr / lenbase;
			i++;
		}
		while (--i >= 0)
			ft_putchar(base[res[i]]);
	}
}

int main()
{
	ft_putnbr_base(03, "0123456789abcdef");
}
