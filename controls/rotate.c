/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaurin- <lmaurin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:08:16 by lmaurin-          #+#    #+#             */
/*   Updated: 2023/02/21 18:17:20 by lmaurin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3D.h"

void	rotateleft(t_player *player)
{
	float	old_dirx;
	float	old_planex;

	old_dirx = player->playerdir.dirx;
	player->playerdir.dirx = player->playerdir.dirx \
	* cos(ROTATIONSPEED) - player->playerdir.diry * sin(ROTATIONSPEED);
	player->playerdir.diry = old_dirx * sin(ROTATIONSPEED) \
	+ player->playerdir.diry * cos(ROTATIONSPEED);
	old_planex = player->planeX;
	player->planeX = player->planeX * cos(ROTATIONSPEED) \
	- player->planeY * sin(ROTATIONSPEED);
	player->planeY = old_planex * sin(ROTATIONSPEED) \
	+ player->planeY * cos(ROTATIONSPEED);
}

void	rotateright(t_player *player)
{
	float	old_dirx;
	float	old_planex;

	old_dirx = player->playerdir.dirx;
	player->playerdir.dirx = player->playerdir.dirx \
	* cos(-ROTATIONSPEED) - player->playerdir.diry * sin(-ROTATIONSPEED);
	player->playerdir.diry = old_dirx * sin(-ROTATIONSPEED) \
	+ player->playerdir.diry * cos(-ROTATIONSPEED);
	old_planex = player->planeX;
	player->planeX = player->planeX * cos(-ROTATIONSPEED) \
	- player->planeY * sin(-ROTATIONSPEED);
	player->planeY = old_planex * sin(-ROTATIONSPEED) \
	+ player->planeY * cos(-ROTATIONSPEED);
}
