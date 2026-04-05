NAME = ft_strlen_test

$(NAME): main.o ft_strlen.o
	gcc main.o ft_strlen.o -o $(NAME)

main.o: main.c
	gcc main.c -c 

ft_strlen.o: ft_strlen.s
	nasm -f elf64 ft_strlen.s -o ft_strlen.o

run:
	./ft_strlen_test
clean:
	rm ft_strlen.o main.o
fclean: clean
	rm $(NAME)
