# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/13 12:53:10 by houaslam          #+#    #+#              #
#    Updated: 2023/08/23 18:56:42 by houaslam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = cc 
cc += -fsanitize=address -g3
CFLAGS = -I/usr/include -Imlx_linux -O3
EXTRA_FLAGS =  -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz 

R_SRCS = 	raycasting/distances.c \
			raycasting/raycasting.c \
	    	raycasting/player.c \
	    	raycasting/quadrant.c \
			main.c

REND_SRCS = rendering/render_setup.c \
	    	rendering/minimap.c \
	    	rendering/mini_quadrant.c \


P_SRCS = parsing/player_position.c \
		parsing/read_map.c \
		parsing/parsing.c \
		parsing/map_dimension.c \
		cardinal_directions.c


O_SRCS = external_outils/get_next_line/get_next_line.c \
		 external_outils/get_next_line/get_next_line_utils.c

OBJ = ${R_SRCS:.c=.o} ${P_SRCS:.c=.o} ${REND_SRCS:.c=.o} ${O_SRCS:.c=.o}

all : ${NAME}

${NAME} : ${OBJ}
	${CC} ${CFLAGS} ${EXTRA_FLAGS} ${OBJ} ${EXTRA_FLAGS} external_outils/libft/libft.a -o ${NAME}

clean :
	rm -rf ${OBJ}
fclean : clean
	rm -rf ${NAME}

re : fclean all

push :
	git add .
	git commit -m cube
	git push
