/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:06:08 by houaslam          #+#    #+#             */
/*   Updated: 2023/07/27 10:42:53 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/raycasting.h"

void	render_wall(t_window *window, int pos)
{
	int	mid;
	int	i;

	mid = PP_HEIGHT / 2;
	i = mid - window->map->wall_h / 2;
	if (i < 0)
		i = 0;
	while (window->map->wall_h && i < PP_HEIGHT)
	{
		my_mlx_pixel_put(&window->map->img, pos \
		, i++, PINK);
		window->map->wall_h--;
	}
}
