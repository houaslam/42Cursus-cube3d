/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookair <macbookair@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:57:23 by fadermou          #+#    #+#             */
/*   Updated: 2023/07/25 13:03:19 by macbookair       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <string.h>
# include "../cube.h"
# include "../external_outils/libft/libft.h"
# include "../external_outils/get_next_line/get_next_line.h"

void	player_position(t_map **map);
void    parsing(t_map **map, char **av);
void    map_dimension(t_map **map);
void	read_map(t_map **map, char **av);
void    wall_parsing(t_map *map);
void	flood_fill(char **map, int yp, int xp);
char	**make_area(t_map *map);

#endif
