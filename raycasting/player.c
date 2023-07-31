/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 07:38:31 by houaslam          #+#    #+#             */
/*   Updated: 2023/07/31 07:16:04 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	turn_move(int keycode, t_map *map)
{
	if (keycode == ARROW_LEFT)
		map->r.ang += 7;
	else if (keycode == ARROW_RIGHT)
		map->r.ang -= 7;
	return (0);
}

void	move_up_down(t_map *map, int keycode)
{
	int	sinvalue;
	int	cosvalue;

	sinvalue = sin(map->r.ang * M_PI / 180) * SPEED;
	cosvalue = cos(map->r.ang * M_PI / 180) * SPEED;
	if ((keycode == UP || keycode == ARROW_UP) && map->r.distance > 0)
	{
		if (map->map[(int)map->p.u_y / UNIT][(int) \
		(map->p.u_x + cosvalue) / UNIT] != '1')
			map->p.u_x += cos(map->r.ang * M_PI / 180) * SPEED;
		if (map->map[(int)(map->p.u_y - sinvalue) \
		/ UNIT][(int)map->p.u_x / UNIT] != '1')
			map->p.u_y -= sin(map->r.ang * M_PI / 180) * SPEED;
	}
	if ((keycode == DOWN || keycode == ARROW_DOWN))
	{
		if (map->map[(int)map->p.u_y / UNIT] \
		[(int)(map->p.u_x - cosvalue) / UNIT] != '1')
			map->p.u_x -= cos(map->r.ang * M_PI / 180) * SPEED;
		if (map->map[(int)(map->p.u_y + sinvalue) \
		/ UNIT][(int)map->p.u_x / UNIT] != '1')
		map->p.u_y += sin(map->r.ang * M_PI / 180) * SPEED;
	}
}

void	move_left_right(t_map *map, int keycode)
{
	int	sinvalue;
	int	cosvalue;

	sinvalue = sin((90 - map->r.ang) * M_PI / 180) * SPEED;
	cosvalue = cos((90 - map->r.ang) * M_PI / 180) * SPEED;
	if (keycode == LEFT)
	{
		if (map->map[(int)map->p.u_y / UNIT][(int) \
		(map->p.u_x - cosvalue) / UNIT] != '1')
			map->p.u_x -= cosvalue;
		if (map->map[(int)(map->p.u_y - sinvalue) \
		/ UNIT][(int)map->p.u_x / UNIT] != '1')
			map->p.u_y -= sinvalue;
	}
	if (keycode == RIGHT)
	{
		if (map->map[(int)map->p.u_y / UNIT][(int) \
		(map->p.u_x + cosvalue) / UNIT] != '1')
			map->p.u_x += cosvalue;
		if (map->map[(int)(map->p.u_y + sinvalue) / \
		UNIT][(int)map->p.u_x / UNIT] != '1')
			map->p.u_y += sinvalue;
	}
}

int	which_move(int keycode, t_map *map)
{
	if (keycode == LEFT || keycode == RIGHT)
		move_left_right(map, keycode);
	else if (keycode == UP || keycode == ARROW_UP \
	|| keycode == DOWN || keycode == ARROW_DOWN)
		move_up_down(map, keycode);
	else
		turn_move(keycode, map);
	if (keycode == 53)
		ft_exit(map->window);
	rays_casting(map, map->window);
	return (0);
}

void	player_view(t_map **map)
{
	if ((*map)->map[(int)(*map)->p.y][(int)(*map)->p.x] == 'E')
		(*map)->r.ang = 0;
	else if ((*map)->map[(int)(*map)->p.y][(int)(*map)->p.x] == 'N')
		(*map)->r.ang = 90;
	else if ((*map)->map[(int)(*map)->p.y][(int)(*map)->p.x] == 'W')
		(*map)->r.ang = 180;
	else if ((*map)->map[(int)(*map)->p.y][(int)(*map)->p.x] == 'S')
		(*map)->r.ang = 270;
	(*map)->r.cast = (*map)->r.ang + 30;
}
