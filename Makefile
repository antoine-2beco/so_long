# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/07 15:13:16 by ade-beco          #+#    #+#              #
#    Updated: 2024/03/25 10:46:53 by ade-beco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SO_LONG		=		so_long

LIBFT		=		libft.a
LIBFT_PATH	=		./libft/

MLX			=		libmlx.a
MLX_PATH	=		./mlx/

SRC_PATH	=		./src/
SRCS 		=		so_long.c init_map.c init_game.c map_compliant.c check_path.c
SRCS_D 		=		$(addprefix $(SRC_PATH), $(SRCS))

OBJECTS		=		$(SRCS_D:.c=.o)

INC			=		-I includes/$(SO_LONG).h -I $(LIBFT_PATH)$(LIBFT).h
CFLAGS		=		-Wall -Wextra -Werror -fsanitize=address
MLX_INC		=		-Lmlx -lmlx -framework OpenGL -framework AppKit

all: 		$(OBJECTS) $(SO_LONG)

%.o:		%.c
					@gcc -Wall -Wextra -Werror -Imlx -c $< -o $(<:c=o)

$(SO_LONG):	$(OBJECTS)
					@echo "Compiling Libft..."
					@make bonus -C $(LIBFT_PATH)
					@cp $(LIBFT_PATH)$(LIBFT) $(SO_LONG)
					@echo "OK !"
					@echo "Compiling Mlx..."
					@make -C $(MLX_PATH)
					@echo "OK !"
					@echo "Compiling and Creating So_Long..."
					@ar -rcs $(SO_LONG) $(OBJECTS)
					@gcc $(SO_LONG) $(CFLAGS) $(MLX_INC) $(INC) $(MLX_PATH)$(MLX) -o $(SO_LONG)
					@echo "OK !"

clean:
					@make clean -C $(LIBFT_PATH)
					@make clean -C $(MLX_PATH)
					@echo "Cleaning Push_Swap Objects..."
					@rm -f $(OBJECTS)
					@echo "OK !"

fclean:			clean
					@make fclean -C $(LIBFT_PATH)
					@make clean -C $(MLX_PATH)
					@echo "Cleaning Push_Swap..."
					@rm -f $(PUSH_SWAP)
					@echo "OK !"

re:			fclean all

.PHONY:		all clean fclean re
