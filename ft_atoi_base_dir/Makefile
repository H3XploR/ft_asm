NAME = test_ft_atoi_base
DEPENDANCE = ../ft_strlen_dir/ft_strlen.o

$(NAME): test.o ft_atoi_base.o $(DEPENDANCE)
	gcc test.o ft_atoi_base.o $(DEPENDANCE) -o $(NAME)

test.o: test.c
	gcc -g test.c -c 

ft_atoi_base.o: ft_atoi_base.s
	nasm -f elf64 ft_atoi_base.s -o ft_atoi_base.o

$(DEPENDANCE):
	make -C $(dir $(DEPENDANCE)) all || true

all: $(NAME)

run:
	./$(NAME)

val:
	valgrind -s ./$(NAME)

clean:
	rm ft_atoi_base.o test.o
fclean: clean
	rm $(NAME)

re: fclean all
