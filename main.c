#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>

extern size_t ft_strlen(const char* s);
extern int ft_strcmp(const char* s1, const char* s2);
extern char *ft_strcpy(char *restrict dst, const char *restrict src);
extern ssize_t ft_write(int fd, const void *buf, size_t count);


int main() {
    char *str1 = "ou\n";
    char *str2 = "oue\n";
    char str3[100];

    // strcmp
    printf(" - [strcmp] - \n");
    printf("ft_strcmp:    %d\n", ft_strcmp(str1, str2));
    printf("strcmp:       %d\n", strcmp(str1, str2));
    printf("\n");

    // strcpy
    printf(" - [strcpy] - \n");
    bzero(str3, 100);
    printf("ft_strcpy:    %s\n", ft_strcpy(str3, str2));
    bzero(str3, 100);
    printf("strcpy:       %s\n", strcpy(str3, str2));
    printf("\n");

    // strlen
    printf(" - [strlen] - \n");
    printf("ft_strlen:   %ld\n", ft_strlen(str1));
    printf("strlen:   %ld\n", strlen(str1));
    printf("\n");

    // write
    printf(" - [write] - \n");
    printf("ft_write:   %ld\nerrno:    %d\n", ft_write(5, str1, ft_strlen(str1)), errno);
    printf("write:   %ld\nerrno:    %d\n", write(5, str1, strlen(str1)), errno);
    printf("\n");

    // read
    return (EXIT_SUCCESS);
}