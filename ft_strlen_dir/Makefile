NAME = ft_strlen

$(NAME): test.o ft_strlen.o
	gcc test.o ft_strlen.o -o $(NAME)

test.o: test.c
	gcc test.c -c 

ft_strlen.o: ft_strlen.s
	nasm -f elf64 ft_strlen.s -o ft_strlen.o

all: $(NAME)

run:
	$(NAME)
clean:
	rm ft_strlen.o test.o
fclean: clean
	rm $(NAME)
