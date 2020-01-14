/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_duplicate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 18:23:19 by ellarbi           #+#    #+#             */
/*   Updated: 2019/09/15 18:23:21 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_str.h"

char	*ft_str_duplicate(char *src)
{
	int		length;
	int		index;
	char	*dest;

	length = ft_str_length(src);
	index = 0;
	if ((dest = (char *)malloc((length + 1) * sizeof(char))) == NULL)
		return (0);
	while (src[index])
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

char	*ft_str_n_duplicate(char *str, int n)
{
	int		index;
	int		length;
	char	*dup;

	length = 0;
	while (str[length])
		length++;
	if (length > n)
		length = n;
	if (!(dup = malloc((length + 1) * sizeof(char))))
		return (NULL);
	index = 0;
	while (index < length)
	{
		dup[index] = str[index];
		index++;
	}
	dup[index] = '\0';
	return (dup);
}
