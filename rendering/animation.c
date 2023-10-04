/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:00:10 by houaslam          #+#    #+#             */
/*   Updated: 2023/10/04 16:35:54 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/raycasting.h"

void	animation_loop(int frame, int *weapon, int *dim, t_window *window)
{
	void	*img;
	char	*res;
	char	*which;

	img = NULL;
	if (frame == 700 * (*weapon))
	{
		mlx_clear_window(window->mlx, window->mlx_win);
		rays_casting(window->map, window);
		which = ft_itoa(*weapon);
		res = ft_strdup("textures/weapon_");
		res = ft_strjoin(res, which);
		res = ft_strjoin(res, ".xpm");
		img = mlx_xpm_file_to_image(window->mlx, res, &dim[1], &dim[0]);
		free(res);
		free(which);
		(*weapon)++;
		if (img)
			mlx_put_image_to_window(window->mlx, window->mlx_win, img, \
			PP_WIDTH / 2 - dim[1] / 2, PP_HEIGHT - dim[0]);
		free(img);
	}
}

int	perform_animation(t_window *window)
{
	int			dim[2];
	static int	frame;
	static int	weapon;

	dim[0] = 320;
	dim[1] = 498;
	frame %= 700 * 35;
	weapon %= 35;
	if (window->s_animation)
	{
		animation_loop(frame, &weapon, dim, window);
		if (weapon == 35)
		{
			rays_casting(window->map, window);
			window->s_animation = false;
		}
		frame++;
	}
	return (0);
}
