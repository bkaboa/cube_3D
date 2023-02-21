/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaurin- <lmaurin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:36:19 by lmaurin-          #+#    #+#             */
/*   Updated: 2023/02/21 18:36:20 by lmaurin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3D.h"

void	string_destructor(t_string *str)
{
	if (str)
	{
		str->lenght = 0;
		str->size = 0;
		if (str->str)
			free(str->str);
		str->str = NULL;
	}
}

int64_t	find_file_instructions(t_string str, char **lines, const char **find)
{
	int64_t	i;
	void	*addr;

	i = 0;
	addr = find;
	while (i < 6)
	{
		find = addr;
		if (*str.str != '\n')
		{
			while (ft_strncomp(str.str, *find, ft_strlen(*find)) && find++)
				if (!(*find))
					return (-1);
			if (lines[((void *)find - addr) >> 3])
				return (-2);
			lines[((void *)find - addr) >> 3] = str.str;
			while (*str.str != '\n')
				str.str++;
			i++;
		}
		str.str++;
	}
	return ((int64_t)str.str);
}

void	string_init(t_string *str)
{
	ft_bzero(str, sizeof(t_string));
	str->append = append;
	str->alloc_string = alloc_string;
	str->string_destructor = string_destructor;
	str->reference_copy_operator = reference_copy_operator;
	str->profond_copy_operator = profond_copy_operator;
	str->find = find;
	str->find_file_instructions = find_file_instructions;
}
