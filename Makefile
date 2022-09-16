# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sokhacha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/08 16:37:27 by sokhacha          #+#    #+#              #
#    Updated: 2022/09/08 17:28:06 by sokhacha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = 
SERVER = server
CLIENT = client
SRC_S = server.c
SRC_C = client.c
OBJ_S = $(patsubst %.c, %.o, $(SRC_S))
OBJ_C = $(patsubst %.c, %.o, $(SRC_C))

CC = cc

FLAGS = -Wall -Werror -Wextra

RM = rm -f

%.o: %.c
	${CC} ${FLAGS} -c $< -o $@

all: ${SERVER} ${CLIENT}

${SERVER}: ${OBJ_S}
	${CC} ${CFLAGS} -o ${SERVER} ${OBJ_S}

${CLIENT}: ${OBJ_C}
	${CC} ${FLAGS} -o ${CLIENT} ${OBJ_C}

clean:
	${RM} ${OBJ_S} ${OBJ_C}

fclean:clean
	${RM} ${SERVER} ${CLIENT}

re: fclean all

.PHONY: all clean fclean re

