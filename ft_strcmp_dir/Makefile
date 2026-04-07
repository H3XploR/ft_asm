NAME = test_ft_strcmp

$(NAME): test.o ft_strcmp.o
	gcc test.o ft_strcmp.o -o $(NAME)

test.o: test.c
	gcc test.c -c 

ft_strcmp.o: ft_strcmp.s
	nasm -f elf64 ft_strcmp.s -o ft_strcmp.o

all: $(NAME)

run:
	./$(NAME)
clean:
	rm ft_strcmp.o test.o
fclean: clean
	rm $(NAME)

re: fclean all
