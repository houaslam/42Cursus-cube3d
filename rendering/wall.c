/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:06:08 by houaslam          #+#    #+#             */
/*   Updated: 2023/07/21 12:49:42 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/raycasting.h"

void	render_wall(t_window *window, int pos)
{
	int mid;
	int	i;

	mid = PP_HEIGHT / 2;
	i = mid - window->map->wall_h / 2;
	// window->map->wall_h = wall_height(window->map);
	while (window->map->wall_h)
	{
		mlx_pixel_put(window->mlx, window->mlx_win, pos \
		, i++, PINK);
		window->map->wall_h--;
	}
}
