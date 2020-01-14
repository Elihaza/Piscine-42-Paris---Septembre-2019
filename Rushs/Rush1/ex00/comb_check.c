/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comb_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hteissei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 20:09:54 by hteissei          #+#    #+#             */
/*   Updated: 2019/09/08 20:17:32 by hteissei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		duplicate_check(int x, int y, char **tab)
{
	int	x_copy;
	int	y_copy;
	int	value;

	value = tab[y][x];
	x_copy = 0;
	while (++x_copy < 5)
	{
		if (tab[y][x_copy] == value && x_copy != x)
			return (1);
	}
	y_copy = 0;
	while (++y_copy < 5)
	{
		if (tab[y_copy][x] == value && y_copy != y)
			return (1);
	}
	return (0);
}

int		cant_see_line(char **tab, int y, int compteur, int x)
{
	int reference;

	compteur = 0;
	x = 0;
	reference = tab[y][1] - 48;
	while (++x < 5)
	{
		if (tab[y][x] - 48 >= reference)
			compteur++;
		if (tab[y][x] - 48 > reference)
			reference = tab[y][x] - 48;
	}
	if (compteur != tab[y][0] - 48)
		return (1);
	reference = tab[y][4] - 48;
	compteur = 0;
	while (--x > 0)
	{
		if (tab[y][x] - 48 >= reference)
			compteur++;
		if (tab[y][x] - 48 > reference)
			reference = tab[y][x] - 48;
	}
	return (0);
}
