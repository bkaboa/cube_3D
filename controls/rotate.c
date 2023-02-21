/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaurin- <lmaurin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:08:16 by lmaurin-          #+#    #+#             */
/*   Updated: 2023/02/21 20:08:46 by lmaurin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3D.h"

void	rotateleft(t_player *player)
{
	float	old_dirx;
	float	old_plane_x;

	old_dirx = player->playerdir.dirx;
	player->playerdir.dirx = player->playerdir.dirx \
	* cos(ROTATIONSPEED) - player->playerdir.diry * sin(ROTATIONSPEED);
	player->playerdir.diry = old_dirx * sin(ROTATIONSPEED) \
	+ player->playerdir.diry * cos(ROTATIONSPEED);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(ROTATIONSPEED) \
	- player->plane_y * sin(ROTATIONSPEED);
	player->plane_y = old_plane_x * sin(ROTATIONSPEED) \
	+ player->plane_y * cos(ROTATIONSPEED);
}

void	rotateright(t_player *player)
{
	float	old_dirx;
	float	old_plane_x;

	old_dirx = player->playerdir.dirx;
	player->playerdir.dirx = player->playerdir.dirx \
	* cos(-ROTATIONSPEED) - player->playerdir.diry * sin(-ROTATIONSPEED);
	player->playerdir.diry = old_dirx * sin(-ROTATIONSPEED) \
	+ player->playerdir.diry * cos(-ROTATIONSPEED);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(-ROTATIONSPEED) \
	- player->plane_y * sin(-ROTATIONSPEED);
	player->plane_y = old_plane_x * sin(-ROTATIONSPEED) \
	+ player->plane_y * cos(-ROTATIONSPEED);
}
