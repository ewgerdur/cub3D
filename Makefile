NAME	   = cub3D

SRCS	   = $(wildcard *.c)

OBJS	   =  ${SRCS:.c=.o}

MLX	       =  mlxlinux

FLAGS	   = -Wall -Wextra -Werror -g

CC         = gcc

$(NAME):     $(OBJS)
	$(MAKE) -C $(MLX)
	#$(CC) get_screen.m -L$(MLX) -lmlx -lXext -lX11 -lm -lz -framework OpenGL -framework Appkit -O3 $(OBJS) -o $(NAME)
	$(CC)  -o $(NAME) $(OBJS) -L$(MLX) -lmlx -lXext -lX11 -lm -lz

%.o: %.c
	$(CC) $(FLAGS)  -c $< -o $@

all:        $(NAME)

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}
			rm -f screenshot.bmp
			$(MAKE) -C $(MLX) clean

re:			fclean all

.PHONY:		all bonus clean fclean re