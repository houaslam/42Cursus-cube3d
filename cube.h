/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajarouaslam <hajarouaslam@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:29:31 by houaslam          #+#    #+#             */
/*   Updated: 2023/09/24 15:05:45 by hajarouasla      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
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
# define NO 0
# define SO 1
# define WE 2
# define EA 3

enum {
	ARROW_LEFT = 65361,
	ARROW_UP = 65362,
	ARROW_RIGHT = 65363,
	ARROW_DOWN = 65364,
	LEFT = 97,
	UP = 119,
	RIGHT = 100,
	DOWN = 115,
	DESTROY = 65307,
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
	void				*player;
	float				x;
	float				y;
	t_player			mini_p;
}	t_minimap;

typedef struct s_map
{
	char				**map;
	int					m_x;
	int					m_y;
	bool				is_v;
	float				wall_h;
	t_ray				r;
	t_wall				h;
	t_wall				v;
	t_player			p;
	t_minimap			minimap;
	t_data				img;
	t_data				mini;
	struct s_directions *directions;
	struct s_textures *textures;
	struct s_window		*window;
}	t_map;

typedef struct s_textures
{
	void			*img;
	char			*addr;
	int				h;
	int				w;
    int  			*add;
    int  			bits_per_pixel;
    int  			line_length;
    int  			endian;
	struct s_map	*map;
}	t_textures;

typedef struct s_directions
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	int				f;
	int				c;
	struct s_map	*map;
}	t_directions;

typedef struct s_window{
	void				*mlx;
	void				*mlx_win;
	struct s_map		*map;
}	t_window;

#endif