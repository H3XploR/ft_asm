#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int	ft_strcmp(char* s1, char* s2);

int main(void) {
    char *ch1 = "hello\n";
    char *ch2 = "bonjour\n";

    int ret = ft_strcmp(ch1, ch2);
    printf("ret = %d\n", ret);
    return 0;
} 
