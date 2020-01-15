# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asouat <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/22 11:37:13 by asouat            #+#    #+#              #
#    Updated: 2019/04/26 17:04:35 by asouat           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

LIBFT = libft
SRCS_PATH = srcs
OBJ_PATH = objects

SOURCES = ft_printf.c \
		  get_arg_f.c \
			f_to_str.c \
		  apply_option_to_di_tools.c \
			apply_option_to_f_tools.c \
		  apply_option_to_di.c \
		  apply_option_to_o.c \
		  apply_option_to_u.c \
		  apply_option_to_x.c \
		  apply_option_to_f.c \
		  apply_precision.c \
		  di_to_str.c \
		  get_arg_modified_for_f_pourcent.c \
		  get_arg_modified_for_p.c \
		  get_all_for_t_arg1.c \
		  get_all_for_t_arg2.c \
		  get_arg_c.c \
		  get_arg_di.c \
		  get_arg_modified_for_di.c \
		  get_arg_modified_for_oux.c \
		  get_arg_modified_for_cs.c \
		  get_arg_modified.c \
		  get_arg_oux.c \
		  get_arg_s.c \
		  get_prefix.c \
		  get_str_format.c \
		  get_t_arg.c \
		  leaks_management.c \
		  oux_to_str.c \
		  print_str_format.c \
		  put_wchar_tools.c \
		  put_wchar_wint_tools1.c \
		  put_wchar_wint_tools2.c \
		  get_wchar_wint_len.c \
		  utf8_tools.c \
		  u_to_str.c

OBJS = $(addprefix $(OBJ_PATH)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(OBJ_PATH)/%.o: $(SRCS_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(FLAG) -I includes -o $@  -c $<

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_PATH)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY : all clean fclean re
