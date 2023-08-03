# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/13 12:53:10 by houaslam          #+#    #+#              #
#    Updated: 2023/08/02 10:15:01 by houaslam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = cc 
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
EXTRA_FLAGS =  -g3  -lmlx -framework OpenGL -framework AppKit

R_SRCS = 	raycasting/distances.c \
			raycasting/raycasting.c \
	    	raycasting/player.c \
	    	raycasting/quadrant.c \
			main.c

REND_SRCS = rendering/render_setup.c \
	    	rendering/minimap.c \


P_SRCS = parsing/player_position.c \
		parsing/read_map.c \
		parsing/parsing.c \
		parsing/map_dimension.c \


O_SRCS = external_outils/get_next_line/get_next_line.c \
		 external_outils/get_next_line/get_next_line_utils.c

OBJ = ${R_SRCS:.c=.o} ${P_SRCS:.c=.o} ${REND_SRCS:.c=.o} ${O_SRCS:.c=.o}

all : ${NAME}

${NAME} : ${OBJ}
	${CC} ${CFLAGS} ${EXTRA_FLAGS} ${OBJ} external_outils/libft/libft.a -o ${NAME}

clean :
	rm ${OBJ}
fclean : clean
	rm -f ${NAME}

re : fclean all

push :
	git add .
	git commit -m cube
	git push
