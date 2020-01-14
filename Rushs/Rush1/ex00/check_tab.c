/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 13:32:55 by ellarbi           #+#    #+#             */
/*   Updated: 2019/09/08 20:16:12 by hteissei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	reset_row(char **row, int y)
{
	int i;

	i = 1;
	while (i < 5)
	{
		row[y][i] = '0';
		i++;
	}
}

void	print_tab(char **tab)
{
	int x;
	int y;

	x = 1;
	y = 1;
	while (x < 5 && y < 5)
	{
		write(1, &tab[y][x], 1);
		if (x == 4)
		{
			write(1, "\n", 1);
			x = 1;
			y++;
			continue;
		}
		else
			write(1, " ", 1);
		x++;
	}
}
