#include <stdio.h>
#include <string.h>

int	ft_atoi_base(char *str, char *base);

static char    *itoa(int n, char *str, int base)
{
    int     len;
    int     neg;
    long    nb;

    len = 0;
    neg = 0;
    nb = n;
    if (nb < 0 && base == 10)
    {
        neg = 1;
        nb = -nb;
    }
    if (nb == 0)
        len = 1;
    else
    {
        long tmp = nb;
        while (tmp > 0)
        {
            tmp /= base;
            len++;
        }
    }
    if (neg)
        len++;
    str[len] = '\0';
    if (nb == 0)
        str[0] = '0';
    else
    {
        int i = len - 1;
        while (nb > 0)
        {
            int rem = nb % base;
            str[i--] = (rem < 10) ? '0' + rem : 'a' + rem - 10;
            nb /= base;
        }
        if (neg)
            str[0] = '-';
    }
    return (str);
}

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

	printf("boucle positif\n");
	char cnb[4];
	cnb[4] = 0;
	memset(cnb, '0', 3);
	while (cnb[0] <= '1'){
		cnb[1] = '0';
		while (cnb[1] <= '9'){
			cnb[2] = '0';
			while (cnb[2] <= '9'){
				numb = ft_atoi_base(cnb, base_10); printf("numb = %d\n", numb);
				cnb[2]++;
			}
			cnb[1]++;
		}
		cnb[0]++;
	}
	printf("boucle negative\n");
	int	neg_nb = 0;
	char	neg_nb_char[5];
	int	ret = 0;
	memset(neg_nb_char, '0', 5);
	while (neg_nb >= -100){
		itoa(neg_nb, neg_nb_char, 10);
		ret = ft_atoi_base(neg_nb_char, base_10); printf("ret = %d\n", ret);
		neg_nb--;
	}

	printf("test avec un \"moins\" dans la base\n");
        numb = ft_atoi_base("5", "012345-789"); printf("numb = %d\n\n", numb);

        printf("test avec un \"plus\" dans la base\n");
        numb = ft_atoi_base("5", "012345+789"); printf("numb = %d\n\n", numb);

        printf("test avec un \"-\" dans la base et dans le nombre\n");
        numb = ft_atoi_base("-5", "012345-789"); printf("numb = %d\n\n", numb);

        printf("test avec un \"+\" dans la base et dans le nombre\n");
        numb = ft_atoi_base("+5", "012345+789"); printf("numb = %d\n\n", numb);

        printf("test avec la base qui contient deux fois le meme caractere\n");
        numb = ft_atoi_base("5", "0123456789"); printf("numb = %d\n\n", numb);
        numb = ft_atoi_base("5", "01234556789"); printf("numb = %d\n\n", numb);

        printf("test avec la base qui contient un espace\n");
        numb = ft_atoi_base("5", "01234 6789"); printf("numb = %d\n\n", numb);

        printf("test avec le nombre qui contient un espace\n");
        numb = ft_atoi_base("5 6", "0123456789"); printf("numb = %d\n\n", numb);

        printf("test avec espaces avant le nombre\n");
        numb = ft_atoi_base("   56", "0123456789"); printf("numb = %d\n\n", numb);

        printf("test avec tab avant le nombre\n");
        numb = ft_atoi_base("\t56", "0123456789"); printf("numb = %d\n\n", numb);

        printf("test avec newline avant le nombre\n");
        numb = ft_atoi_base("\n56", "0123456789"); printf("numb = %d\n\n", numb);

        printf("test base binaire\n");
        numb = ft_atoi_base("1010", "01"); printf("numb = %d\n\n", numb);

        printf("test base hexadecimale\n");
        numb = ft_atoi_base("ff", "0123456789abcdef"); printf("numb = %d\n\n", numb);
        numb = ft_atoi_base("FF", "0123456789ABCDEF"); printf("numb = %d\n\n", numb);

        printf("test base a un seul caractere (invalide)\n");
        numb = ft_atoi_base("0", "0"); printf("numb = %d\n\n", numb);
	return 0;
}
