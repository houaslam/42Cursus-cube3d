/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:09:17 by houaslam          #+#    #+#             */
/*   Updated: 2023/07/17 13:15:39 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/raycasting.h"

void	draw_ray(t_window *window, int pos)
{
	// render_ceiling(window, pos);
	render_floor(window, pos);
	// render_wall(window, pos);
}
