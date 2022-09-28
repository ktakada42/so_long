# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktakada <ktakada@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/28 16:15:39 by ktakada           #+#    #+#              #
#    Updated: 2022/09/28 16:15:41 by ktakada          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long

CC := cc

CFLAGS := -Wall -Wextra -Werror

MINILIBXFLAGS := -L/usr/X11R6/lib -lX11 -lXext -framework OpenGL -framework AppKit

SRCS := main.c

LIBFTDIR := ./libft

LIBFTAR := libft.a

MINILIBXDIR := ./minilibx-linux

MINILIBXAR := libmlx_Darwin.a

.PHONY: all
all: $(NAME)

.PHONY: $(NAME)
$(NAME): $(SRCS)
	make -C $(LIBFTDIR)
	make -C $(MINILIBXDIR)
	cp $(LIBFTDIR)/$(LIBFTAR) .
	cp $(MINILIBXDIR)/$(MINILIBXAR) .
	$(CC) $(CFLAGS) $(MINILIBXFLAGS) $(SRCS) $(MINILIBXAR) -o $(NAME)

.PHONY: clean
clean:
	make -C $(LIBFTDIR) clean
	make -C $(MINILIBXDIR) clean
	rm -f $(OBJS)

.PHONY: fclean
fclean:
	make -C $(LIBFTDIR) fclean
	make -C $(MINILIBXDIR) clean
	rm -f $(LIBFTAR)
	rm -f $(MINILIBXAR)
	rm -f $(NAME)

.PHONY: re
re: fclean all
