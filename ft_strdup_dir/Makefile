NAME = test_ft_strdup
DEPENDANCE = ../ft_strlen_dir/ft_strlen.o


$(NAME): test.o ft_strdup.o $(DEPENDANCE)
	gcc test.o ft_strdup.o $(DEPENDANCE) -o $(NAME)

test.o: test.c
	gcc test.c -c 

ft_strdup.o: ft_strdup.s
	nasm -f elf64 ft_strdup.s -o ft_strdup.o

$(DEPENDANCE):
	make -C $(dir $(DEPENDANCE)) all || true

all: $(NAME)

run:
	./$(NAME)

clean:
	rm ft_strdup.o test.o
	make -C $(dir $(DEPENDANCE)) clean || true

fclean: clean
	rm $(NAME)
	make -C $(dir $(DEPENDANCE)) fclean || true

re: fclean all
	make -C $(dir $(DEPENDANCE)) re || true
