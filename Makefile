# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/13 12:53:10 by houaslam          #+#    #+#              #
#    Updated: 2023/07/18 13:28:11 by houaslam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cube
CC = cc 
CFLAGS = -Wall -Wextra -Werror
EXTRA_FLAGS = -fsanitize=address -g3 -Lmlx -lmlx -framework OpenGL -framework AppKit

SRCS = 	raycasting/distances.c \
		raycasting/raycasting.c \
	    raycasting/player.c \
	    raycasting/quadrant.c \
	    raycasting/external_outil.c \
		rendering/wall.c \
		rendering/floor.c \
		rendering/ceilling.c \
		rendering/render_setup.c \
		raycasting/view.c \

OBJ = ${SRCS:.c=.o}

all : ${NAME}

${NAME} : ${OBJ}
	${CC} ${CFLAGS} ${EXTRA_FLAGS} ${OBJ} -o ${NAME}

clean :
	rm ${OBJ}
fclean : clean
	rm -f ${NAME}

re : fclean all

push :
	git add .
	git commit -m cube
	git push
