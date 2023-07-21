/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookair <macbookair@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:31:12 by houaslam          #+#    #+#             */
/*   Updated: 2023/07/21 18:12:25 by macbookair       ###   ########.fr       */
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
	set_distance(&map, window);
	mlx_loop(window->mlx);
}
