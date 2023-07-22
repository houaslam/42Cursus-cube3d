/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceilling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:10:31 by houaslam          #+#    #+#             */
/*   Updated: 2023/07/22 08:42:38 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/raycasting.h"

void	render_ceiling(t_window *window, int pos)
{
	int	i;

	i = 0;
	window->map->ceiling = (PP_HEIGHT / 2) - (window->map->wall_h / 2);
	while (i <= window->map->ceiling)
		mlx_pixel_put(window->mlx, window->mlx_win, pos, i++, YELLOW);
}
