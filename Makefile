# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/13 15:10:58 by ohertzbe          #+#    #+#              #
#    Updated: 2024/01/24 11:49:39 by ohertzbe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= fractol
CFLAGS	:= -g -Wall -Wextra -Werror
LIBMLX	:= ./lib/MLX42

HEADERS	:= -I ./include -I $(LIBMLX)/include -I ./lib/libft

LIBS	:= $(LIBMLX)/build/libmlx42.a -Iinclude -lglfw \
		-L"/Users/$(USER)/.brew/opt/glfw/lib/" -framework Cocoa \
		-framework OpenGL -framework IOKit \
		./lib/libft/libft.a

SRCS	:=	src/main.c \
			src/colours.c \
			src/event_functions.c \
			src/handle_args.c \
			src/instructions.c
			
OBJS := $(patsubst src/%.c, obj/%.o, $(SRCS))

all: libmlx libft $(NAME)

clone_mlx42:
	if [ ! -d "$(LIBMLX)" ]; then \
		git clone https://github.com/codam-coding-college/MLX42.git $(LIBMLX); \
	fi

libmlx: clone_mlx42
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	make -C ./lib/libft

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

obj/%.o: src/%.c
	@mkdir -p obj
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	make -C ./lib/libft clean

fclean: clean
	@rm -rf $(NAME)
	make -C ./lib/libft fclean

re: clean all

.PHONY: all, clean, fclean, re, libmlx