SRCS = main.c ft_putstr.c ft_open_file.c ft_rewrite_userinput.c ft_strcmp.c ft_puterr.c
OBJS = ${SRCS:.c=.o}
CC = gcc
FLAGS = -Wall -Wextra -Werror
PROG = ft_cat

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