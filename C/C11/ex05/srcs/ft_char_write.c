/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 09:44:03 by ellarbi           #+#    #+#             */
/*   Updated: 2019/09/19 09:44:05 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft_io.h"

void	ft_char_write_to(int fd, char c)
{
	write(fd, &c, 1);
}

void	ft_char_write(char c)
{
	ft_char_write_to(OUT, c);
}
