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
// 	int		i;
// 	int		wall_h;
// 	float	ceiling;
// 	int		color;

// 	int		text_offset_y;
// 	int		text_offset_x;
// 	i = 0;
// 	ceiling = (PP_HEIGHT / 2) - (window->map->wall_h / 2);
// 	if (ceiling > 0 && ceiling < PP_HEIGHT)
// 	{
// 		while (i <= ceiling && ceiling > 0)
// 			my_mlx_pixel_put(&window->map->img, pos, i++, YELLOW);
// 	}
// 	if (window->map->r.content == DOOR)
// 		color = BLACK;
// 	if (window->map->r.content == WALL)
// 		color = PINK;
// 	wall_h = window->map->wall_h;
// 	if (window->map->vert == true)
// 		text_offset_x = (int)(window->map->v.y) % UNIT;
// 	else
// 		text_offset_x = (int)(window->map->h.x) % UNIT;
// 	while (window->map->wall_h >= 0 && i < PP_HEIGHT)
// 	{
// 		float normalized_y = (float)(wall_h - window->map->wall_h) / wall_h;  // divided by wall_height
// 		text_offset_y = normalized_y * (window->map->textures[0].h);
// 		color = window->map->textures[0].add[(window->map->textures[0].w * text_offset_y) + text_offset_x];
// 		my_mlx_pixel_put(&window->map->img, pos, i++, color);
// 		window->map->wall_h--;
// 	}
// 	while (i < PP_HEIGHT)
// 		my_mlx_pixel_put(&window->map->img, pos, i++, PURPLE);
// }


////CHARG
void	draw_ray(t_window *window, int pos)
{
	int		i;
	// int		dir;
	// int		*addb;
	int		y;
	int		x;
	int		wall_h;
	float	ceiling;
	int		color;
	int		text_offset_y;
	int		text_offset_x;
	// float		wallstripheight = (int)window->map->wall_h;
	// int			walltopixel = (PP_HEIGHT / 2) - (wallstripheight / 2);
	// int			bottompixel = (PP_HEIGHT / 2) + (wallstripheight / 2);
	
	x = 0;
	while (x < 64)
	{
		y = 0;
		while (y < 64)
		{
			if (x % 8 && y % 8)
				addb[(64 * y) + x] = 0xFF0000FF;
			else
				addb[(64 * y) + x] = 0xFF000000;
			y++;
		}
		x++;
	}
	// if (((int)window->map->r.cast % 360 >= 0 && (int)window->map->r.cast % 360 < 45) || (((int)window->map->r.cast % 360) >= 315 && (int)window->map->r.cast % 360 < 360))
	// 	dir = EA;
	// else if (((int)window->map->r.cast % 360 >= 45 && (int)window->map->r.cast % 360 < 135))
	// 	dir = NO;
	// else if (((int)window->map->r.cast % 360 >= 135 && (int)window->map->r.cast % 360 < 225))
	// 	dir = WE;
	// else
	// 	dir = SO;
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
	// (void)wall_h;
	if (window->map->vert == true)
	{
		text_offset_x = (int)(window->map->v.y) % window->map->textures[0].h;//// check unit after
		// dir = NO;
	}
	else
	{
		text_offset_x = (int)(window->map->h.x) % window->map->textures[0].w;
		// dir = WE;
	}
	while (window->map->wall_h >= 0 && i < PP_HEIGHT)
	{
		// //1// text_offset_y = normalized_y * (window->map->textures[0].h);
		// //1// textureoffsety = (y - walltoppixel) * ((double)window->map->textures[0].h / wallstripheight);
		// //1// color = window->map->textures[0].add[(window->map->textures[0].w * textureoffsety) + textureoffsetx];
		// float normalized_y = (float)(wall_h - window->map->wall_h) / wall_h;
		// text_offset_y = normalized_y * (window->map->textures[dir].h);
		int distanceFromTop = i + (wall_h / 2) - (PP_HEIGHT / 2);
        text_offset_y = distanceFromTop * ((float)window->map->textures[0].h / wall_h);
		color = addb[(window->map->textures[0].w * text_offset_y) + text_offset_x];
		my_mlx_pixel_put(&window->map->img, pos, i++, color);
		window->map->wall_h--;
	}
	while (i < PP_HEIGHT)
		my_mlx_pixel_put(&window->map->img, pos, i++, PURPLE);
}


////KHONA
void	draw_ray1(t_window *window, int pos)
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
	// if (walltoppixel > 0 && walltoppixel < PP_HEIGHT)
	// {
		while (y < walltoppixel)
		{
			my_mlx_pixel_put(&window->map->img, pos, y++, 0xFF333333);
			y++;
		}
	// }
	if (window->map->vert == true)
		textureoffsetx = (int)(window->map->v.y) % window->map->textures[0].h ;////check v.x in both and the opposite too
	else
		textureoffsetx = (int)(window->map->h.x) % window->map->textures[0].h ;
	// y = walltoppixel;
	while (window->map->wall_h >= 0 && y < wallbottompixel)
	{
		textureoffsety = (y - walltoppixel) * ((double)window->map->textures[0].h / wallstripheight);
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

////KHONA V2
void	draw_ray2(t_window *window, int pos)
{
        int wallStripHeight = (int)window->map->wall_h;

        int wallTopPixel = (PP_HEIGHT / 2) - (wallStripHeight / 2);
        wallTopPixel = wallTopPixel < 0 ? 0 : wallTopPixel;

        int wallBottomPixel = (PP_HEIGHT / 2) + (wallStripHeight / 2);
        wallBottomPixel = wallBottomPixel > PP_HEIGHT ? PP_HEIGHT : wallBottomPixel;

        // set the color of the ceiling
        for (int y = 0; y < wallTopPixel; y++)
			my_mlx_pixel_put(&window->map->img, pos, y++, 0xFF333333);
            // colorBuffer[(PP_WIDTH * y) + i] = 0xFF333333;


        // calculate texture offset X
        int textureOffsetX;
        if (window->map->vert == true)
            textureOffsetX = (int)(window->map->v.y) % window->map->textures[0].h;
        else
            textureOffsetX = (int)(window->map->h.x)% window->map->textures[0].w;

        // render the wall from wallTopPixel to wallBottomPixel
        for (int y = wallTopPixel; y < wallBottomPixel; y++) {
            // calculate texture offset Y
            int distanceFromTop = y + (wallStripHeight / 2) - (PP_HEIGHT / 2);
            int textureOffsetY = distanceFromTop * ((float)window->map->textures[0].h / wallStripHeight);

            // set the color of the wall based on the color from the texture
            int texelColor = window->map->textures[0].add[(window->map->textures[0].w * textureOffsetY) + textureOffsetX];
			my_mlx_pixel_put(&window->map->img, pos, y++, texelColor);
            // colorBuffer[(PP_WIDTH * y) + i] = texelColor;

        }

        // set the color of the floor
        for (int y = wallBottomPixel; y < PP_HEIGHT; y++)
			my_mlx_pixel_put(&window->map->img, pos, y++, 0xFF777777);
            // colorBuffer[(PP_WIDTH * y) + i] = 0xFF777777;

}