#include <stdio.h>

int	ft_atoi_base(char *str, char *base);

int	main(void){
	char msg[6] = "53";
	char base_10[10] = "0123456789";
	int numb = ft_atoi_base(msg, base_10);
	printf("avec \"%s\", atoi_base a returner le numero: %d en base 10\n", msg, numb);


	char out_base[2] = "a";
	printf("test avec character (%s) qui n'appartient pas a la base (%s)\n", out_base, base_10);
	numb = ft_atoi_base(out_base, base_10);
	return 0;
}
