# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/07 15:13:16 by ade-beco          #+#    #+#              #
#    Updated: 2024/02/27 15:54:12 by ade-beco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SO_LONG		=		so_long

LIBFT		=		libft
LIBFT_PATH	=		./libft/

SRC_PATH	=		./src/
SRCS 		=		so_long.c check_map.c map_compliant.c
SRCS_D 		=		$(addprefix $(SRC_PATH), $(SRCS))

OBJECTS		=		$(SRCS_D:.c=.o)

INC			=		-I includes/$(SO_LONG).h -I $(LIBFT_PATH)$(LIBFT).h

all: 		$(OBJECTS) $(SO_LONG)

%.o:		%.c
					@gcc -Wall -Wextra -Werror -Imlx -c $< -o $(<:c=o)

$(SO_LONG):	$(OBJECTS)
					@echo "Compiling Libft..."
					@make bonus -C $(LIBFT_PATH) $(LIBFT).a
					@cp $(LIBFT_PATH)$(LIBFT).a $(SO_LONG)
					@echo "OK !"
					@echo "Compiling and Creating So_Long..."
					@ar -rcs $(SO_LONG) $(OBJECTS)
					@gcc $(SO_LONG) -Wall -Wextra -Werror -fsanitize=address $(INC) -o $(SO_LONG)
# -Lmlx -lmlx -framework OpenGL -framework AppKit
					@echo "OK !"

clean:
					@make clean -C $(LIBFT_PATH)
					@echo "Cleaning Push_Swap Objects..."
					@rm -f $(OBJECTS)
					@echo "OK !"

fclean:			clean
					@make fclean -C $(LIBFT_PATH)
					@echo "Cleaning Push_Swap..."
					@rm -f $(PUSH_SWAP)
					@echo "OK !"

re:			fclean all

.PHONY:		all clean fclean re
