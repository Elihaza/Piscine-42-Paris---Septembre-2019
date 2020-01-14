/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:48:43 by ellarbi           #+#    #+#             */
/*   Updated: 2019/09/18 21:52:34 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

long	check_base(char *base);
long	cacul_res(char *str, char *base, long size_base);
long	ft_atoi_base(char *str, char *base);

long	ft_strlen(char *str)
{
	long	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_putnbr(long nbr, char *base, char *resultat, long i)
{
	long	size;

	size = 0;
	while (base[size])
		size++;
	if (nbr != 0)
	{
		resultat[i] = (base[nbr % size]);
		return (ft_putnbr(nbr / size, base, resultat, i + 1));
	}
	return (resultat);
}

char	*ft_printnbr(char *resultat, long nbr, char *base, long s)
{
	long	i;
	long	size;

	size = 0;
	while (base[size])
		size++;
	i = 0;
	if (s < 0)
		resultat[i++] = '-';
	if (nbr != 0)
		resultat = ft_putnbr(nbr, base, resultat, i);
	else if (nbr == 0)
		resultat[0] = (base[0]);
	return (resultat);
}

char	*ft_strrev(char *resultat)
{
	char	c;
	long	i;
	long	len;

	i = (resultat[0] == '-' ? 1 : 0);
	len = ft_strlen(resultat) - 1;
	while (i < len)
	{
		c = resultat[i];
		resultat[i++] = resultat[len];
		resultat[len--] = c;
	}
	return (resultat);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*resultat;
	long	nb;
	long	s;

	if (!check_base(base_to) || !check_base(base_from))
		return (0);
	nb = ft_atoi_base(nbr, base_from);
	s = 1;
	if (nb < 0)
	{
		nb *= -1;
		s = -1;
	}
	if (!(resultat = malloc((256 + 1) * sizeof(char))))
		return (0);
	ft_printnbr(resultat, nb, base_to, s);
	return (ft_strrev(resultat));
}
