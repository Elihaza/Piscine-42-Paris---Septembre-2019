/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 14:32:17 by ellarbi           #+#    #+#             */
/*   Updated: 2019/09/17 14:32:19 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_union(char *str, int *tab)
{
    int i;
    i = 0;
    while (str[i] != '\0')
    {
        if (tab[(unsigned char)str[i]] == 0)
        {
            ft_putchar(str[i]);
            tab[(unsigned char)str[i]] = 1;
        }
        i++;
    }
}

int        main(int ac, char **av)
{
    if (ac == 3)
    {
    	int tab[256] = {0};
    	ft_union(av[1], tab);
    	ft_union(av[2], tab);	
    }
    write(1, "\n", 1);
}
