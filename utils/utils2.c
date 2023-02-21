/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaurin- <lmaurin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:34:13 by lmaurin-          #+#    #+#             */
/*   Updated: 2023/02/21 22:30:06 by lmaurin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3D.h"

size_t	ft_strlen(const char *str)
{
	char	*tmp;

	if (!str)
		return (0);
	tmp = (char *)str;
	while (*tmp)
		tmp++;
	return (tmp - str);
}

bool	ft_strcomp(const char *first, const char *second)
{
	if (!first || !second)
		return (-1);
	while (*first == *second && *first && *second)
	{
		first++;
		second++;
	}
	return (*first - *second);
}

int	ft_strncomp(const char *str1, const char *str2, const int n)
{
	int		i;

	i = 0;
	if (!str1 || !str2)
		return (-1);
	while (i < n && str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

int	ft_read_file(t_string *line, const int fd)
{
	char		buf[10000];
	int			read_ret;

	line->string_destructor(line);
	while (true)
	{
		read_ret = read(fd, buf, 10000);
		if (read_ret == -1)
			return (FAILURE);
		if (line->lenght > 25000)
			return (FAILURE_2);
		if (read_ret == 0)
			return (EOM);
		buf[read_ret] = 0;
		if (line->append(line, buf) == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}

void	init_map(t_cube *map)
{
	map->mlx.wall_sprite[0].sprite = NULL;
	map->mlx.wall_sprite[1].sprite = NULL;
	map->mlx.wall_sprite[2].sprite = NULL;
	map->mlx.wall_sprite[3].sprite = NULL;
	map->map = NULL;
}
