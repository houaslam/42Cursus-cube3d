/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:31:12 by houaslam          #+#    #+#             */
/*   Updated: 2023/07/19 13:25:36 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting/raycasting.h"


int	main(int ac, char **av)
{
	t_window	*window;
	t_map		*map;

	(void)av;
	(void)ac;
	window = (t_window *)malloc(sizeof(t_window));
	map = (t_map *)malloc(sizeof(t_map));
	window->map = map;
	map->window = window;
	map->map = (char **)malloc(sizeof(char *) * 5);
	map->map[0] = "11111";
	map->map[1] = "10001";
	map->map[2] = "10001";
	map->map[3] = "10N01";
	map->map[4] = NULL;
	player_position(&map);
	window->mlx = mlx_init();
	window->mlx_win = mlx_new_window(window->mlx, PP_WIDTH, PP_HEIGHT, "Cube");
	// parsing(&map, av);
	map->m_x = 4;
	map->m_y = 3;
	player_view(&window->map);
	set_distance(&map, window);
	mlx_loop(window->mlx);
}