/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:00:10 by houaslam          #+#    #+#             */
/*   Updated: 2023/10/02 13:22:52 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/raycasting.h"

int perform_animation(t_window *window)
{
    static int	frame;
	void *img;
	int	h;
	int	w;

	h = 64;
	w = 64;
	img = NULL;
	frame %= 200001;
	if (window->DO_ANIMATION)
	{
		if (frame == 50000)
			img = mlx_xpm_file_to_image(window->mlx, "textures/knife1.xpm", &w, &h);
		else if (frame == 100000)
			img = mlx_xpm_file_to_image(window->mlx, "textures/knife2.xpm", &w, &h);
		else if (frame == 150000)
			img = mlx_xpm_file_to_image(window->mlx, "textures/knife3.xpm", &w, &h);
		else if (frame == 200000)
		{
			img = mlx_xpm_file_to_image(window->mlx, "textures/knife1.xpm", &w, &h);
			window->DO_ANIMATION = false;
		}
		frame++;
		if (img)
		{
			w = PP_WIDTH / 2;
			h = PP_HEIGHT - 100;
			mlx_put_image_to_window(window->mlx, window->mlx_win, img,w, h);
		}
		free(img);
	}
	return(0);
}
