/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:57:23 by fadermou          #+#    #+#             */
/*   Updated: 2023/07/30 07:36:24 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <string.h>
# include "../cube.h"
# include "../external_outils/libft/libft.h"
# include "../external_outils/get_next_line/get_next_line.h"

void	player_position(t_map **map, int i);
void    parsing(t_map *map, char **av);
void    map_dimension(t_map **map, int i);
void	read_map(t_map **map, char **av);
void	cardinal_directions(t_map **map, int *s);
void    map_parsing(t_map **map);
void	ea_and_colors(char **str, t_directions *dir, int *s, int i);
int     ft_is_space(char c);
void	check_cardinal(t_directions *dir);
//      TOOLS
void	put_error(char *str);
int	    str_lenght(char **str);
void	ft_free(char **str);

#endif
