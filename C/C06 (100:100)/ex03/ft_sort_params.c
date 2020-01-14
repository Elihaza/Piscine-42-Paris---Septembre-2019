/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 14:56:54 by ellarbi           #+#    #+#             */
/*   Updated: 2019/09/04 21:02:55 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

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

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char*)s1 - *(unsigned char*)s2);
}

void	ft_swap(char **s1, char **s2)
{
	char *swap;

	swap = *s1;
	*s1 = *s2;
	*s2 = swap;
}

void	ft_sort_params(char **strs, int size, int nb)
{
	int		curs;
	bool	change;

	curs = nb;
	while (1)
	{
		curs = nb;
		change = false;
		while (curs < size)
		{
			if (ft_strcmp(strs[curs], strs[curs + 1]) > 0)
			{
				ft_swap(&strs[curs], &strs[curs + 1]);
				change = true;
			}
			curs++;
		}
		if (!change)
			break ;
	}
}

int		main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc > 2)
		ft_sort_params(argv, argc - 1, 1);
	while (i < argc)
	{
		ft_putstr(argv[i]);
		ft_putstr("\n");
		i++;
	}
}
