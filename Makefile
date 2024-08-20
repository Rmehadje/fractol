# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmehadje <rmehadje@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/23 14:56:17 by rmehadje          #+#    #+#              #
#    Updated: 2023/10/31 17:49:50 by rmehadje         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fractol
CFLAGS := -Wextra -Wall -Werror -g -O3 -funroll-loops
LIBMLX := ./lib/MLX42
HEADERS := -I ./include -I $(LIBMLX)/include
LIBS := $(LIBMLX)/build/libmlx42.a
SRCS := fractol.c init.c movement.c Mandelbrot.c \
Julia.c atof.c
LDFLAGS := -ldl -lglfw -pthread -lm -flto -framework Cocoa -framework OpenGL -framework IOKit
OBJS := $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<

build:
	mkdir -p lib && cd lib && git clone https://github.com/codam-coding-college/MLX42.git
	cd lib && cd MLX42 && cmake -B build && cmake --build build -j4
	

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) $(LDFLAGS) -o $(NAME)

rmlib:
	rm -rf lib

clean:
	@rm -rf $(OBJS)

fclean: clean
	rm -f $(OBJS) $(NAME)

re: fclean all

.PHONY: all MLX rmlib clean fclean re