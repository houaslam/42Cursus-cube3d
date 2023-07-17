/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:06:08 by houaslam          #+#    #+#             */
/*   Updated: 2023/07/17 13:13:41 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/raycasting.h"

void	render_wall(t_window *window, int pos)
{
	window->map->wall_h = wall_height(window->map);
	while (window->map->wall_h)
	{
		mlx_pixel_put(window->mlx, window->mlx_win, pos \
		, window->map->k--, PINK);
		window->map->wall_h--;
	}
}
