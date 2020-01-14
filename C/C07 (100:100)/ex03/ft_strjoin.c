/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 10:28:06 by ellarbi           #+#    #+#             */
/*   Updated: 2019/09/12 11:34:49 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		ft_end_len(char **strs, int size, int sep_len)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		len += sep_len;
		i++;
	}
	len -= sep_len;
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		len;
	int		i;
	char	*frst_str;
	char	*str;

	if (size == 0)
		return ((char *)malloc(sizeof(char)));
	len = ft_end_len(strs, size, ft_strlen(sep));
	if (!(str = (char *)malloc((len + 1) * sizeof(char))))
		return (0);
	frst_str = str;
	i = 0;
	while (i < size)
	{
		ft_strcpy(frst_str, strs[i]);
		frst_str += ft_strlen(strs[i]);
		if (i < size - 1)
		{
			ft_strcpy(frst_str, sep);
			frst_str += ft_strlen(sep);
		}
		i++;
	}
	*frst_str = '\0';
	return (str);
}
