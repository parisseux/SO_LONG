# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/05 14:08:54 by pchatagn          #+#    #+#              #
#    Updated: 2024/12/09 14:23:28 by pchatagn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Werror -Wextra -Imlx/minilibx_opengl -I/usr/X11/include -Ilibraries/libft -Ilibraries/ft_printf -g
RM = rm -f
SRCDIR = src
OBJDIR = obj
LIBDIR = libraries
LIBFT = $(LIBDIR)/libft/libft.a
FT_PRINTF = $(LIBDIR)/ft_printf/libftprintf.a

FILES = main.c \
		so_long.c \
		color.c \
		event.c \
		utils.c \
		get_next_line_utils.c \
		get_next_line.c \
		check_map.c


SRC = $(addprefix $(SRCDIR)/, $(FILES))
OBJ = $(addprefix $(OBJDIR)/, $(FILES:.c=.o))


SUCCESS = "\033[1;35mSuccessful compilation!\033[0m"

all: $(NAME)
	@echo $(SUCCESS)

$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) -Lmlx/minilibx_opengl -lz -lmlx -framework OpenGL -framework AppKit -lm -o $(NAME)
$(LIBFT):
	@make all bonus -C $(LIBDIR)/libft

$(FT_PRINTF):
	@make -C $(LIBDIR)/ft_printf

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)  # Ensure obj/ directory exists
	@$(CC) $(CFLAGS) -c $< -o $@
 
	
clean:
	@$(RM) $(OBJ) 
	@rmdir $(OBJDIR) 2>/dev/null || true  # Remove obj/ only if empty
	@make -C $(LIBDIR)/libft clean
	@make -C $(LIBDIR)/ft_printf clean

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBDIR)/libft fclean
	@make -C $(LIBDIR)/ft_printf fclean

re: fclean all

.PHONY: all clean fclean re