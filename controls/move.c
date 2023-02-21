/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaurin- <lmaurin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 01:42:31 by lmaurin-          #+#    #+#             */
/*   Updated: 2023/02/21 20:08:15 by lmaurin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3D.h"

void	move_player_front(t_cube *cube)
{
	if (cube->map[(int)(cube->player.x_pos + \
	cube->player.playerdir.dirx * MOVESPEED)][(int)(cube->player.y_pos)] == '0')
		cube->player.x_pos += cube->player.playerdir.dirx * MOVESPEED;
	if (cube->map[(int)(cube->player.x_pos)][(int)(cube->player.y_pos \
	+ cube->player.playerdir.diry * MOVESPEED)] == '0')
		cube->player.y_pos += cube->player.playerdir.diry * MOVESPEED;
}

void	move_player_back(t_cube *cube)
{
	if (cube->map[(int)(cube->player.x_pos - \
	cube->player.playerdir.dirx * MOVESPEED)][(int)(cube->player.y_pos)] == '0')
		cube->player.x_pos -= cube->player.playerdir.dirx * MOVESPEED;
	if (cube->map[(int)(cube->player.x_pos)][(int)(cube->player.y_pos \
	- cube->player.playerdir.diry * MOVESPEED)] == '0')
		cube->player.y_pos -= cube->player.playerdir.diry * MOVESPEED;
}

void	move_strafe_left(t_cube *cube)
{
	if (cube->map[(int)(cube->player.x_pos - cube->player.playerdir.diry \
	* MOVESPEED)][(int)(cube->player.y_pos)] == '0')
		cube->player.x_pos -= cube->player.playerdir.diry * MOVESPEED;
	if (cube->map[(int)(cube->player.x_pos)][(int)(cube->player.y_pos + \
	cube->player.playerdir.dirx * MOVESPEED)] == '0')
		cube->player.y_pos += cube->player.playerdir.dirx * MOVESPEED;
}

void	move_strafe_right(t_cube *cube)
{
	if (cube->map[(int)(cube->player.x_pos + cube->player.playerdir.diry \
	* MOVESPEED)][(int)(cube->player.y_pos)] == '0')
		cube->player.x_pos += cube->player.playerdir.diry * MOVESPEED;
	if (cube->map[(int)(cube->player.x_pos)][(int)(cube->player.y_pos \
	- cube->player.playerdir.dirx * MOVESPEED)] == '0')
		cube->player.y_pos -= cube->player.playerdir.dirx * MOVESPEED;
}
