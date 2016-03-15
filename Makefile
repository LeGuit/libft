# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 11:51:30 by gwoodwar          #+#    #+#              #
#    Updated: 2016/02/15 17:54:08 by gwoodwar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# For mem : @ before a commande hide the echo of the command

CC =		clang
FLAGS =		-Wall -Werror -Wextra -O2
NAME =		libft.a
INCLS =		-I./includes
SRCS_DIR =	srcs
OBJS_DIR =	objs

LIST =	ft_dlst/ft_dlstcreate \
		ft_dlst/ft_dlstdel \
		ft_dlst/ft_dlstmove \
		ft_dlst/ft_dlsttest \
		ft_dlst/ft_dlstsort \
		ft_draw/ft_mix_color \
		ft_draw/ft_put_pix_to_img \
		ft_gnl/get_next_line \
		ft_is/ft_isalnum \
		ft_is/ft_isalpha \
		ft_is/ft_isascii \
		ft_is/ft_isdigit \
		ft_is/ft_isprint \
		ft_lsts/ft_lstnew \
		ft_lsts/ft_lstdelone \
		ft_lsts/ft_lstdel \
		ft_lsts/ft_lstadd \
		ft_lsts/ft_lstiter \
		ft_lsts/ft_lstmap \
		ft_lsts/ft_lstfind \
		ft_mem/ft_bzero \
		ft_mem/ft_memalloc \
		ft_mem/ft_memccpy \
		ft_mem/ft_memcpy \
		ft_mem/ft_memrcpy \
		ft_mem/ft_memdel \
		ft_mem/ft_memmove \
		ft_mem/ft_memset \
		ft_mem/ft_memchr \
		ft_mem/ft_memcmp \
		ft_printf/conversion \
		ft_printf/print_arg \
		ft_printf/process_mod \
		ft_printf/print_u \
		ft_printf/print_sign \
		ft_printf/print_str \
		ft_printf/print_c \
		ft_printf/print_wstr \
		ft_printf/display_ui \
		ft_printf/ft_printf_prefix \
		ft_printf/ft_wstrlen \
		ft_printf/ft_printf \
		ft_printf/get_mod \
		ft_printf/ft_vprintf \
		ft_puts/ft_putchar \
		ft_puts/ft_putchar_fd \
		ft_puts/ft_putendl \
		ft_puts/ft_putendl_fd \
		ft_puts/ft_putnbr \
		ft_puts/ft_putnbr_fd \
		ft_puts/ft_putstr \
		ft_puts/ft_putstr_fd \
		ft_puts/ft_putnstr \
		ft_puts/ft_putnstr_fd \
		ft_str/ft_strcat \
		ft_str/ft_strchr \
		ft_str/ft_strclr \
		ft_str/ft_strcmp \
		ft_str/ft_strcpy \
		ft_str/ft_strdel \
		ft_str/ft_strdup \
		ft_str/ft_strequ \
		ft_str/ft_striter \
		ft_str/ft_striteri \
		ft_str/ft_strjoin \
		ft_str/ft_strlcat \
		ft_str/ft_strlen \
		ft_str/ft_strlen_ch \
		ft_str/ft_strmap \
		ft_str/ft_strmapi \
		ft_str/ft_strncat \
		ft_str/ft_strncmp \
		ft_str/ft_strncpy \
		ft_str/ft_strnequ \
		ft_str/ft_strnew \
		ft_str/ft_strnstr \
		ft_str/ft_strrchr \
		ft_str/ft_strrcpy \
		ft_str/ft_strsplit \
		ft_str/ft_strstr \
		ft_str/ft_strsub \
		ft_str/ft_strtrim \
		ft_tabs/ft_tabdel \
		ft_tabs/ft_tabdup \
		ft_tabs/ft_tabsize \
		ft_vect/ft_vect_at \
		ft_vect/ft_vect_push_back \
		ft_vect/ft_vect_reserve \
		ft_vect/ft_vect_del \
		ft_vect/ft_vect_print \
		ft_xtoy/ft_atoi \
		ft_xtoy/ft_atoll \
		ft_xtoy/ft_itoa \
		ft_xtoy/ft_size_nb \
		ft_xtoy/ft_slltstr \
		ft_xtoy/ft_tolower \
		ft_xtoy/ft_toupper \
		ft_xtoy/ft_ulltstr_base \
		ft_xtoy/ft_widetoa \
		ft_xtoy/ft_nb_words
		
SRCS := $(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(LIST)))
OBJS := $(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(LIST)))

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $@ $^
	ranlib $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) $(INCLS) -o $@ -c $<

clean:
	/bin/rm -rf $(OBJS_DIR)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all
