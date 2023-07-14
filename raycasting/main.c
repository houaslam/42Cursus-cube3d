/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MAIN.C                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:06:46 by houaslam          #+#    #+#             */
/*   Updated: 2023/07/14 16:57:02 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	find_wall(t_map *map)
{
    map->p_x = 2;
    map->p_y = 3;
    
    map->pu_x = map->p_x * UNIT + (UNIT / 2);
    map->pu_y = map->p_y * UNIT + (UNIT / 2);
    
    map->c_hy = ((map->pu_y / UNIT) * UNIT) - 1;
    map->c_hx = (( map->p_y - map->c_hy) / tan(60)) + map->p_x;
    
    map->d_hx = UNIT/tan(ALPHA);
    map->d_hy = -UNIT;
    
    printf("cy = %d\n", map->c_hy);
    printf("cx = %d\n", map->c_hx);
    // printf("dx = %d\n", map->d_hx);
    // while(map->c_hx / 64 < 6 && map->c_hy / 64 < 8 && map->map[map->c_hx / 64][map->c_hy / 64] != '1')
    //     map->c_hx += map->d_hx;
    // printf("AFTER cx = %d\n", map->c_hx / 64);
}


int main(int ac, char **av)
{
    t_window *window;
    t_map *map;
    
    (void)av;
    (void)ac;
	window = malloc(sizeof(t_window));
	map = malloc(sizeof(t_map));
    window->map = map;
    map->map = malloc(sizeof(char *) * 5);
    map->map[0] = "1111";
    map->map[1] = "1000";
    map->map[2] = "1000";
    map->map[3] = "1P00";
    map->map[4] = NULL;
    // window->mlx = mlx_init();
    find_wall(window->map);
    // window->mlx_win =  mlx_new_window(window->mlx, 1920, 1080, "Cube");
    // mlx_loop(window->mlx);
}