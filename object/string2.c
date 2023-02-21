/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaurin- <lmaurin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:36:22 by lmaurin-          #+#    #+#             */
/*   Updated: 2023/02/21 18:36:23 by lmaurin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3D.h"

int32_t	alloc_string(t_string *str1, size_t lenght)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * (str1->lenght + lenght + 20));
	if (!str)
		return (FAILURE);
	str1->size = str1->lenght + lenght + 20;
	while (str1->str && str1->str[i])
	{
		str[i] = str1->str[i];
		i++;
	}
	if (str1->str)
		free(str1->str);
	str1->str = str;
	return (SUCCESS);
}

int32_t	append(t_string *str1, const char *str2)
{
	size_t	i;

	i = 0;
	if (!str2)
		return (SUCCESS);
	if ((ft_strlen(str2) + str1->lenght) >= str1->size)
		if (alloc_string(str1, ft_strlen(str2)) == FAILURE)
			return (FAILURE);
	while (str2[i])
		str1->str[(str1->lenght)++] = str2[i++];
	str1->str[str1->lenght] = '\0';
	return (SUCCESS);
}

void	reference_copy_operator(const t_string to_copy, t_string *copy)
{
	copy->string_destructor(copy);
	copy->lenght = to_copy.lenght;
	copy->size = to_copy.size;
	copy->str = to_copy.str;
}

int32_t	profond_copy_operator(const t_string to_copy, t_string *copy)
{
	copy->string_destructor(copy);
	if (copy->append(copy, to_copy.str) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int64_t	find(t_string *str, const char *str2)
{
	int				i;
	const size_t	str2_len = ft_strlen(str2);

	if (!str->str || !str2)
		return (-1);
	i = 0;
	while (i + str2_len < str->lenght)
	{
		if (ft_strncomp(&str->str[i], str2, str2_len) == 0)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}
