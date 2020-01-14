/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hteissei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 20:07:22 by hteissei          #+#    #+#             */
/*   Updated: 2019/09/08 20:08:39 by hteissei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		param_check2(char **argv)
{
	int	i;

	i = 0;
	while (i < 23 && argv[1][i + 8])
	{
		if (argv[1][i] == argv[1][i + 8] && argv[1][i] != '2')
			return (1);
		i = i + 2;
		if (i > 30)
			break ;
	}
	return (0);
}

int		param_check1(int argc, char **argv)
{
	int	i;
	int	count;

	if (argc != 2)
		return (1);
	i = -1;
	count = 0;
	while (argv[1][++i])
	{
		if (i > 30 || ((argv[1][i] < 49 || argv[1][i] > 52)
					&& argv[1][i] != ' '))
			return (1);
		if (argv[1][i] >= 49 && argv[1][i] <= 52)
			count++;
		if (argv[1][i] == ' ')
			count--;
		if (count > 1 || count < 0 || ((count == 0 || i != 30)
					&& argv[1][i + 1] == '\0'))
			return (1);
	}
	return (param_check2(argv));
}
