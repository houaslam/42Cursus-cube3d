/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 18:48:02 by houaslam          #+#    #+#             */
/*   Updated: 2023/07/14 18:48:28 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	find_wall(t_map *map)
{
    map->pu_x = map->p_x * UNIT + (UNIT / 2);
    map->pu_y = map->p_y * UNIT + (UNIT / 2);
    
    map->c_hy = ((map->pu_y / UNIT) * UNIT) - 1;
    map->c_hx = ((map->pu_y - map->c_hy) / tan(60 * M_PI/180)) + map->pu_x;
    
    map->d_hx = UNIT/tan(60 * M_PI/180);
    map->d_hy = -UNIT;
    
    printf("cy = %d\n", map->c_hy);
    printf("cx = %d\n", map->c_hx);
    while(map->c_hx / 64 < 3 && map->c_hy / 64 < 4 && map->map[map->c_hx / 64][map->c_hy / 64] != '1')
    {
        map->c_hx += map->d_hx;
        map->c_hy += map->d_hy;
    }
    printf("AFTER cx = %d\n", map->c_hx / 64);
    printf("AFTER cy = %d\n", map->c_hy/64);

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
    window->mlx = mlx_init();
    map->p_x = 1;
    map->p_y = 3;
    find_wall(window->map);
    window->mlx_win =  mlx_new_window(window->mlx, 1920, 1080, "Cube");
    mlx_loop(window->mlx);
}