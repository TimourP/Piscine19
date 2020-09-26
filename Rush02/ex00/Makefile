SRCS = main.c ft_putstr.c ft_strlen.c ft_atoi.c write_number.c write_functions.c
OBJS = ${SRCS:.c=.o}
CC = gcc
FLAGS = -Wall -Wextra -Werror
PROG = rush-02

all : ${PROG}

allup : all clean

${PROG} : ${OBJS}
	${CC} ${FLAGS} $^ -o $@

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

clean:
	rm -f ${OBJS}

fclean : clean
	rm -f ${PROG}

re : fclean all

.PHONY : all clean fclean re