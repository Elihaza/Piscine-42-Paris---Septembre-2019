/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 11:11:23 by exam              #+#    #+#             */
/*   Updated: 2019/09/20 11:17:49 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_union(char *str, int tab[256])
{
	int i;

	i = 0;
	while (str[i])
	{
		if (tab[(unsigned char)str[i]] == 0)
		{
			write(1, &str[i], 1);
			tab[(unsigned char)str[i]] = 1;
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	int tab[256] = {0};
	
	if (argc == 3)
	{
		ft_union(argv[1], tab);
		ft_union(argv[2], tab);
	}
	write(1, "\n", 1);
}
