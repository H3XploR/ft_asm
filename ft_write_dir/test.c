#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int	ft_write(int fd, const void* buf, int count);



int main(void) {
    int fd = 99;  // fd invalide
    const char *msg = "hello\n";

    ssize_t ret =  ft_write(1, "oui\n", 4); //appel_valide
    
    ret = ft_write(fd, msg, 6); //appel_err
    if (ret < 0) {
        printf("erreur : %s (errno = %d)\n", strerror(errno), errno);
    }

    return 0;
} 
