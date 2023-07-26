/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:31:12 by houaslam          #+#    #+#             */
/*   Updated: 2023/07/26 14:59:29 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting/raycasting.h"

int	main(int ac, char **av)
{
	t_window	*window;
	t_map		*map;

	if (ac != 2)
	{
		printf("∆ invalid number of arguments! ∆\n");
		exit(1);
	}
	window = (t_window *)malloc(sizeof(t_window));
	map = (t_map *)malloc(sizeof(t_map));
	window->map = map;
	map->window = window;
	parsing(&map, av);
	window->mlx = mlx_init();
	window->mlx_win = mlx_new_window(window->mlx, PP_WIDTH, PP_HEIGHT, "Cube");
	player_view(&window->map);
	map->p.u_x = ((map)->p.x * UNIT) + (UNIT / 2);
	map->p.u_y = ((map)->p.y * UNIT) + (UNIT / 2);
	map->minimap.px = (map)->p.x;
	map->minimap.py = (map)->p.y;
	map->img.img = mlx_new_image(window->mlx, PP_WIDTH, PP_HEIGHT);
	rays_casting(&map, window);
	mlx_hook(window->mlx_win, 2, 0, which_move, map);
	mlx_hook(window->mlx_win, 17, 0, ft_exit, map);
	mlx_loop(window->mlx);
}
