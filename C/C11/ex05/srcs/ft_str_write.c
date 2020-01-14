/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 09:44:30 by ellarbi           #+#    #+#             */
/*   Updated: 2019/09/19 09:44:32 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft_io.h"
#include "ft_char.h"

void	ft_str_write_to(int fd, char *str)
{
	while (*str)
	{
		ft_char_write_to(fd, *str);
		str++;
	}
}

void	ft_str_write(char *str)
{
	ft_str_write_to(OUT, str);
}
