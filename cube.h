/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:29:31 by houaslam          #+#    #+#             */
/*   Updated: 2023/07/23 11:25:59 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# define PP_HEIGHT 500
# define PP_WIDTH 800
# define UNIT 320
# define VIEW_D 60
# define PURPLE 0x581845 //floor
# define PINK 0xC70039 //wall
# define YELLOW 0xFFC300 //ceiling
# define BLACK 0x000000 //ceiling

typedef struct s_wall
{
	int					cx;
	int					cy;
	int					dx;
	int					dy;
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
}	t_player;

typedef struct s_map
{
	//map
	char				**map;
	int					m_x;
	int					m_y;
	// wall var
	int					p_to_w;
	int					wall_h;
	int					k;
	int					saveit;
	int					n_v;
	int					n_h;
	// render
	int					ceiling;
	t_ray				r;
	t_wall				h;
	t_wall				v;
	t_player			p;
	struct s_window		*window;
}	t_map;

typedef struct s_window{
	void				*mlx;
	void				*mlx_win;
	struct s_map		*map;
}	t_window;

#endif