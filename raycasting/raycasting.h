/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:47:14 by houaslam          #+#    #+#             */
/*   Updated: 2023/07/14 14:13:21 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#ifndef RAYCASTING_H
#define RAYCASTING_H

#define PP_HEIGHT 200
#define PP_WIDTH 320
#define UNIT 64
#define VIEW_D 60
#define PLAYER_H 32
#define RAY_D VIEW_D/WIDTH
#define ALPHA 90 - (VIEW_D/2)
#define PP_DIST (PP_WIDTH/2) / tan(VIEW_D/2)
#define PI 3.141592654

typedef struct s_map{
	char	**map;
	int		alpha;
	int		p_x;
	int		p_y;
	int		pu_x;
	int		pu_y;
	int		c_hx;
	int		c_hy;
	int		d_hx;
	int		d_hy;
	struct s_window *window; 
}   t_map;

typedef struct s_window{
    void			*mlx;
    void			*mlx_win;
	struct s_map	*map;
}   t_window;

#endif