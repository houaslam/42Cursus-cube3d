# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/13 12:53:10 by houaslam          #+#    #+#              #
#    Updated: 2023/07/14 18:48:52 by houaslam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cube
CC = cc 
CFLAGS = -Wall -Wextra -Werror
EXTRA_FLAGS = -fsanitize=address -Lmlx -lmlx -framework OpenGL -framework AppKit

SRCS = raycasting/main.c

OBJ = ${SRCS:.cpp=.o}

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
