/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:09:17 by houaslam          #+#    #+#             */
/*   Updated: 2023/07/30 08:59:05 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/raycasting.h"
#include <inttypes.h>
#include <stdint.h>
// #include 
// #include 
void	 my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_ray(t_window *window, int pos)
{
	int		i;
	// int		x;
	int		wall_h;
	float	ceiling;
	int		color;

	int		text_offset_y;
	int		text_offset_x;
	// float		wallstripheight = (int)window->map->wall_h;
	// int			walltopixel = (PP_HEIGHT / 2) - (wallstripheight / 2);
	// int			bottompixel = (PP_HEIGHT / 2) + (wallstripheight / 2);
	i = 0;
	ceiling = (PP_HEIGHT / 2) - (window->map->wall_h / 2);
	if (ceiling > 0 && ceiling < PP_HEIGHT)
	{
		while (i <= ceiling && ceiling > 0)
			my_mlx_pixel_put(&window->map->img, pos, i++, YELLOW);
	}
	// if (window->map->r.content == DOOR)
	// 	color = BLACK;
	// if (window->map->r.content == WALL)
	// 	color = PINK;
	wall_h = window->map->wall_h;
	(void)wall_h;
	if (window->map->vert == true)
		text_offset_x = (int)(window->map->v.y) % UNIT;//// check unit after
	else
		text_offset_x = (int)(window->map->h.x) % UNIT;
	while (window->map->wall_h >= 0 && i < PP_HEIGHT)
	// while(y < bottompixel)
	{
		// text_offset_y = (y - walltopixel) * ((float)UNIT / wallstripheight);
		// color = window->map->textures[0].add[(PP_WIDTH * text_offset_y) + text_offset_x];
		// text_offset_y = (window->map->wall_h - wall_h);
		float normalized_y = (float)(wall_h - window->map->wall_h) / (float)wall_h;  // divided by wall_height
		text_offset_y = normalized_y * (window->map->textures[0].h);
		// // text_offset_y = (window->map->wall_h - wall_h) * (window->map->textures[0].h / 200);////WHAT'S 200?
		color = window->map->textures[0].add[(window->map->textures[0].w * text_offset_y) + text_offset_x];
		// color = add[(window->map->textures[0].w * text_offset_y) + text_offset_x];
		my_mlx_pixel_put(&window->map->img, pos, i++, color);
		window->map->wall_h--;
	}
	// (void)text_offset_x;
	while (i < PP_HEIGHT)
		my_mlx_pixel_put(&window->map->img, pos, i++, PURPLE);
}
