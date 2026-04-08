NAME = test_ft_read

$(NAME): test.o ft_read.o
	gcc test.o ft_read.o -o $(NAME)

test.o: test.c
	gcc test.c -c 

ft_read.o: ft_read.s
	nasm -f elf64 ft_read.s -o ft_read.o

all: $(NAME)

run:
	./$(NAME)
clean:
	rm ft_read.o test.o
fclean: clean
	rm $(NAME)

re: fclean all
