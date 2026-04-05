define function_handle_procedure
	$(eval name_dir = $(1:%=%_dir))
	mkdir -p $(name_dir)

	$(eval name_obj = $(1:%=%.o))
	echo $(name_obj)
	mv $(name_obj) $(name_dir) || true 

	$(eval name_src = $(1:%=%.s))
	echo $(name_src)
	mv $(name_src) $(name_dir) || true 

endef 

define loop
	$(foreach var, $(list_function_name), $(call function_handle_procedure, $(var)))
endef

list_function_name = ft_strlen ft_strcpy ft_strcmp ft_write ft_read ft_strdup ft_atoi_base ft_list_push_front ft_list_size ft_list_sort ft_list_remove_if

list_function_source = $(list_function_name=:.s)

list_function_obj = $(list_function_name=:.o)

FT_STRLEN = ft_strlen

$(FT_STRLEN): main.o ft_strlen.o
	gcc main.o ft_strlen.o -o $(FT_STRLEN)

main.o: main.c
	gcc main.c -c 

ft_strlen.o: ft_strlen.s
	nasm -f elf64 ft_strlen.s -o ft_strlen.o


all:
	$(call loop)
run:
	$(FT_STRLEN)
clean:
	rm ft_strlen.o main.o
fclean: clean
	rm $(FT_STRLEN)
