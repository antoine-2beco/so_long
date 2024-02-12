# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/07 15:13:16 by ade-beco          #+#    #+#              #
#    Updated: 2024/02/12 10:32:00 by ade-beco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SO_LONG		=		so_long

LIBFT		=		libft
LIBFT_PATH	=		./libft/

SRC_PATH	=		./src/
SRCS 		=		so_long.c check_map.c
SRCS_D 		=		$(SRC_PATH)so_long.c $(SRC_PATH)check_map.c

OBJECTS		=		$(SRCS:.c=.o)

INC			=		-I includes/$(NAME).h $(LIBFT_PATH)$(LIBFT).h

all: 		$(SO_LONG)

$(SO_LONG):	$(OBJECTS) $(LIBFT_PATH)
					@make bonus -C $(LIBFT_PATH) $(LIBFT).a
					@cp $(LIBFT_PATH)$(LIBFT).a $(SO_LONG)
					@echo "Creating SO_LONG Executable..."
					@ar -rcs $(SO_LONG) $(OBJECTS)
					@cc $(SO_LONG) -Lmlx -lmlx -framework OpenGL -framework AppKit -fsanitize=address -o $(SO_LONG)
					@echo "OK !"

$(OBJECTS):	$(SRCS_D)
					@echo "Compiling SO_LONG..."
					@cc -Wall -Wextra -Werror -Imlx -c $(INC) $(SRCS_D)
					@echo "OK !"

clean:
					@make clean -C $(LIBFT_PATH)
					@echo "Cleaning SO_LONG Objects..."
					@rm -f $(OBJECTS)
					@echo "OK !"

fclean:		clean
					@make fclean -C $(LIBFT_PATH)
					@echo "Cleaning SO_LONG..."
					@rm -f $(SO_LONG)
					@echo "OK !"

re:			fclean all 
.PHONY:		all clean fclean re