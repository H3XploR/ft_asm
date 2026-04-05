#include <stdio.h>

int	ft_strlen(const char* str);

int main(void){
	const char msg[6] = "voila";
	int len = ft_strlen(msg);
	printf("le chaine fait une taille de %d\n", len);
	//int null_len = ft_strlen(NULL);
	//printf("le chaine fait une taille de %d\n", null_len);
	return 0;
}
