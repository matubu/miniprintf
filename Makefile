NAME = libftprintf.a
FILES = printf num str print

OBJ_BOTH = $(foreach file,$(FILES),ft_$(file).o)
OBJ_MANDATORY = parse.o
OBJ_BONUS = parse_bonus.o

FLAGS = -Wall -Wextra -Werror

all: OBJ := $(OBJ_BOTH) $(OBJ_MANDATORY)
all: OBJ_UNUSED := $(OBJ_BONUS)
all: $(OBJ_MANDATORY) $(NAME)

bonus: OBJ := $(OBJ_BOTH) $(OBJ_BONUS)
bonus: OBJ_UNUSED := $(OBJ_MANDATORY)
bonus: $(OBJ_BONUS) $(NAME)

%.o: %.c
	rm -rf $(NAME) $(OBJ_UNUSED)
	gcc $(FLAGS) -c $^ -o $@

$(NAME): $(OBJ_BOTH)
	$(MAKE) -C libft
	cp libft/libft.a $(NAME)
	ar rcs $@ $(OBJ)

clean:
	$(MAKE) clean -C libft
	rm -rf $(OBJ_BOTH) $(OBJ_MANDATORY) $(OBJ_BONUS)

fclean: clean
	$(MAKE) fclean -C libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
