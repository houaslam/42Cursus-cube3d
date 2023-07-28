/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 08:59:03 by houaslam          #+#    #+#             */
/*   Updated: 2023/07/27 13:16:28 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	draw_square(int color, int x, int y, t_window *window)
{
	int	a;
	int	b;

	x *= 10;
	y *= 10;
	a = -1;
	while (++a < 10)
	{
		b = -1;
		while (++b < 10)
			mlx_pixel_put(window->mlx, window->mlx_win, x++, y, color);
		x -= 10;
		y++;
	}
}

// void	draw_player(int x, int y, t_window *window)
// {
// 	int	a;
// 	int	b;

// 	x *= 10;
// 	y *= 10;
// 	a = -1;
// 	while (++a < 5)
// 	{
// 		b = -1;
// 		while (++b < 5)
// 			mlx_pixel_put(window->mlx, window->mlx_win, x++, y, YELLOW);
// 		x -= 5;
// 		y++;
// 	}
// }

void	draw_minimap(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	map->minimap.height = floor((map)->p.u_x / UNIT) * 2;
	map->minimap.width = floor((map)->p.u_y / UNIT) * 2;
	draw_square(PURPLE, map->minimap.px, map->minimap.py, map->window);
	while (map->map[y] && y < map->minimap.height)
	{
		x = 0;
		while (map->map[y][x] && x < map->minimap.width)
		{
			if (map->map[y][x] == '1')
				draw_square(BLACK, x, y, map->window);
			x++;
		}
		y++;
	}
}
