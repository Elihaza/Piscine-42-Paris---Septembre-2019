/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_dictionary.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 18:18:32 by ellarbi           #+#    #+#             */
/*   Updated: 2019/09/15 18:18:34 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NUMBER_DICTIONARY_H
# define FT_NUMBER_DICTIONARY_H

# include "ft_boolean.h"

# define INVALID -1
# define ENGLISH_DICT "numbers.dict"

typedef struct	s_dict_entry
{
	unsigned long	value;
	char	*str;
	t_bool	normal;
}				t_dict_entry;

typedef struct	s_dict
{
	char			*path;
	t_bool			valid;
	int				size;
	t_dict_entry	*entries;
}				t_dict;

typedef enum {
	none,
	generic,
	invalid_number,
	fail_convert,
	dict_parsing
}	t_error;

t_dict			ft_load_default_dictionary(void);
t_dict			ft_load_dictionary(char *path);
void			ft_free_dictionary(t_dict *dict);

#endif
