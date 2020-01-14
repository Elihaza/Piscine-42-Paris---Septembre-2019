/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 11:20:29 by exam              #+#    #+#             */
/*   Updated: 2019/09/20 13:21:23 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

long int	count_n(long int n)
{
	long int	i;
	long int	nb;

	i = 1;
	nb = n;
	while (nb >= 10)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char		*ft_strrev(char *str)
{
	int		i;
	int		size;
	char	swap;

	i = 0;
	size = 0;
	while (str[size])
		size++;
	size--;
	while (i < size)
	{
		swap = str[i];
		str[i] = str[size];
		str[size] = swap;
		i++;
		size--;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	int				i;
	int				s;
	long int		len;
	long int		nb;
	char			*tab;

	i = 0;
	s = 1;
	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		s = -1;
	}
	len = count_n(nb);
	if (s == -1)
	{
		if (!(tab = malloc(len + 2)))
				return (0);
		len = len + 1;
	}
	else 
		if (!(tab = malloc(len + 1)))
			return (0);
	tab[len] = '\0';
	while (len > 0)
	{
		len--;
		tab[len] = (nb % 10) + '0';
		nb = nb / 10;
	}
	if (s == -1)
		tab[len] = '-';
	return (tab);
}
