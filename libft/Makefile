# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asouat <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/03 11:54:05 by asouat            #+#    #+#              #
#    Updated: 2018/10/31 17:49:26 by asouat           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libft.a

SRCS_DIR = ./srcs
INC_DIR	= ./includes
OBJ_DIR	= ./objects

FLAGS= -Wall -Werror -Wextra

OBJECTS = $(SOURCES:.c=.o)
SOURCES = ft_round_num.c ft_putchar_fd.c ft_islower.c ft_toupper.c \
			ft_putnbr_fd.c ft_lstnew.c ft_isascii.c ft_strstr.c \
			ft_putendl.c ft_strdup.c ft_memset.c ft_memmove.c \
			ft_strnequ.c ft_bin_to_decimal.c ft_strcpy.c ft_strncmp.c \
			ft_strdel.c ft_striteri.c ft_strmapi.c ft_uitoa.c ft_memalloc.c \
			ft_strlen.c ft_lstmap.c ft_strjoin.c ft_lluitoa.c \
			get_next_line.c ft_bin_to_octal.c ft_count_digits.c ft_putstr.c \
			ft_itoa.c ft_putnbr.c ft_strnew.c ft_power.c ft_strchr.c \
			ft_strjoin3.c ft_memchr.c ft_bin_to_hexa.c ft_strmap.c \
			ft_putendl_fd.c ft_strclr.c ft_memccpy.c ft_striter.c \
			ft_memdel.c ft_lltoa.c ft_word_len.c ft_isalpha.c \
			ft_isprint.c ft_putstr_fd.c ft_strtrim.c ft_decimal_to_bin.c \
			ft_luitoa.c ft_strrchr.c ft_bzero.c ft_strsplit.c \
			ft_word_count.c ft_lstadd.c ft_memcpy.c ft_strncat.c \
			ft_lstiter.c ft_strsub.c ft_strequ.c ft_strncpy.c ft_strrstr.c \
			ft_atoi.c ft_lstdelone.c ft_isdigit.c ft_lstdel.c ft_tolower.c \
			ft_isalnum.c ft_litoa.c ft_isupper.c ft_strnstr.c ft_strcmp.c \
			ft_strcat.c ft_putchar.c ft_strlcat.c ft_memcmp.c

SRCS_PATH = $(addprefix $(SRCS_DIR)/,$(SOURCES))
OBJ_PATH = $(addprefix $(OBJ_DIR)/,$(SOURCES:.c=.o))

$(NAME):
	@mkdir -p $(OBJ_DIR)
	@gcc $(FLAGS) -I $(INC_DIR) -c $(SRCS_PATH)
	@mv $(OBJECTS) $(OBJ_DIR)
	@ar rc $(NAME) $(OBJ_PATH)
	@ranlib $(NAME)

all: $(NAME)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
