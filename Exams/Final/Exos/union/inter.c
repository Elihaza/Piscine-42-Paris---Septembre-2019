/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:17:09 by ellarbi           #+#    #+#             */
/*   Updated: 2019/09/19 18:32:57 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_check(char c, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_inter(char *str, char *str2, int *tab)
{
	int i;

	i = 0 ;
	while (str[i])
	{
		if (tab[(unsigned char)str[i]] == 0)
		{
			if (ft_check(str[i], str2) == 1)
			{
				ft_putchar(str[i]);
				tab[(unsigned char)str[i]] = 1;
			}
		}
		i++;
	}
}

int 	main(int argc, char **argv)
{
	int tab[256] = {0};
	if (argc == 3)
		ft_inter(argv[1], argv[2], tab);
	ft_putchar('\n');
	return (0);
}
