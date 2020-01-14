/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 16:13:19 by ellarbi           #+#    #+#             */
/*   Updated: 2019/08/31 18:05:36 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (*to_find == '\0')
		return (str);
	while (str[i] && (ft_strlen(str) >= ft_strlen(to_find)))
	{
		if (str[i] == to_find[j])
		{
			while (str[i] == to_find[j])
			{
				if (to_find[j + 1] == '\0')
					return (&str[i - j]);
				i++;
				j++;
			}
			i = i - j;
		}
		j = 0;
		i++;
	}
	return (0);
}
