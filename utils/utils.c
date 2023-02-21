/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaurin- <lmaurin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:33:12 by lmaurin-          #+#    #+#             */
/*   Updated: 2023/02/21 18:33:13 by lmaurin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3D.h"

void	free_double_pointer(void **pointer)
{
	int	i;

	i = -1;
	if (pointer)
	{
		while (pointer[++i])
			free(pointer[i]);
		free(pointer);
	}
}

int	add_line(t_cube map, t_string line)
{
	int		i;
	char	**new_map;

	i = 0;
	while (map.map && map.map[i])
		i++;
	new_map = malloc(sizeof(char *) * (i + 1));
	if (new_map == NULL)
		return (FAILURE);
	i = -1;
	while (map.map && map.map[++i])
		new_map[i] = map.map[i];
	new_map[i] = line.str;
	new_map[i + 1] = NULL;
	free_double_pointer((void **)map.map);
	map.map = new_map;
	return (SUCCESS);
}

void	ft_bzero(void *var, int64_t var_size)
{
	const void	*var_str = var;

	while (var - var_str < var_size)
		*(char *)(var++) = 0;
}

int	check_char_in_str(char *str, char c)
{
	char	*tmp_str;

	tmp_str = str;
	while (*str)
	{
		if (*str == c)
			return (str - tmp_str);
		str++;
	}
	return (-1);
}

void	ft_itoa_fd(u_int64_t num, int fd)
{
	char	c;

	c = num % 10 + 48;
	if (num > 9)
		ft_itoa_fd(num / 10, fd);
	write(fd, &c, 1);
}
