NAME = test_ft_write

$(NAME): test.o ft_write.o
	gcc test.o ft_write.o -o $(NAME)

test.o: test.c
	gcc test.c -c 

ft_write.o: ft_write.s
	nasm -f elf64 ft_write.s -o ft_write.o

all: $(NAME)

run:
	./$(NAME)
clean:
	rm ft_write.o test.o
fclean: clean
	rm $(NAME)

re: fclean all
