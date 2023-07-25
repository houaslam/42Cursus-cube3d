/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 07:38:31 by houaslam          #+#    #+#             */
/*   Updated: 2023/07/25 17:46:26 by houaslam         ###   ########.fr       */
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

int	which_move(int keycode, t_map *map)
{
	// t_data *data;

	// data->addr = mlx_get_data_addr(map->window->mlx_win, &data->bits_per_pixel, &data->line_length, &data->endian);
	if (keycode == LEFT)
		map->p.u_x -= SPEED;
	else if (keycode == RIGHT)
		map->p.u_x += SPEED;
	else if (keycode == UP)
		map->p.u_y -= SPEED;
	else if (keycode == DOWN)
		map->p.u_y += SPEED;
	else if (keycode == 53)
		ft_exit(map->window);
	else
		turn_move(keycode, map);
	
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
