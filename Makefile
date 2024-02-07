# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/07 15:13:16 by ade-beco          #+#    #+#              #
#    Updated: 2024/02/07 10:18:50 by ade-beco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SO_LONG		=		so_long

SRC_PATH	=		./src/
SRCS 		=		so_long.c ft_printf.c ft_printf_utils.c utils_func.c
SRCS_D 		=		$(SRC_PATH)so_long.c $(SRC_PATH)ft_printf.c $(SRC_PATH)ft_printf_utils.c $(SRC_PATH)utils_func.c

OBJECTS		=		$(SRCS:.c=.o)

INC			=		-I includes/$(NAME).h

all: 		$(SO_LONG)

$(SO_LONG):	$(OBJECTS) $(LIBFT_PATH)
					@echo "Creating SO_LONG Executable..."
					@ar -rcs $(SO_LONG) $(OBJECTS)
					@gcc $(SO_LONG) -fsanitize=address -o $(SO_LONG)
					@echo "OK !"

$(OBJECTS):	$(SRCS_D)
					@echo "Compiling SO_LONG..."
					@cc -Wall -Wextra -Werror -c $(INC) $(SRCS_D)
					@echo "OK !"

clean:
					@echo "Cleaning SO_LONG Objects..."
					@rm -f $(OBJECTS)
					@echo "OK !"

fclean:		clean
					@echo "Cleaning SO_LONG..."
					@rm -f $(SO_LONG)
					@echo "OK !"

re:			fclean all 
.PHONY:		all clean fclean re