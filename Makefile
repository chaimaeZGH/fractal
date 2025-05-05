CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -framework Cocoa -framework OpenGL -framework IOKit
MLX = MLX42/build/libmlx42.a -Iinclude -lglfw -L"/Users/czghoumi/.brew/Cellar/glfw/3.4/lib/"
SRCS = mand/main.c mand/mandelbrot.c mand/julia.c mand/help_function.c
OBJS = $(SRCS:.c=.o)

SRCS_B = bonus/main_bonus.c bonus/help_functin_bonus.c bonus/help_function_for_bonus.c
OBJS_B = $(SRCS_B:.c=.o)

HEADER = mand/fractol.h
NAME = fractol

NAME_B = fractol_bonus
HEADER_B = bonus/fractol_bonus.h

all: $(NAME)

bonus: $(NAME_B)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(MLX) $(MLXFLAGS) $(OBJS) -o $(NAME)

$(NAME_B): $(OBJS_B)
	$(CC) $(CFLAGS) $(MLX) $(MLXFLAGS) $(OBJS_B) -o $(NAME_B)

%_bonus.o: %_bonus.c $(HEADER_B)
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c $(HEADER) 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_B)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_B)

re: fclean all

.PHONY: all clean fclean re bonus