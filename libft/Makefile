# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mberger- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/18 11:06:13 by mberger-          #+#    #+#              #
#    Updated: 2021/10/26 09:54:52 by mberger-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FILES = atoi \
		bzero \
		calloc \
		isalnum \
		isalpha \
		isascii \
		isdigit \
		isprint \
		itoa \
		max \
		memchr \
		memcmp \
		memcpy \
		memmove \
		memset \
		min \
		putchar_fd \
		putendl_fd \
		putnbr_fd \
		putstr_fd \
		split \
		strchr \
		strdup \
		striteri \
		strjoin \
		strlcat \
		strlcpy \
		strlen \
		strmapi \
		strncmp \
		strnstr \
		strrchr \
		strtrim \
		substr \
		tolower \
		toupper


BONUS_FILES = lstadd_back \
				lstadd_front \
				lstclear \
				lstdelone \
				lstiter \
				lstlast \
				lstmap \
				lstnew \
				lstsize \

OUTPUT = $(foreach file,$(FILES),ft_$(file).o)
BONUS_OUTPUT = $(OUTPUT) $(foreach file,$(BONUS_FILES),ft_$(file)_bonus.o)
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

bonus: $(BONUS_OUTPUT)
	ar rcs $(NAME) $^

%.o: %.c
	gcc $(FLAGS) -c $^ -o $@

$(NAME): $(OUTPUT)
	ar rcs $@ $^

clean:
	rm -rf $(BONUS_OUTPUT)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
