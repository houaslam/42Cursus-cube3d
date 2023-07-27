/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceilling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:10:31 by houaslam          #+#    #+#             */
/*   Updated: 2023/07/27 10:49:29 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/raycasting.h"

void	render_ceiling(t_window *window, int pos)
{
	int	i;
	int	ceiling;

	i = 0;
	ceiling = (PP_HEIGHT / 2) - (window->map->wall_h / 2);
	if (ceiling > 0)
	{
		while (i <= ceiling && ceiling > 0)
			my_mlx_pixel_put(&window->map->img, pos, i++, YELLOW);
	}
	while (window->map->wall_h && i < PP_HEIGHT)
	{
		my_mlx_pixel_put(&window->map->img, pos \
		, i++, PINK);
		window->map->wall_h--;
	}
	while (i < PP_HEIGHT)
		my_mlx_pixel_put(&window->map->img, pos, i++, PURPLE);
}
