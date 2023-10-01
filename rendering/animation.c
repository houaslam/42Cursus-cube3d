/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadermou <fadermou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:00:10 by houaslam          #+#    #+#             */
/*   Updated: 2023/10/01 17:28:20 by fadermou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/raycasting.h"

int ft_animation(t_window *window)
{
    static int	frame;
	void *img;
	int	h;
	int	w;

	h = 64;
	w = 64;
	img = NULL;
	if (frame == 50000)
		img = mlx_xpm_file_to_image(window->mlx, "textures/knife1.xpm", &w, &h);
	if (frame == 100000)
		img = mlx_xpm_file_to_image(window->mlx, "textures/knife2.xpm", &w, &h);
	if (frame == 150000)
	{
		img = mlx_xpm_file_to_image(window->mlx, "textures/knife3.xpm", &w, &h);
		frame = 0;
	}
	h = PP_HEIGHT - 100;
	w = PP_WIDTH / 2;
	if (img)
		mlx_put_image_to_window(window->mlx, window->mlx_win, img,w, h);
	frame++;
	free(img);
	return(0);
}
