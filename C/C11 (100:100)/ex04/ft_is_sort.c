/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 09:42:04 by ellarbi           #+#    #+#             */
/*   Updated: 2019/09/19 09:42:08 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int		i;
	int		sort;

	sort = 1;
	i = 0;
	while (i < length - 1 && sort)
	{
		if ((*f)(tab[i], tab[i + 1]) < 0)
			sort = 0;
		i++;
	}
	if (sort != 1)
	{
		sort = 1;
		i = 0;
		while (i < length - 1)
		{
			if ((*f)(tab[i], tab[i + 1]) > 0)
				return (0);
			i++;
		}
	}
	return (1);
}
