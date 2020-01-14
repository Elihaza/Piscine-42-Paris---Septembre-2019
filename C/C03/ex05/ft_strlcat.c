/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 15:01:54 by ellarbi           #+#    #+#             */
/*   Updated: 2019/08/31 18:22:45 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	j = 0;
	k = 0;
	while (dest[i])
		i++;
	while (src[k])
		k++;
	if (size <= i) //i = len(dest)
		k += size; //k = len(src)
	else
		k += i; //k = len(src)
	while (src[j] && i + 1 < size)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (k);
}

int main()
{
	char dst[] = "Bon";
	char src[] = "Coucou";
	printf("%u\n", ft_strlcat(dst, src, 9));
	//printf("%lu\n", strlcat(dst, src, 100));
}