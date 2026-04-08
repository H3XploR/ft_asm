#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int	ft_read(int fd, const void* buf, int count);



int main(void) {
    int fd = 99;  // fd invalide
    char c = 0;
    int ret = ft_read(fd, &c, 1); //appel_err
    if (ret < 0) {
        printf("erreur : %s (errno = %d)\n", strerror(errno), errno);
    } 
    printf("\n\ntest write good with test.c\n");
    fd = open("test.c", O_RDONLY);
    for (int i = 0; i < 400; i++){
	    ft_read(fd, &c, 1);
	    printf("%c", c);
    }
    close(fd);
    return 0;
} 
