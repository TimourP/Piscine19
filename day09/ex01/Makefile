SRCS = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
OBJS = $(addprefix srcs/, ${SRCS:.c=.o})
CC = gcc
FLAGS = -Wall -Wextra -Werror

.o.c :
	${CC} ${FLAGS} -c ${SRCS} -o ${OBJS}

${libft.a} : ${OBJS}
	ar rs $@ ${OBJS}

all : ${libft.a}

clean:
	rm -f ${OBJS}

fclean : clean
	rm -f ${libft.a}

re : fclean all