/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hteissei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 20:12:09 by hteissei          #+#    #+#             */
/*   Updated: 2019/09/08 20:20:25 by hteissei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_copy(char *dest, char *src);

void	all_combinaison(char **tab)
{
	ft_copy(tab[0], "1234");
	ft_copy(tab[1], "2134");
	ft_copy(tab[2], "3124");
	ft_copy(tab[3], "1324");
	ft_copy(tab[4], "2314");
	ft_copy(tab[5], "3214");
	ft_copy(tab[6], "3241");
	ft_copy(tab[7], "2341");
	ft_copy(tab[8], "4321");
	ft_copy(tab[9], "3421");
	ft_copy(tab[10], "2431");
	ft_copy(tab[11], "4231");
	ft_copy(tab[12], "4132");
	ft_copy(tab[13], "1432");
	ft_copy(tab[14], "3412");
	ft_copy(tab[15], "4312");
	ft_copy(tab[16], "1342");
	ft_copy(tab[17], "3142");
	ft_copy(tab[18], "2143");
	ft_copy(tab[19], "1243");
	ft_copy(tab[20], "4213");
	ft_copy(tab[21], "2413");
	ft_copy(tab[22], "1423");
	ft_copy(tab[23], "4123");
}

void	init_int_tab(int *tab, int size)
{
	int	i;

	i = -1;
	while (++i < size + 1)
		tab[i] = 24;
}

char	**generate_tab(void)
{
	char	**tab;
	int		a;

	if (!(tab = malloc(sizeof(char*) * 24)))
		return (NULL);
	a = -1;
	while (++a < 24)
	{
		if (!(tab[a] = malloc(sizeof(char) * 5)))
			return (NULL);
	}
	all_combinaison(tab);
	return (tab);
}

char	**initialize_combinaison(void)
{
	char	**ligne;
	int		i;
	int		a;

	if (!(ligne = malloc(sizeof(char *) * 4)))
		return (NULL);
	i = -1;
	while (++i < 4)
	{
		a = -1;
		if (!(ligne[i] = malloc(sizeof(char) * 5)))
			return (NULL);
		while (++a < 4)
			ligne[i][a] = a + 1 + 48;
		ligne[i][a] = '\0';
	}
	return (ligne);
}
