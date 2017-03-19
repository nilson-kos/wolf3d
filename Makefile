# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kshcherb <kshcherb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/19 17:36:18 by kshcherb          #+#    #+#              #
#    Updated: 2017/03/18 17:46:52 by kshcherb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

IDIR = includes/

VPATH = src:includes

FLAGS = -O3 -Wall -Wextra -Werror -I$(IDIR) -g

MLX = -lmlx -framework AppKit -framework OpenGl

LIB = libft/libft.a

SRCS =		main.c											\
			ft_init_wf.c									\
			menu.c											\
			ft_zaloop_hook.c								\
			download_image.c								\
			ft_readfile.c 									\
			raycasting.c									\
			ft_pix_put.c									\
			ft_key_event.c									\
			ft_buttons.c									\
			speed_fps.c										\

BINS = $(SRCS:.c=.o)

all: $(NAME)

makelib:
	make -C libft/

libclean:
	make -C libft/ clean

libfclean:
	make -C libft/ fclean

$(NAME): $(BINS)
	make -C libft/
	gcc -o $(NAME) $(BINS) $(FLAGS) $(MLX) $(LIB)

%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

clean: libclean
	/bin/rm -f $(BINS)

fclean: libfclean clean
	/bin/rm -f $(NAME)

re: fclean all
