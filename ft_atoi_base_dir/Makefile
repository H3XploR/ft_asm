NAME = test_ft_atoi_base

$(NAME): test.o ft_atoi_base.o
	gcc test.o ft_atoi_base.o -o $(NAME)

test.o: test.c
	gcc test.c -c 

ft_atoi_base.o: ft_atoi_base.s
	nasm -f elf64 ft_atoi_base.s -o ft_atoi_base.o

all: $(NAME)

run:
	$(NAME)
clean:
	rm ft_atoi_base.o test.o
fclean: clean
	rm $(NAME)

re: fclean all
