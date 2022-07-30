/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabentay <nabentay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 00:27:54 by nabentay          #+#    #+#             */
/*   Updated: 2022/07/14 15:41:09 by nabentay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>

size_t	ft_strlen(const char *s);
char *	ft_strcpy(char * dst, const char * src);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_write(int fildes, const void *buf, size_t nbyte);
size_t	ft_read(int fildes, void *buf, size_t nbyte);
char	*ft_strdup(const char *s);

void	ft_print_num(char *funcolor, char *rescolor, char *fun, size_t x, size_t x2)
{
	printf("%s%s\033[0m: %s%ld\033[0m",funcolor, fun, rescolor, x);
	printf(", %sft_%s\033[0m: %s%ld\033[0m",  funcolor, fun, rescolor, x2);
	if (x == x2)
		printf("\033[38;5;10m  OK\033[0m\n");
	else
		printf("\033[38;5;124m  KO\033[0m\n");
}

void	ft_print_str(char *funcolor, char *rescolor, char *fun, char *x, char *x2)
{
	printf("%s%s\033[0m: %s%s\033[0m",funcolor, fun, rescolor, x);
	printf(", %sft_%s\033[0m: %s%s\033[0m",  funcolor, fun, rescolor, x2);
	if (strcmp(x, x2) == 0)
		printf("\033[38;5;10m  OK\033[0m\n");
	else
		printf("\033[38;5;124m  KO\033[0m\n");
}

void	ft_strlen_test(void)
{
	int		i = -1;
	char	buff[2100000];

	while(++i < 2100000)
		buff[i] = 'a';
	buff[i] = '\0';
	printf("\n\033[48;5m========== FT_STRLEN ==========\033[0m\n");
	ft_print_num("\033[38;5;156m", "\033[38;5;147m", "strlen", strlen(""), ft_strlen(""));
	ft_print_num("\033[38;5;156m", "\033[38;5;147m", "strlen", strlen("1"), ft_strlen("1"));
	ft_print_num("\033[38;5;156m", "\033[38;5;147m", "strlen", strlen("Hello"), ft_strlen("Hello"));
	ft_print_num("\033[38;5;156m", "\033[38;5;147m", "strlen", strlen("$Hello World$"), ft_strlen("$Hello World$"));
	ft_print_num("\033[38;5;156m", "\033[38;5;147m", "strlen", strlen(buff), ft_strlen(buff));
}

void	ft_strcpy_test(void)
{
	char buff[6];
	char buff2[6];

	printf("\n\033[48;5m========== FT_STRCPY ==========\033[0m\n");
	ft_print_str("\033[38;5;156m", "\033[38;5;147m", "strcpy RET", strcpy(buff, "Hello"), ft_strcpy(buff2, "Hello"));
	ft_print_str("\033[38;5;156m", "\033[38;5;147m", "strcpy BUF", buff, buff2);
	ft_print_str("\033[38;5;156m", "\033[38;5;147m", "strcpy RET", strcpy(buff, ""), ft_strcpy(buff2, ""));
	ft_print_str("\033[38;5;156m", "\033[38;5;147m", "strcpy BUF", buff, buff2);
}

void	ft_strcmp_test(void)
{
	printf("\n\033[48;5m========== FT_STRCMP ==========\033[0m\n");
	ft_print_num("\033[38;5;156m", "\033[38;5;147m", "strcmp", strcmp("Hello", "Hello"), ft_strcmp("Hello", "Hello"));
	ft_print_num("\033[38;5;156m", "\033[38;5;147m", "strcmp", strcmp("Hello", "H"), ft_strcmp("Hello", "H"));
	ft_print_num("\033[38;5;156m", "\033[38;5;147m", "strcmp", strcmp("Hel", "Pomme"), ft_strcmp("Hel", "Pomme"));
}

void	ft_write_test(void)
{
	printf("\n\033[48;5m========== FT_WRITE ==========\033[0m\n");

	ft_print_num("\033[38;5;156m", "\033[38;5;147m", "write RET", write(1, "Hey", 3), ft_write(1, "Hey", 3));
	ft_print_num("\033[38;5;156m", "\033[38;5;147m", "write RET", write(1, "", 0), ft_write(1, "", 0));
	ft_print_num("\033[38;5;156m", "\033[38;5;147m", "write RET", write(1, NULL, 0), ft_write(1, NULL, 0));
	printf("ERRNO: %d\n", errno);
	printf("TEST: %ld\n", ft_write(999999, "Hello", 5)); // Must be 9 - EBADF Bad file descriptor
	printf("ERRNO: %d", errno);
	if (errno == 9)
		printf("\033[38;5;10m  OK\033[0m\n");
	else
		printf("\033[38;5;124m  KO\033[0m\n");
}

void	ft_read_test(void)
{
	char buff[20], buff2[20];
	int	fd, fd2;

	fd = open("testfile", O_RDONLY);
	fd2 = open("testfile", O_RDONLY);
	bzero(buff, 20);
	bzero(buff2, 20);
	printf("\n\033[48;5m========== FT_READ ==========\033[0m\n");
	ft_print_num("\033[38;5;156m", "\033[38;5;147m", "read RET", read(fd, buff, 20), ft_read(fd2, buff2, 20));
	ft_print_str("\033[38;5;156m", "\033[38;5;147m", "read BUF", buff, buff2);
	printf("ERRNO: %d\n", errno);
	printf("TEST: %ld\n", ft_read(fd, buff, -1)); // Must be 14 - EFAULT Bad address.
	printf("ERRNO: %d", errno);
	if (errno == 14)
		printf("\033[38;5;10m  OK\033[0m\n");
	else
		printf("\033[38;5;124m  KO\033[0m\n");
	close(fd);
	close(fd2);
}

void	ft_strdup_test(void)
{
	char	*_1;
	char	*ft_1;
	char	*_2;
	char	*ft_2;

	_1 = strdup("Hello");
	ft_1 = ft_strdup("Hello");
	_2 = strdup("");
	ft_2 = ft_strdup("");
	printf("\n\033[48;5m========== FT_STRDUP ==========\033[0m\n");
	ft_print_str("\033[38;5;156m", "\033[38;5;147m", "strdup RET", _1, ft_1);
	ft_print_str("\033[38;5;156m", "\033[38;5;147m", "strdup RET", _2, ft_2);
	free(_1);
	free(ft_1);
	free(_2);
	free(ft_2);
}

int	main(void)
{
	printf("\033[48;5m========== LIBASM ==========\033[0m\n");
	ft_strlen_test();
	ft_strcpy_test();
	ft_strcmp_test();
	ft_write_test();
	ft_read_test();
	ft_strdup_test();
}
