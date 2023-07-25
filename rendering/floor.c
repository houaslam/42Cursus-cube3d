/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:06:40 by houaslam          #+#    #+#             */
/*   Updated: 2023/07/25 17:45:44 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/raycasting.h"

void	render_floor(t_window *window, int pos)
{
	int	i;

	i = PP_HEIGHT / 2;
	while (i < PP_HEIGHT)
		my_mlx_pixel_put(&window->map->img, pos, i++, PURPLE);
}
