NAME = test_ft_strcpy

$(NAME): test.o ft_strcpy.o
	gcc test.o ft_strcpy.o -o $(NAME)

test.o: test.c
	gcc test.c -c 

ft_strcpy.o: ft_strcpy.s
	nasm -f elf64 ft_strcpy.s -o ft_strcpy.o

all: $(NAME)

run:
	./$(NAME)

clean:
	rm ft_strcpy.o test.o

fclean: clean
	rm $(NAME)

re: fclean all
