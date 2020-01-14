/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hteissei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 19:47:05 by hteissei          #+#    #+#             */
/*   Updated: 2019/09/08 20:20:10 by hteissei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	reset_row(char *row);
void	print_tab(char **tab);
int		param_check1(int argc, char **argv);
int		param_check2(char **argv);
int		cant_see_line(char **tab, int y, int compteur, int x);
int		duplicate_check(int x, int y, char **tab);
char	**initialize_combinaison(void);
void	all_combinaison(char **tab);
char	**generate_tab(void);
void	init_int_tab(int *tab, int size);

void	ft_copy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] && i < 4)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void	next_combinaison(char *combinaison, char **all_four_combinaison)
{
	int	i;
	int	a;

	a = 0;
	i = -1;
	while (++i < 24)
	{
		while (combinaison[a] == all_four_combinaison[i][a])
		{
			a++;
			if (combinaison[a] == '\0' || a == 4)
			{
				ft_copy(combinaison, all_four_combinaison[i + 1]);
				return ;
			}
		}
		a = 0;
	}
}

int		tab_filler(char **tab, char **all_four_combinaison, int *comb_done)
{
	char	**combinaison;
	int		x;
	int		y;

	combinaison = initialize_combinaison();
	y = 0;
	x = 0;
	while (++y < 5)
	{
		while (++x < 5)
		{
			tab[y][x] = combinaison[y - 1][x - 1];
			if (duplicate_check(x, y, tab) == 1)
			{
				--comb_done[y - 1];
				if (!(comb_done[y - 1] == 0 && y > 1))
					next_combinaison(combinaison[y - 1], all_four_combinaison);
				x = 0;
			}
		}
		x = 0;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	char	**tab;
	char	**four_all_comb;
	int		*comb_done;
	int		i;

	if (param_check1(argc, argv) == 1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	comb_done = malloc(sizeof(int) * 6);
	tab = malloc(sizeof(char *) * 6);
	if (!tab || !comb_done)
		return (0);
	i = -1;
	while (++i < 6)
	{
		if (!(tab[i] = malloc(sizeof(char) * 7)))
			return (0);
	}
	init_int_tab(comb_done, 4);
	four_all_comb = generate_tab();
	tab_filler(tab, four_all_comb, comb_done);
	print_tab(tab);
}
