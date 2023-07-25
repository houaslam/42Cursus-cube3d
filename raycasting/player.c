/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 07:38:31 by houaslam          #+#    #+#             */
/*   Updated: 2023/07/25 11:24:23 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"


int	ft_exit(t_window *mlx)
{
	printf("GAME OVER !!");
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit(0);
}

int	which_move(int keycode, t_map *map)
{
	if (keycode == LEFT)
	{
		map->minimap.px -= 2;
		map->p.u_x -= SPEED;
	}
	else if (keycode == RIGHT)
	{
		map->minimap.px += 2;
		map->p.u_x += SPEED;
	}
	else if (keycode == UP)
	{
		map->minimap.py -= 2;
		map->p.u_y -= SPEED;
	}
	else if (keycode == DOWN)
	{
		map->minimap.py += 2;
		map->p.u_y += SPEED;
	}
	else if (keycode == 53)
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
