/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 07:38:31 by houaslam          #+#    #+#             */
/*   Updated: 2023/07/27 06:52:44 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	ft_exit(t_window *mlx)
{
	printf("GAME OVER !!");
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit(0);
}

int	turn_move(int keycode, t_map *map)
{
	if (keycode == ARROW_LEFT)
		map->r.ang += 7;
	else if (keycode == ARROW_RIGHT)
		map->r.ang -= 7;
	return (0);
}

void	move_up(t_map *map)
{
	int sinvalue;
	int cosvalue;

	sinvalue = sin(map->r.ang * M_PI / 180) * SPEED;
	cosvalue = cos(map->r.ang * M_PI / 180) * SPEED;
	if (map->map[map->p.u_y / UNIT][(map->p.u_x + cosvalue) / UNIT] != '1')
		map->p.u_x += cosvalue;
	if (map->map[(map->p.u_y - sinvalue)/ UNIT][map->p.u_x / UNIT] != '1')
		map->p.u_y -= sinvalue;
}

int	which_move(int keycode, t_map *map)
{
	if (keycode == LEFT)
	{
		map->p.u_x -= sin((90 - map->r.alpha) * M_PI / 180) * SPEED;
		map->p.u_y -= cos((90 - map->r.alpha) * M_PI / 180) * SPEED;
	}
	else if (keycode == RIGHT)
	{
		map->p.u_x += cos((90 - map->r.ang) * M_PI / 180) * SPEED;
		map->p.u_y += sin((90 - map->r.ang) * M_PI / 180) * SPEED;
	}
	else if (keycode == UP || keycode == ARROW_UP)
	{
		map->p.u_x += cos(map->r.ang * M_PI / 180) * SPEED;
		map->p.u_y -= sin(map->r.ang * M_PI / 180) * SPEED;
	}
	else if (keycode == DOWN || keycode == ARROW_DOWN)
	{
		map->p.u_x -= cos(map->r.ang * M_PI / 180) * SPEED;
		map->p.u_y += sin(map->r.ang * M_PI / 180) * SPEED;
	}
	else
		turn_move(keycode, map);
	if (keycode == 53)
		ft_exit(map->window);
	rays_casting(&map, map->window);
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
