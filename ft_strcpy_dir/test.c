#include <stdio.h>

char*	ft_strcpy(char*	dest, char* src);

int main(void) {
	char msg[6] = "voila";
	char dest[6] = "12345";
	printf("before cpy: %s\n", dest);
	char* new_string = ft_strcpy(dest, msg);
	printf("after cpy: %s\n", dest);
	return 0;
}
