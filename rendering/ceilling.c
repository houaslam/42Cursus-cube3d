/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceilling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:10:31 by houaslam          #+#    #+#             */
/*   Updated: 2023/07/25 18:15:56 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/raycasting.h"

void	render_ceiling(t_window *window, int pos)
{
	int	i;
	int	ceiling;

	i = 0;
	ceiling = (PP_HEIGHT / 2) - (window->map->wall_h / 2);
	while (i <= ceiling)
		my_mlx_pixel_put(&window->map->img, pos, i++, YELLOW);
}
