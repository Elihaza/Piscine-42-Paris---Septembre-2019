/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 08:54:06 by ellarbi           #+#    #+#             */
/*   Updated: 2019/09/01 19:37:11 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

int			verif_base(char *base)
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

void		ft_putnbr_base(int nbr, char *base)
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

int			ft_atoi(char *str)
{
	int i;
	int s;
	int res;

	i = 0;
	s = 1;
	res = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -s;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * s);
}

void		ft_atoi_base(char *str, char *base)
{
	int nb;

	nb = ft_atoi(str);
	ft_putnbr_base(nb, base);
}
