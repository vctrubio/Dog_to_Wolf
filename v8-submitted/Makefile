name = cub3D
SRCS = $(wildcard ./srcs/*.c)
OBJS = $(SRCS:.c=.o)
RM = rm -f
UNAME = $(shell uname)
LIBS	= -L./libft -lft

ifeq ($(UNAME), Darwin)
all: 
	$(MAKE) -C libft
	gcc $(SRCS) $(LIBS) lmlx/libmlx.a -L/usr/lib -framework OpenGL -framework AppKit -o $(name)

else
all:
	$(MAKE) -C libft
	gcc -g -Wall -Werror -Wextra $(SRCS) $(LIBS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -fsanitize=address -o $(name) 
	# gcc -g -valgrind -Wall -Werror -Wextra $(SRCS) $(LIBS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(name) 
endif
run: all
	./$(name)

clean:
	$(RM) $(OBJS) $(NAME)

fclean:	clean
	$(MAKE) fclean -C libft
				$(RM) $(NAME)

re: clean all
