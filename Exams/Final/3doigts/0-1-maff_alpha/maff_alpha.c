/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maff_alpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 21:29:02 by exam              #+#    #+#             */
/*   Updated: 2017/12/13 15:51:41 by lsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	affiche(char c)
{
	write(1, &c, 1);
}

int		main(void)
{
	int a;
	int b;

	a = 'a';
	b = 'B';
	while (a <= 'y')
	{
		while (b <= 'Z')
		{
			affiche(a);
			a += 2;
			affiche(b);
			b += 2;
		}
	}
	affiche('\n');
	return (0);
}
