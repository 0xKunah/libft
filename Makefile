# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 13:34:19 by dbiguene          #+#    #+#              #
#    Updated: 2022/11/16 13:59:42 by dbiguene         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

.PHONY:	all clean fclean re

# ******** VARIABLES ******** #

# ---- Final Executable --- #

NAME		=	libft.a

COMP_NAME	= 	output

# ---- Directories ---- #

DIR_OBJS	=	.objs/

# ---- Files ---- #

HEAD		=	libft.h

SRCS		=	ft_isalpha.c	ft_isdigit.c	\
				ft_isalnum.c	ft_isascii.c	\
				ft_isprint.c	ft_calloc.c		\
				ft_memset.c		ft_bzero.c		\
				ft_memcpy.c		ft_strlcpy.c	\
				ft_strlcat.c	ft_toupper.c	\
				ft_tolower.c	ft_strchr.c		\
				ft_strrchr.c	ft_strncmp.c	\
				ft_memchr.c		ft_memcmp.c		\
				ft_memmove.c	ft_strnstr.c	\
				ft_atoi.c		ft_strdup.c		\
				ft_substr.c		ft_strjoin.c	\
				ft_strtrim.c	ft_strlen.c		\
				ft_itoa.c		ft_strmapi.c	\
				ft_striteri.c	ft_putchar_fd.c	\
				ft_putstr_fd.c	ft_putendl_fd.c	\
				ft_putnbr_fd.c	ft_split.c		\

SRCS_BONUS	=	ft_lstnew_bonus.c		ft_lstadd_front_bonus.c	\
				ft_lstsize_bonus.c		ft_lstlast_bonus.c		\
				ft_lstadd_back_bonus.c	ft_lstdelone_bonus.c	\
				ft_lstclear_bonus.c		ft_lstiter_bonus.c		\
				ft_lstmap_bonus.c

OBJS		=	${SRCS:%.c=${DIR_OBJS}%.o}

OBJS_BONUS	=	${SRCS_BONUS:%.c=${DIR_OBJS}%.o}

# ---- Compilation ---- #

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

# ---- Commands ---- #

RM		=	rm -rf
MKDIR	=	mkdir -p
AR		=	ar rc

# ********* RULES ******** #

all			:	${NAME}

bonus			:	${OBJS_BONUS} Makefile ${HEAD}
					${AR} ${NAME} ${OBJS_BONUS}

# ---- Variables Rules ---- #

${NAME}			:	${OBJS} Makefile ${HEAD}
					${AR} ${NAME} ${OBJS}

# ---- Compiled Rules ---- #

${OBJS}			:	| ${DIR_OBJS}

${OBJS_BONUS}	:	| ${DIR_OBJS}

${DIR_OBJS}%.o	:	%.c ${HEAD} Makefile
					${CC} ${CFLAGS} -I ${HEAD} -c $< -o $@

${DIR_OBJS}		:
					${MKDIR} ${DIR_OBJS}

# ---- Usual Commands ---- #

clean			:
					${RM} ${DIR_OBJS}

fclean			:	clean
					${RM} ${NAME}

re				:	fclean all
