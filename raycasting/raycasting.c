/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 18:48:02 by houaslam          #+#    #+#             */
/*   Updated: 2023/07/19 09:45:02 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

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
	window->mlx = mlx_init();
	window->mlx_win = mlx_new_window(window->mlx, PP_WIDTH, PP_HEIGHT, "Cube");
	map->map = (char **)malloc(sizeof(char *) * 5);
	map->map[0] = "11111";
	map->map[1] = "10001";
	map->map[2] = "10001";
	map->map[3] = "1N001";
	map->map[4] = NULL;
	map->m_x = 4;
	map->m_y = 4;
	map->p.x = 1;
	map->p.y = 3;
	player_view(&window->map);
	set_distance(&map, window);
	mlx_loop(window->mlx);
}
