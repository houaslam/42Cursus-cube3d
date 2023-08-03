/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 08:59:03 by houaslam          #+#    #+#             */
/*   Updated: 2023/08/03 09:37:40 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/raycasting.h"

void	draw_square(int color, int x, int y, t_window *window)
{
	int	a;
	int	b;

	a = -1;
	while (++a < MINI_UNIT)
	{
		b = -1;
		while (++b < MINI_UNIT)
			my_mlx_pixel_put(&window->map->mini, x++, y, color);
		x -= MINI_UNIT;
		y++;
	}
}

void	base(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < PP_HEIGHT/5)
	{
		x = 0;
		while (x < PP_WIDTH/5)
		{
			my_mlx_pixel_put(&map->mini, x, y, PURPLE);
			x++;
		}
		y++;
	}
	map->minimap.height = PP_HEIGHT/5;
	map->minimap.width =  PP_WIDTH/5;
	map->minimap.mini_p.u_x = (map->p.u_x / UNIT) * MINI_UNIT;
	map->minimap.mini_p.u_y = (map->p.u_y / UNIT) * MINI_UNIT;
}

int check(t_map *map, int x, int y)
{
	if (x / MINI_UNIT < 0 || y / MINI_UNIT < 0)
		return (0);
	if((y + MINI_UNIT / 2) / MINI_UNIT >= map->m_y || (x + MINI_UNIT / 2) / MINI_UNIT >= map->m_x )
		return (0);
	if (map->map[y  / MINI_UNIT][(x) / MINI_UNIT] != '1')
		return (0);
	if (map->map[(y) / MINI_UNIT][x / MINI_UNIT] != '1')
		return (0);
	return (1);
}


void	draw_player(t_map *map)
{
	int x;
	int y;
	
	y = map->minimap.height / 2;
	while(y > map->minimap.height / 2 - 15)
	{
		x = map->minimap.width / 2 + MINI_UNIT / 2;
		while(x < map->minimap.width / 2 + MINI_UNIT / 2 + 2) 
			my_mlx_pixel_put(&map->mini, x++, y, 225111);
		y--;
	}
	draw_square(225111, map->minimap.width / 2, map->minimap.height / 2, map->window);
}

void	draw_minimap(t_map *map)
{
	int x;
	int y;
	int x_mov;
	int y_mov;

	base(map);
	y = map->minimap.mini_p.u_y -  map->minimap.height / 2;
	y_mov = 0;
	while (y_mov < map->minimap.height)
	{
		x = map->minimap.mini_p.u_x -  map->minimap.width / 2;
		x_mov = 0;
		while(x_mov < map->minimap.width)
		{
			if (check(map, x, y))
				my_mlx_pixel_put(&map->mini, x_mov, y_mov, BLACK);
			x_mov++;
			x++;
		}	
			y_mov++;
			y++;
	}
	draw_player(map);
}




// void	draw_minimap(t_map *map)
// {
// 	int	x;
// 	int	y;
// 	int x1;
// 	int y1;

// 	base(map);
// 	y = map->minimap.mini_p.u_y - (map->minimap.height / 2);
// 	y1 = 0;
// 	while (y1 < map->minimap.height)
// 	{
// 		x = map->minimap.mini_p.u_x - (map->minimap.width / 2);
// 		x1 = 0;
// 		while (x1 < map->minimap.width)
// 		{
// 			if (x / MINI_UNIT >= 0 && y / MINI_UNIT >= 0 && y / MINI_UNIT < \
// 			map->m_y && x / MINI_UNIT < map->m_x && map->map[y / MINI_UNIT][x / MINI_UNIT] == '1')
// 				my_mlx_pixel_put(&map->mini, x1, y1, PURPLE);
// 			x++;
// 			x1++;
// 		}
// 		y1++;
// 		y++;
// 	}
// 	draw_square(225111, map->minimap.width / 2, map->minimap.height / 2, map->window);
// }
