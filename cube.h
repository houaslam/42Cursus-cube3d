/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:29:31 by houaslam          #+#    #+#             */
/*   Updated: 2023/07/25 13:35:01 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# define PP_HEIGHT 1000
# define PP_WIDTH 1600
# define UNIT 64
# define VIEW_D 60
# define PURPLE 0x581845 //floor
# define PINK 0xC70039 //wall
# define YELLOW 0xFFC300 //ceiling
# define BLACK 0x000000 //ceiling


enum {
	ARROW_LEFT = 123,
	ARROW_RIGHT = 124,
	UP = 13,
	LEFT = 0,
	DOWN = 1,
	RIGHT = 2,
	DESTROY = 17,
	SPEED = 10
};

typedef struct s_minimap
{
	int					px;
	int					py;
}	t_minimap;

typedef struct s_wall
{
	double					x;
	double					y;
	double					step_x;
	double					step_y;
}	t_wall;

typedef struct s_ray
{
	float				alpha;
	float				ang;
	float				cast;
	int					left;
	int					right;
}	t_ray;

typedef struct s_player
{
	int					x;
	int					y;
	int					u_x;
	int					u_y;
	int					rot_speed;
	int					mov_speed;
	int					to_w;
}	t_player;

typedef struct s_map
{
	//map
	char				**map;
	int					m_x;
	int					m_y;
	// wall var
	int					wall_h;
	int					n_v;
	int					n_h;
	// render
	t_ray				r;
	t_wall				h;
	t_wall				v;
	t_player			p;
	t_minimap			minimap;
	struct s_window		*window;
}	t_map;

typedef struct s_window{
	void				*mlx;
	void				*mlx_win;
	struct s_map		*map;
}	t_window;

#endif