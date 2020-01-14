/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 13:40:20 by ellarbi           #+#    #+#             */
/*   Updated: 2019/08/31 14:56:32 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_dec_to_hex(long int r, long int q)
{
	if (str[i] <= 32 && str[i] >= 126)
	{
		q = str[i] - '0';
		while (q != 0)
		{
			r = q % 16;
			if (r < 10)
				str[i++] = r + 48;
			else
				str[i++] = r + 55;
			q = q / 16;
		}
	}
}

void	ft_putstr_non_printable(char *str)
{
	int			i;
	long int	r;
	long int	q;

	i = 0;
	while (str[i])
	{
		ft_dec_to_hex(r, q);
		while (str[i] >= 32 && str[i] <= 126)
		{
			ft_putstr(str);
			i++;
		}
		i++;
	}
}
