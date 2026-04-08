#include <stdio.h>

int	ft_atoi_base(char *str, char *base);

int	main(void){
	const char msg[6] = "53";
	int numb = ft_atoi_base(msg, "0123456789");
	printf("avec \"%s\", atoi_base a returner le numero: %d en base 10\n", msg, numb);
	return 0;
}
