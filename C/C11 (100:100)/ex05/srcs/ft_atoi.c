/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 09:43:51 by ellarbi           #+#    #+#             */
/*   Updated: 2019/09/19 09:43:53 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_boolean.h"
#include "ft_is.h"

int		ft_atoi(char *str)
{
	int	res;
	int	s;

	s = 1;
	while (ft_is_whitespace(*str))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			s *= -1;
		str++;
	}
	res = 0;
	while (ft_is_number(*str))
	{
		res *= 10;
		res += (*str) - '0';
		str++;
	}
	return (res * s);
}
