NAME = libftprintf.a
FILES = printf num str print
OUT = $(foreach file,$(FILES),ft_$(file).o)
FLAGS = -Wall -Wextra -Werror

all: FLAGS := $(FLAGS) -D 'FT_PRINTF_PARSE(s)=(ft_printf_init_opt())'
all: $(NAME)

%.o: %.c
	gcc $(FLAGS) -c $^ -o $@

$(NAME): $(OUT)
	$(MAKE) -C libft
	cp libft/libft.a $(NAME)
	ar rcs $@ $^

clean:
	$(MAKE) clean -C libft
	rm -rf $(OUT)

fclean: clean
	$(MAKE) fclean -C libft
	rm -rf $(NAME)

re: fclean all

bonus: FLAGS := $(FLAGS) -D 'FT_PRINTF_PARSE(s)=(ft_printf_parse_opt(s))'
bonus: $(NAME)

test: bonus
	sh test.sh > main.c
	gcc $(FLAGS) $(NAME) main.c -o out
	./out | cat -e
	rm out

.PHONY: all clean fclean re bonus test
