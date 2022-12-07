# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 13:34:19 by dbiguene          #+#    #+#              #
#    Updated: 2022/11/21 17:03:39 by dbiguene         ###   ########lyon.fr    #
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

HEADERS_LIST	=	libft.h					ft_char.h	\
					ft_get_next_line.h		ft_io.h		\
					ft_linked_list.h		ft_mem.h	\
					ft_numbers.h			ft_string.h	\

SRCS			=	char/ft_isalpha.c					char/ft_isdigit.c					\
					char/ft_isalnum.c					char/ft_isascii.c					\
					char/ft_isprint.c					char/ft_toupper.c					\
					char/ft_tolower.c														\
					\
					string/ft_strchr.c					string/ft_split.c					\
					string/ft_strlcat.c					string/ft_strlcpy.c					\
					string/ft_substr.c					string/ft_strjoin.c					\
					string/ft_strtrim.c					string/ft_strlen.c					\
					string/ft_strdup.c					string/ft_strmapi.c					\
					string/ft_striteri.c				string/ft_strnstr.c					\
					string/ft_strrchr.c					string/ft_strncmp.c					\
					\
					numbers/ft_itoa.c					numbers/ft_atoi.c					\
					\
					mem/ft_calloc.c						mem/ft_memmove.c					\
					mem/ft_memset.c						mem/ft_bzero.c						\
					mem/ft_memcpy.c						mem/ft_memchr.c						\
					mem/ft_memcmp.c															\
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
					io/printf/ft_printf.c 				io/printf/ft_printers.c					\
					io/printf/ft_printers2.c													\
					\
					get_next_line/get_next_line.c		get_next_line/get_next_line_utils.c
								

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
					@echo "\n\033[0;32m ✔️ Binaries compiled from \033[1;36m${DIR_SRCS} \033[0;32mto \033[1;36m${DIR_OBJS} !"
					${AR} ${NAME} ${OBJS}
					@echo "\n\033[0;32m ✔️ Lib successfully built !"

# ---- Compiled Rules ---- #

${OBJS}			:	| ${DIR_OBJS}

${DIR_OBJS}%.o	:	${DIR_SRCS}%.c ${HEADERS}
					${CC} ${CFLAGS} -I ${DIR_HEADERS}. -c $< -o $@

${DIR_OBJS}:
			@echo ${OBJS} | tr ' ' '\n'\
				| sed 's|\(.*\)/.*|\1|'\
				| sed 's/^/${MKDIR} /'\
				| sh -s
			@echo "\n\033[0;32m ✔️ Successfully created binaries directories \033[1;36m${DIR_OBJS} !"

# ---- Usual Rules ---- #

clean			:
					${RM} ${OBJS}
					@echo "\n\033[0;31m ✔️ Successfully deleted binaries from directory \033[1;36m${DIR_OBJS} !"

fclean			:	clean
					${RM} ${NAME}
					@echo "\n\033[0;31m ✔️ Successfully deleted \033[1;36m${NAME} !"

re				:	fclean all
					@echo "\n\033[0;32m ✔️ Successfully re-compiled binaries and lib \033[0;36m${NAME} !"

.PHONY:	all clean fclean re
.SILENT:
