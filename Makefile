# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/19 19:15:46 by geargenc          #+#    #+#              #
#    Updated: 2017/12/15 22:58:27 by geargenc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

FILES	=	ft_memset.c\
			ft_bzero.c\
			ft_memcpy.c\
			ft_memccpy.c\
			ft_memmove.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_strlen.c\
			ft_strdup.c\
			ft_strcpy.c\
			ft_strncpy.c\
			ft_strcat.c\
			ft_strncat.c\
			ft_strlcat.c\
			ft_strchr.c\
			ft_strrchr.c\
			ft_strstr.c\
			ft_strnstr.c\
			ft_strcmp.c\
			ft_strncmp.c\
			ft_atoi.c\
			ft_isalpha.c\
			ft_isdigit.c\
			ft_isalnum.c\
			ft_isascii.c\
			ft_isprint.c\
			ft_toupper.c\
			ft_tolower.c\
			ft_memalloc.c\
			ft_memdel.c\
			ft_strnew.c\
			ft_strdel.c\
			ft_strclr.c\
			ft_striter.c\
			ft_striteri.c\
			ft_strmap.c\
			ft_strmapi.c\
			ft_strequ.c\
			ft_strnequ.c\
			ft_strsub.c\
			ft_strjoin.c\
			ft_strtrim.c\
			ft_strsplit.c\
			ft_itoa.c\
			ft_putchar.c\
			ft_putstr.c\
			ft_putendl.c\
			ft_putnbr.c\
			ft_putchar_fd.c\
			ft_putstr_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c\
			ft_lstnew.c\
			ft_lstdelone.c\
			ft_lstdel.c\
			ft_lstadd.c\
			ft_lstiter.c\
			ft_lstmap.c\
			ft_factorial.c\
			ft_isblank.c\
			ft_iscntrl.c\
			ft_isgraph.c\
			ft_islower.c\
			ft_ispunct.c\
			ft_isspace.c\
			ft_isupper.c\
			ft_isxdigit.c\
			ft_lstpushback.c\
			ft_lstsize.c\
			ft_power.c\
			ft_root.c\
			ft_strjoinfree.c\
			ft_strsplitmore.c\
			ft_strsplitwhitespaces.c\
			get_next_line.c

SRC		=	$(addprefix src/, $(FILES))

OBJ		=	$(FILES:.c=.o)

INC		=	includes/

COMP	=	gcc -Wall -Wextra -Werror

all		:	$(NAME)

$(NAME)	:	$(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[1;32m$(NAME) created !\033[0m"

$(OBJ)	:	%.o: src/%.c
	@$(COMP) -I $(INC) -c $< -o $@
	@echo "\033[1;32m$< -> $@\033[0m"

clean	:
	@rm -rf $(OBJ)
	@echo "\033[1;32m$(OBJ) removed !\033[0m"

fclean	:	clean
	@rm -rf $(NAME)
	@echo "\033[1;32m$(NAME) removed !\033[0m"

re		:	fclean all

easy	:	all clean

.PHONY	:	all clean fclean re easy
