# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aminadzh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/24 13:17:40 by aminadzh          #+#    #+#              #
#    Updated: 2018/03/24 13:18:40 by aminadzh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = fdf

LIB_DIR = ./libft
SRC_DIR = ./src
INC_DIR = ./inc
BIN_DIR = bin

SRC     = draw_segment.c \
        environment.c \
        hooks.c \
        image.c \
        linked_lists.c \
        main.x \
        move_map.c \
        reader.c \
        render.c \

OBJ     = $(addprefix $(BIN_DIR)/,$(SRC:.c=.o))

CC      = gcc
FLAGS   = -Wall -Werror -Wextra

MLX_I   = -I /usr/local/include
MLX_L   = -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(OBJ): | $(BIN_DIR)

$(BIN_DIR)
    mkdir $(BIN_DIR)

$(BIN_DIR)/%.o : $(SRC_DIR)/%.c
    $(CC) $(FLAGS) -I$(INC_DIR) $(MLX_I) -o $@ -c $<

$(NAME): $(OBJ)
    @make -C $(LIB_DIR)
    @cp $(LIB_DIR)*.o ./$(BIN_DIR)
    $(CC) $(FLAGS) $(OBJ) -L$(LIB_DIR) -lft $(MLX_L) -o $(NAME)

clean:
    rm -rf $(BIN_DIR)

fclean: clean
    rm -f $(NAME)

re:
    $(MAKE) fclean
    $(MAKE) all
