#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <fcntl.h>

size_t ft_strlen(const char *s);
int ft_strcmp(const char *s1, const char *s2);
char *ft_strcpy(char *restrict dst, const char *restrict src);
ssize_t ft_write(int fd, const void *buf, size_t count);
ssize_t ft_read(int fd, void *buf, size_t count);
char *ft_strdup(const char *s);


int main() {
	int fd_ft;
	int fd_std;
	int cmp_ft;
	int cmp_std;
	size_t len_ft;
	size_t len_std;
	ssize_t read_ft;
	ssize_t read_std;
	ssize_t write_ft;
	ssize_t write_std;
	char *dup_ft;
	char *dup_std;
	int errno_ft;
	int errno_std;
	char buffer_ft[256];
	char buffer_std[256];

	// strcmp
	printf("\n\n--------------------- [STRCMP] --------------------- \n\n");

	// Test 1 s1 == s2
	printf("[Test 1 s1 == s2]\n\n");
	printf("String1: \"Bonjour Bonsoir\", String2: \"Bonjour Bonsoir\"\n\n");

	cmp_ft = ft_strcmp("Bonjour Bonsoir", "Bonjour Bonsoir");
	cmp_std = strcmp("Bonjour Bonsoir", "Bonjour Bonsoir");

	printf("%s %d\n", "ft_strcmp	=>", cmp_ft);
	printf("%s %d\n", "strcmp		=>", cmp_std);

	// Test 2 s1 < s2
	printf("\n[Test 2 s1 < s2]\n\n");
	printf("String1: \"Bonjour\", String2: \"Bonsoir\"\n\n");

	cmp_ft = ft_strcmp("Bonjour", "Bonsoir");
	cmp_std = strcmp("Bonjour", "Bonsoir");

	printf("%s %d\n", "ft_strcmp	=>", cmp_ft);
	printf("%s %d\n","strcmp		=>", cmp_std);

	// Test 3 s1 > s2
	printf("\n[Test 3 s1 > s2]\n\n");
	printf("String1: \"Bonsoir\", String2: \"Bonjour\"\n\n");

	cmp_ft = ft_strcmp("Bonsoir", "Bonjour");
	cmp_std = strcmp("Bonsoir", "Bonjour");

	printf("%s %d\n", "ft_strcmp	=>", cmp_ft);
	printf("%s %d\n","strcmp		=>", cmp_std);

	// strcpy
	printf("\n\n --------------------- [STRCPY] --------------------- \n\n");

	// Test 1
	printf("[Test 1]\n\n");
	printf("String: \"Don't panic !\"\n\n");

	ft_strcpy(buffer_ft, "Don't panic !");
	strcpy(buffer_std, "Don't panic !");

	printf("%s %s\n", "buffer_ft  =>", buffer_ft);
	printf("%s %s\n", "buffer_std =>", buffer_ft);


	// strlen
	printf("\n\n --------------------- [STRLEN] --------------------- \n\n");

	// Test 1 basic string
	printf("[Test 1 basic string]\n\n");
	printf("String: \"Ceci est un test\"\n\n");

	len_ft = ft_strlen("Ceci est un test");
	len_std = strlen("Ceci est un test");

	printf("%s %ld\n", "ft_strlen =>", len_ft);
	printf("%s %ld\n", "strlen    =>", len_std);

	// Test 2 empty string
	printf("\n[Test 2 empty string]\n\n");
	printf("String: \"\"\n");

	len_ft = ft_strlen("");
	len_std = strlen("");

	printf("%s %ld\n", "ft_strlen =>", len_ft);
	printf("%s %ld\n", "strlen    =>", len_std);


    // write
	printf("\n\n --------------------- [WRITE] --------------------- \n\n");

	// Test 1 classic write
	printf("[Test 1 classic write]\n\n");
	write_ft = ft_write(1, "Hello World !\n", strlen("Hello World !\n"));
	errno_ft = errno;
	write_std = write(1, "Hello World !\n", strlen("Hello World !\n"));
	errno_std = errno;

	printf("\nft_write => %ld, errno: %d\n", write_ft, errno_ft);
	printf("write => %ld, errno: %d\n\n", write_std, errno_std);


	// Test 2 set size
	printf("[Test 2 set size]\n\n");

	write_ft = ft_write(1, "Hello\n World !\n", 6);
	errno_ft = errno;
	write_std = write(1, "Hello\n World !\n\n", 6);
	errno_std = errno;

	printf("\nft_write => %ld, errno: %d\n", write_ft, errno_ft);
	printf("write => %ld, errno: %d\n\n", write_std, errno_std);

	// Test 3 bad fd
	printf("[Test 3 bad fd]\n");

	write_ft = ft_write(42, "Houston, we have a problem !\n", strlen("Houston, we have a problem !\n"));
	errno_ft = errno;
	write_std = write(42, "Houston, we have a problem !\n", strlen("Houston, we have a problem !\n"));
	errno_std = errno;

	printf("\nft_write => %ld, errno: %d\n", write_ft, errno_ft);
	printf("write => %ld, errno: %d\n", write_std, errno_std);
	errno = 0;

	// read
	printf("\n\n --------------------- [READ] --------------------- \n\n");

	bzero(buffer_ft, 256);
	bzero(buffer_std, 256);

	// Test 1 classic read
	printf("[Test 1 classic read]\n\n");

	fd_ft = open("textFile.ber", O_RDONLY);
	fd_std = open("textFile.ber", O_RDONLY);

	read_ft = ft_read(fd_ft, buffer_ft, 26);
	errno_ft = errno;
	read_std = read(fd_std, buffer_std, 26);
	errno_std = errno;

	printf("Reading the first 26 characters of \'textFile.ber\'\n\n");
	printf("buffer_ft  => %s\n", buffer_ft);
	printf("buffer_std => %s\n\n", buffer_std);

	printf("ft_read => %ld, errno: %d\n", read_ft, errno_ft);
	printf("read    => %ld, errno: %d\n", read_std, errno_std);

	close(fd_ft);
	close(fd_std);

	bzero(buffer_ft, sizeof(buffer_ft));
	bzero(buffer_std, sizeof(buffer_std));

	// Test 2 bad fd
	printf("\n\n[Test 2 Reading invalid fd]\n\n");

	read_ft = ft_read(42, buffer_ft, 26);
	errno_ft = errno;
	read_std = read(42, buffer_std, 26);
	errno_std = errno;

	printf("buffer_ft  => %s\n", buffer_ft);
	printf("buffer_std => %s\n\n", buffer_std);

	printf("ft_read => %ld, errno: %d\n", read_ft, errno_ft);
	printf("read    => %ld, errno: %d\n", read_std, errno_std);
	errno = 0;

	//strdup
	printf("\n\n --------------------- [STRDUP] --------------------- \n\n");

	// Test 1 basic string
	printf("[Test 1 basic string]\n\n");

	dup_ft = ft_strdup("Ceci est un test !");
	errno_ft = errno;
	dup_std = strdup("Ceci est un test !");
	errno_std = errno;

	printf("ft_strdup => %p %s, errno: %d\n", (void *)dup_ft, dup_ft, errno_ft);
	printf("strdup => %p %s, errno: %d\n", (void *)dup_std, dup_std, errno_std);

	free(dup_ft);
	free(dup_std);

	// Test 2 empty string
	printf("\n\n[Test 2 empty string]\n\n");

	dup_ft = ft_strdup("");
	errno_ft = errno;
	dup_std = strdup("");
	errno_std = errno;

	printf("ft_strdup => %p %s, errno: %d\n", (void *)dup_ft, dup_ft, errno_ft);
	printf("strdup => %p %s, errno: %d\n\n", (void *)dup_std, dup_std, errno_std);

	free(dup_ft);
	free(dup_std);

	return (0);
}