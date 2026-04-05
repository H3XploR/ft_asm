list_function_name = ft_strlen ft_strcpy ft_strcmp ft_write ft_read ft_strdup ft_atoi_base ft_list_push_front ft_list_size ft_list_sort ft_list_remove_if
list_function_dir = $(list_function_name:%=%_dir)

all:
	@$(foreach var, $(list_function_dir), make -C $(var) || true)
run:
clean:
fclean: clean

re: fclean all
