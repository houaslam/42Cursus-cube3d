/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:29:31 by houaslam          #+#    #+#             */
/*   Updated: 2023/08/04 07:41:17 by houaslam         ###   ########.fr       */
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
# define PURPLE 0x9facb7
# define PINK 0x00406c
# define YELLOW 0xfafefd
# define BLACK 0x000000

enum {
	ARROW_LEFT = 123,
	ARROW_RIGHT = 124,
	ARROW_UP = 126,
	ARROW_DOWN = 125,
	UP = 13,
	LEFT = 0,
	DOWN = 1,
	RIGHT = 2,
	DESTROY = 17,
	SPEED = 30,
	MINI_UNIT = 15,
	DOOR = 111,
	WALL = 222
};

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

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
	double				distance;
	int					up;
	int					down;
	int					right;
	int					left;
	int					content;
}	t_ray;

typedef struct s_player
{
	double					x;
	double					y;
	double					u_x;
	double					u_y;
	int						rot_speed;
	int						mov_speed;
}	t_player;

typedef struct s_minimap
{
	int					height;
	int					width;
	t_player			mini_p;
	void				*player;
	float				x;
	float				y;
}	t_minimap;

typedef struct s_map
{
	char				**map;
	int					m_x;
	int					m_y;
	int					n_v;
	int					n_h;
	float				wall_h;
	t_ray				r;
	t_wall				h;
	t_wall				v;
	t_player			p;
	t_minimap			minimap;
	t_data				img;
	t_data				mini;
	struct s_window		*window;
}	t_map;

typedef struct s_window{
	void				*mlx;
	void				*mlx_win;
	struct s_map		*map;
}	t_window;

#endif