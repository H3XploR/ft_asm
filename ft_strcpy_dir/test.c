#include <stdio.h>

char*	ft_strcpy(char*	dest, char* src);

int main(void) {
	char msg[6] = "voila";
	char dest[6] = "12345";
	printf("before cpy: %s\n", dest);
	char* ptr = ft_strcpy(dest, msg);
	printf("after cpy: %s\n", dest);
	printf("after cpy with ptr: %s\n", ptr);
	//printf("test avec NULL\n");
	//char* null_str = NULL;
	//ft_strcpy(dest, null_str);
	//ft_strcpy(null_str, dest);
	return 0;
}
