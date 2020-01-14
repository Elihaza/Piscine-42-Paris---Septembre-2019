/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:22:58 by ellarbi           #+#    #+#             */
/*   Updated: 2019/09/13 16:22:59 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

bool	is_char_in_string(char c, char *set)
{
	while (true)
	{
		if (*set == '\0')
			return (c == '\0');
		if (*set == c)
			return (true);
		set++;
	}
	return (false);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int		count_occur(char *str, char *charset)
{
	int		count;
	char	*previous;
	char	*next;

	count = 0;
	previous = str;
	next = str;
	while (true)
	{
		if (is_char_in_string(*str, charset))
			next = str;
		if (next - previous > 1)
			count++;
		if (*str == '\0')
			break ;
		previous = next;
		str++;
	}
	return (count);
}

int		add_part(char **entry, char *previous, int size, char *charset)
{
	if (is_char_in_string(previous[0], charset))
	{
		previous++;
		size--;
	}
	*entry = (char *)malloc((size + 3) * sizeof(char));
	ft_strncpy(*entry, previous, size);
	(*entry)[size] = '\0';
	(*entry)[size + 1] = '\0';
	return (1);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		size;
	char	*previous;
	char	*next;
	char	**array;

	array = (char **)malloc((count_occur(str, charset) + 1) * sizeof(char *));
	i = 0;
	previous = str;
	next = str;
	while (true)
	{
		if (is_char_in_string(*str, charset))
			next = str;
		if ((size = next - previous) > 1)
			i += add_part(&array[i], previous, size, charset);
		if (*str == '\0')
			break ;
		previous = next;
		str++;
	}
	array[i] = 0;
	return (array);
}
