/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 19:29:37 by ellarbi           #+#    #+#             */
/*   Updated: 2019/08/29 19:33:44 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] > 64 && str[i] < 91)
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	ft_strupcase(str);
	if (str[0] > 96 && str[0] < 123)
	{
		str[0] = str[0] - 32;
	}
	i = 1;
	while (str[i] != '\0')
	{
		if (!((47 < str[i - 1] && str[i - 1] < 58) || (str[i - 1] > 64
						&& str[i - 1] < 91) || (str[i - 1] > 96
							&& str[i - 1] < 123)))
		{
			if (str[i] > 96 && str[i] < 123)
			{
				str[i] = str[i] - 32;
			}
		}
		i++;
	}
	return (str);
}
