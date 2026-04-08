#include <stdio.h>

char*	ft_strdup(char*	src);
int	ft_strlen(char* src);

int main(void) {
	char	msg[6] = "voila";
	char*	dest = NULL;
	printf("before cpy: %s\n", dest);
	dest = ft_strdup(msg);
	printf("after cpy: %s\n", dest);
	//free(dest);
	return 0;
}
