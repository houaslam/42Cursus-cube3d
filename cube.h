/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:29:31 by houaslam          #+#    #+#             */
/*   Updated: 2023/07/19 11:42:39 by houaslam         ###   ########.fr       */
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
# define UNIT 320
# define VIEW_D 60
# define PLAYER_H 320
# define PURPLE 0x581845 //floor
# define PINK 0xC70039 //wall
# define YELLOW 0xFFC300 //ceiling

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
	int					up;
	int					down;
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
	int					its_v;
	int					its_h;
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