# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 13:34:19 by dbiguene          #+#    #+#              #
#    Updated: 2022/12/15 21:54:44 by dbiguene         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #


# ******** VARIABLES ******** #

# ---- Final Executable --- #

NAME			=	libft.a

# ---- Directories ---- #

DIR_OBJS		=	bin/

DIR_SRCS		=	src/

DIR_HEADERS		=	includes/

# ---- Files ---- #

HEADERS_LIST	=	libft.h					char.h		\
					string.h				io.h		\
					linked_list.h			memory.h	\
					number.h				array.h		\

SRCS			=	char/ft_isalpha.c					char/ft_isdigit.c					\
					char/ft_isalnum.c					char/ft_isascii.c					\
					char/ft_isprint.c					char/ft_isspace.c					\
					char/ft_tolower.c					char/ft_toupper.c					\
					\
					string/ft_strchr.c					string/ft_split.c					\
					string/ft_strlcat.c					string/ft_strlcpy.c					\
					string/ft_substr.c					string/ft_strjoin.c					\
					string/ft_strtrim.c					string/ft_strlen.c					\
					string/ft_strdup.c					string/ft_strmapi.c					\
					string/ft_striteri.c				string/ft_strnstr.c					\
					string/ft_strrchr.c					string/ft_strncmp.c					\
					string/ft_strtolower.c				string/ft_strtoupper.c				\
					string/ft_strndup.c														\
					\
                    math/ft_abs.c						math/ft_log.c						\
                    math/ft_clamp.c						math/ft_pow.c						\
                    math/ft_is_prime.c					math/ft_sqrt.c						\
					\
					number/ft_itoa.c					number/ft_atoi.c					\
					number/ft_itob.c					number/ft_atoll.c					\
					\
					array/ft_array_len.c				array/ft_bubble_sort.c				\
					array/ft_bucket_sort.c				array/ft_insertion_sort.c			\
					array/ft_merge_sort.c				array/ft_selection_sort.c			\
					\
					memory/ft_calloc.c					memory/ft_memmove.c					\
					memory/ft_memset.c					memory/ft_bzero.c					\
					memory/ft_memcpy.c					memory/ft_memchr.c					\
					memory/ft_memcmp.c					memory/ft_free.c					\
					memory/ft_free_array.c													\
					\
					linked_list/ft_lstnew.c				linked_list/ft_lstadd_front.c		\
					linked_list/ft_lstsize.c			linked_list/ft_lstlast.c			\
					linked_list/ft_lstadd_back.c		linked_list/ft_lstdelone.c			\
					linked_list/ft_lstclear.c			linked_list/ft_lstiter.c			\
					linked_list/ft_lstmap.c													\
					\
					io/ft_putchar_fd.c					io/ft_putnbr_fd.c					\
					io/ft_putstr_fd.c					io/ft_putendl_fd.c					\
					\
					io/printf/ft_printf.c 				io/printf/ft_printers.c				\
					io/printf/ft_printers2.c												\
					\
					io/get_next_line/get_next_line.c	io/get_next_line/get_next_line_utils.c

HEADERS			=	${HEADERS_LIST:%.h=${DIR_HEADERS}%.h}

OBJS			=	${SRCS:%.c=${DIR_OBJS}%.o}

# ---- Compilation ---- #

CC				=	cc

CFLAGS			=	-Wall -Wextra -Werror

# ---- Commands ---- #

RM				=	rm -rf

MKDIR			=	mkdir -p

AR				=	ar rcs

# ********* RULES ******** #

all				: ${NAME}

# ---- Variables Rules ---- #

${NAME}			:	${OBJS} ${HEADERS}
					@echo "\033[0;32m [libft] ✔️ Binaries compiled from \033[1;36m${DIR_SRCS} \033[0;32mto \033[1;36m${DIR_OBJS} !"
					${AR} ${NAME} ${OBJS}
					@echo "\033[0;32m [libft] ✔️ Lib successfully built !"

# ---- Compiled Rules ---- #

${OBJS}			:	| ${DIR_OBJS}

${DIR_OBJS}%.o	:	${DIR_SRCS}%.c ${HEADERS}
					${CC} ${CFLAGS} -I ${DIR_HEADERS}. -c $< -o $@

${DIR_OBJS}:
			@echo ${OBJS} | tr ' ' '\n'\
				| sed 's|\(.*\)/.*|\1|'\
				| sed 's/^/${MKDIR} /'\
				| sh -s
			@echo "\033[0;32m [libft] ✔️ Successfully created binaries directories \033[1;36m${DIR_OBJS} !"

# ---- Usual Rules ---- #

clean			:
					${RM} ${OBJS}
					@echo "\033[0;31m [libft] ✔️ Successfully deleted binaries from directory \033[1;36m${DIR_OBJS} !"

fclean			:	clean
					${RM} ${NAME}
					@echo "\033[0;31m [libft] ✔️ Successfully deleted \033[1;36m${NAME} !"

re				:	fclean all
					@echo "\033[0;32m [libft] ✔️ Successfully re-compiled binaries and lib \033[0;36m${NAME} !"

test            :	all
					${CC} ${CFLAGS} -I ${DIR_HEADERS}. test.c ${NAME} -o test
					@echo "\033[0;32m [libft] ✔️ Successfully compiled \033[0;36mtest \033[0;32mprogram !"
					./test

.PHONY:	all clean fclean re
.SILENT:
