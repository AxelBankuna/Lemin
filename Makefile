# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abukasa <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/07 15:49:10 by abukasa           #+#    #+#              #
#    Updated: 2019/01/16 15:28:57 by abukasa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Werror -Wextra
ALLFILL =lemin 

SRC = lemin.c src/load.c src/load2.c src/routes.c src/movethem.c \
	  src/movecheck.c src/start_route.c src/trim.c src/print.c \
	  src/backwards.c

OBJ = lemin.o src/load.o src/load2.o src/routes.o src/movethem.o \
	  src/movecheck.o src/start_route.o src/trim.o src/print.o \
	  src/backwards.o

lemin : $(OBJECTS)
all: $(ALLFILL)
$(ALLFILL):
	@$(MAKE) -C libft	
	@gcc -Wall -Werror -Wextra $(SRC) -o $@ $(OBJECTS) libft/libft.a

norm:
	norminette -R CheckForbiddenSourceHeader src/*.c
	norminette -R CheckForbiddenSourceHeader src/*.h
	norminette -R CheckForbiddenSourceHeader *.c

clean :
	@rm -rf $(OBJ)
	@$(MAKE) -C libft clean

fclean : clean
	@rm -rf $(NAME) lemin
	@$(MAKE) -C libft fclean
re: fclean all
	@$(MAKE) -C libft fclean all
