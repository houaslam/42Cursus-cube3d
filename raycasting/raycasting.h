/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:47:14 by houaslam          #+#    #+#             */
/*   Updated: 2023/08/04 07:44:15 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "../parsing/parsing.h"

//render
void					render_ceiling(t_window *window, int pos);
void					render_wall(t_window *window, int pos);
void					render_floor(t_window *window, int pos);
void					render_setup(t_window *window, int pos);
void					draw_ray(t_window *window, int pos);

//raycasting
// void					setup(t_map **map);

//player
void					player_view(t_map **map);

//wallcast
float					wall_height(t_map *map);
void					find_wall(t_map *map);
void					rays_casting(t_map *map, t_window *window);
float					p_to_wall(t_map *map);
void					draw_wall(t_map *map, t_window *window);
int						check_case_h(t_map *map);
int						check_case_v(t_map *map);
void					check_angles(t_map *map);

// quadrant
void					quadrant(t_map *map);
void					up_left(t_map *map);
void					up_right(t_map *map);
void					down_right(t_map *map);
void					down_left(t_map *map);

//inimap
void					draw_minimap(t_map *map);
void					draw_square(int color, int x, int y, t_window *window);
//player mov
int						which_move(int keycode, t_map *map);
int						ft_exit(t_window *mlx);
int						turn_move(int keycode, t_map *map);

void					my_mlx_pixel_put(t_data *data, int x, int y, int color);
void					draw_player(t_map *map);
void					keep_adding(t_map *map);
void					mini_quadrant(t_map *map);

#endif