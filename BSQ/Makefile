SRCS = main.c ft_putstr.c ft_atoi.c ft_putstr.c find_square.c ft_putnbr.c ft_puterr.c c_vec2u.c
OBJS = ${SRCS:.c=.o}
CC = gcc
FLAGS = -Wall -Wextra -Werror
PROG = BSQ

all : ${PROG}

allup : all clean

grid :
	bash make_grid.sh

${PROG} : ${OBJS}
	@${CC} ${FLAGS} $^ -o $@

.c.o:
	@${CC} ${FLAGS} -c $< -o ${<:.c=.o}

clean:
	@rm -f ${OBJS}

fclean : clean
	@rm -f ${PROG} grid.txt

re : fclean all

.PHONY : all clean fclean re grid