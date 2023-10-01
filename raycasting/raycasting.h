/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadermou <fadermou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:47:14 by houaslam          #+#    #+#             */
/*   Updated: 2023/10/01 16:57:25 by fadermou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "../parsing/parsing.h"

//animation
int ft_animation(t_window *window);

//render
void					loads_textures(t_textures *txt);
void					draw_ray(t_window *window, int pos);

//raycasting

//player
int						which_move(int keycode, t_map *map);
void					player_view(t_map **map);
int						turn_move(int keycode, t_map *map);

//wallcast
float					wall_height(t_map *map);
void					find_wall(t_map *map);
void					rays_casting(t_map *map, t_window *window);
float					p_to_wall(t_map *map);
void					draw_wall(t_map *map, t_window *window);
int						check_case_h(t_map *map);
int						check_case_v(t_map *map);
void					check_angles(t_map *map);
void                    perform_animation(t_map *map);

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
int						ft_exit(t_window *mlx);

void					my_mlx_pixel_put(t_data *data, int x, int y, int color);
void					draw_player(t_map *map);
void					keep_adding(t_map *map);
void					mini_quadrant(t_map *map);

#endif