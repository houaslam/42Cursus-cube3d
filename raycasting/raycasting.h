/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:47:14 by houaslam          #+#    #+#             */
/*   Updated: 2023/07/18 08:03:52 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# define PP_HEIGHT 1400
# define PP_WIDTH 3000
# define UNIT 64
# define VIEW_D 60
# define PLAYER_H 32
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

typedef struct s_map
{
	//map
	char				**map;
	int					m_x;
	int					m_y;
	// player
	int					p_x;
	int					p_y;
	int					pu_x;
	int					pu_y;
	// wall var
	int					p_to_w;
	int					wall_h;
	int					k;
	// render
	int					ceiling;
	t_ray				r;
	t_wall				h;
	t_wall				v;
	struct s_window		*window;
}	t_map;

typedef struct s_window{
	void				*mlx;
	void				*mlx_win;
	struct s_map		*map;
}	t_window;

//render
void					render_ceiling(t_window *window, int pos);
void					render_wall(t_window *window, int pos);
void					render_floor(t_window *window, int pos);
void					render_setup(t_window *window, int pos);
void					draw_ray(t_window *window, int pos);

//raycasting
void					setup(t_map **map);
void					horizental_inter(t_map **map);

//player
void					player_view(t_map **map);

//wallcast
int						wall_height(t_map *map);
void					find_wall(t_map *map);
void					set_distance(t_map *map, t_window *window);
int						p_to_wall(t_map *map);
void					draw_wall(t_map *map, t_window *window);

// quadrant
void					quadrant(t_map **map);
void					quadrant_1(t_map **map);
void					quadrant_2(t_map **map);
void					quadrant_3(t_map **map);
void					quadrant_4(t_map **map);

//external outil
int						check_case_h(t_map **map);
int						check_case_v(t_map **map);

#endif