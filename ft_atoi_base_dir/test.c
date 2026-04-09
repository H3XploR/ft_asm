#include <stdio.h>

int	ft_atoi_base(char *str, char *base);

int	main(void){
	char msg[6] = "53";
	char base_10[11] = "0123456789";
	int numb = ft_atoi_base(msg, base_10);
	printf("avec \"%s\", atoi_base a returner le numero: %d en base 10\n\n", msg, numb);


	char out_base[2] = "a";
	printf("test avec character (%s) qui n'appartient pas a la base (%s)\n", out_base, base_10);
	numb = ft_atoi_base(out_base, base_10); printf("numb = %d\n\n", numb);


	printf("test avec une chaine vide en premier argument\n");
	numb = ft_atoi_base("", base_10); printf("numb = %d\n\n", numb);

	printf("test avec une chaine vide en deuxieme argument\n");
	numb = ft_atoi_base("", base_10); printf("numb = %d\n\n", numb);

	printf("test avec deux chaine vide en  argument\n");
	numb = ft_atoi_base("", ""); printf("numb = %d\n\n", numb);

	printf("test avec une valeur negative\n");
	numb = ft_atoi_base("-8", "0123456789"); printf("numb = %d\n\n", numb);

	printf("test avec une valeur negative entre 100 et 1000\n");
	numb = ft_atoi_base("-889", "0123456789"); printf("numb = %d\n\n", numb);

	printf("test avec plusieurs moins devant\n");
	numb = ft_atoi_base("--889", "0123456789"); printf("numb = %d\n\n", numb);

	printf("test avec un moins au milieu du numero\n");
	numb = ft_atoi_base("8-89", "0123456789"); printf("numb = %d\n\n", numb);

	printf("test avec un moins au milieu du numero\n");
	numb = ft_atoi_base("88-9", "0123456789"); printf("numb = %d\n\n", numb);

	printf("test avec un moins a la fin du numero\n");
	numb = ft_atoi_base("889-", "0123456789"); printf("numb = %d\n\n", numb);

	printf("test avec juste un moins\n");
	numb = ft_atoi_base("-", "0123456789"); printf("numb = %d\n\n", numb);

	printf("test avec plusieurs moins\n");
	numb = ft_atoi_base("--", "0123456789"); printf("numb = %d\n\n", numb);
	numb = ft_atoi_base("---", "0123456789"); printf("numb = %d\n\n", numb);
	numb = ft_atoi_base("----", "0123456789"); printf("numb = %d\n\n", numb);

	printf("test avec un \"+\" devant\n");
	numb = ft_atoi_base("+12", "0123456789"); printf("numb = %d\n\n", numb);

	printf("test avec plusieurs plus\n");
	numb = ft_atoi_base("++", "0123456789"); printf("numb = %d\n\n", numb);
	numb = ft_atoi_base("+++", "0123456789"); printf("numb = %d\n\n", numb);
	numb = ft_atoi_base("++++", "0123456789"); printf("numb = %d\n\n", numb);

	printf("test avec plusieurs plus devant\n");
	numb = ft_atoi_base("++889", "0123456789"); printf("numb = %d\n\n", numb);

	printf("test avec un plus au milieu du numero\n");
	numb = ft_atoi_base("8+89", "0123456789"); printf("numb = %d\n\n", numb);

	printf("test avec un plus au milieu du numero\n");
	numb = ft_atoi_base("88+9", "0123456789"); printf("numb = %d\n\n", numb);

	printf("test avec un plus a la fin du numero\n");
	numb = ft_atoi_base("889+", "0123456789"); printf("numb = %d\n\n", numb);

	return 0;
}
