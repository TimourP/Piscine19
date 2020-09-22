SRCS = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
OBJS = $(addprefix srcs/, ${SRCS:.c=.o})
CC = gcc
FLAGS = -Wall -Wextra -Werror
LNAME = libft.a

.o.c :
	${CC} ${FLAGS} -c ${SRCS} -o ${OBJS}

${LNAME} : ${OBJS}
	ar rs $@ ${OBJS}

all : ${LNAME}

clean:
	rm -f ${OBJS}

fclean : clean
	rm -f ${LNAME}

re : fclean all