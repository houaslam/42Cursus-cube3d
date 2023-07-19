/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:57:23 by fadermou          #+#    #+#             */
/*   Updated: 2023/07/19 13:53:09 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

#include <string.h>
# include "../cube.h"
// # include "get_next_line/get_next_line.h"/

void	player_position(t_map **map);
void parsing(t_map **map, char **av);

#endif