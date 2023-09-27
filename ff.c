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

// void	draw_ray(t_window *window, int pos)
// {
	// int		i;
// 	int		y;
// 	int		x;
// 	int		wall_h;
	// float	ceiling;
// 	uint32_t		color;
// 	uint32_t		*add;

	// i = 0;
// 	x = 0;
// 	add = malloc(sizeof(uint32_t) * (uint32_t)PP_WIDTH * (uint32_t)PP_HEIGHT);
// 	while (x < UNIT)
// 	{
// 		y = 0;
// 		while (y < UNIT)
// 		{
// 			if (x % 8 && y % 8)
// 				add[(UNIT * y) + x] = 0XFF0000FF;
// 			else
// 				add[(UNIT * y) + x] = 0XFF000000;
// 			y++;
// 		}
// 		x++;
// 	}
// 	int		text_offset_y;
// 	int		text_offset_x;
// 	float		wallstripheight = (int)window->map->wall_h;
// 	int			walltopixel = (PP_HEIGHT / 2) - (wallstripheight / 2);
// 	int			bottompixel = (PP_HEIGHT / 2) + (wallstripheight / 2);
// 	i = 0;
	// ceiling = (PP_HEIGHT / 2) - (window->map->wall_h / 2);
	// if (ceiling > 0 && ceiling < PP_HEIGHT)
	// {
	// 	while (i <= ceiling && ceiling > 0)
	// 		my_mlx_pixel_put(&window->map->img, pos, i++, YELLOW);
	// }
// 	// if (window->map->r.content == DOOR)
// 	// 	color = BLACK;
// 	// if (window->map->r.content == WALL)
// 	// 	color = PINK;
// 	wall_h = window->map->wall_h;
// 	(void)wall_h;
// 	if (window->map->vert == true)
// 		text_offset_x = (int)(window->map->v.y) % UNIT;//// check unit after
// 	else
// 		text_offset_x = (int)(window->map->h.x) % UNIT;
// 	y = 0;
// 	// while (window->map->wall_h >= 0 && i < PP_HEIGHT)
// 	while(y < bottompixel)
// 	{
// 		text_offset_y = (y - walltopixel) * ((float)UNIT / wallstripheight);
// 		color = window->map->textures[0].add[(PP_WIDTH * text_offset_y) + text_offset_x];
// 		// text_offset_y = (window->map->wall_h - wall_h);
// 		// float normalized_y = (float)(wall_h - window->map->wall_h) / wall_h;  // divided by wall_height
// 		// text_offset_y = normalized_y * (window->map->textures[0].h);
// 		// // text_offset_y = (window->map->wall_h - wall_h) * (window->map->textures[0].h / 200);////WHAT'S 200?
// 		// // color = window->map->textures[0].add[(window->map->textures[0].w * text_offset_y) + text_offset_x];
// 		// color = add[(window->map->textures[0].w * text_offset_y) + text_offset_x];
// 		my_mlx_pixel_put(&window->map->img, pos, y++, color);
// 		y++;
// 		window->map->wall_h--;
// 	}
// 	// (void)text_offset_x;
// 	while (i < PP_HEIGHT)
// 		my_mlx_pixel_put(&window->map->img, pos, i++, PURPLE);
// }

void	draw_ray(t_window *window, int pos)
{
	int	wallstripheight;
	int	walltoppixel;
	int	wallbottompixel;
	int	textureoffsetx;
	int	textureoffsety;
	uint32_t	color;
	int	y;

	wallstripheight = (int)window->map->wall_h;
	walltoppixel = (PP_HEIGHT / 2) - (wallstripheight / 2);
	// walltoppixel = walltoppixel < 0 ? 0 : wall_height;
	wallbottompixel  = (PP_HEIGHT / 2) + (wallstripheight / 2);
	// wallbottompixel = wallbottompixel > PP_HEIGHT ? PP_HEIGHT : wallbottompixel;
	y = 0;
	if (walltoppixel > 0 && walltoppixel < PP_HEIGHT)
	// {
		while (y < walltoppixel)
		{
			my_mlx_pixel_put(&window->map->img, pos, y++, 0xFF333333);
			y++;
		}
	// }
	if (window->map->vert == true)
		textureoffsetx = (int)(window->map->h.y) % UNIT;////check v.x in both and the opposite too
	else
		textureoffsetx = (int)(window->map->h.x) % UNIT;
	// y = walltoppixel;
	while (window->map->wall_h >= 0 && y < wallbottompixel)
	{
		textureoffsety = (y - walltoppixel) * ((float)window->map->textures[0].h / wallstripheight);
		color = window->map->textures[0].add[(window->map->textures[0].w * textureoffsety) + textureoffsetx];
		my_mlx_pixel_put(&window->map->img, pos, y++, color);
		y++;
		window->map->wall_h--;
	}

	while (y < PP_HEIGHT)
	{
		my_mlx_pixel_put(&window->map->img, pos, y++, 0xFF777777);
		y++;
	}
	// (void)walltoppixel;
	// (void)wallstripheight;
	// (void)wallbottompixel;
	

}