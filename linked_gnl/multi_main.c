#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int 	fd1;
	int 	fd2;
	int 	fd3;
	char	*s1;

	fd1 = open("./41_with_nl", O_RDONLY);
	fd2 = open("./multi2.txt", O_RDONLY);
	fd3 = open("./multi3.txt", O_RDONLY);
	s1 = get_next_line(fd1);
	printf("%s", s1);
	free(s1);
	s1 = get_next_line(fd2);
	printf("%s", s1);
	free(s1);
	s1 = get_next_line(fd3);
	printf("%s", s1);
	free(s1);
	s1 = get_next_line(fd1);
	printf("%s", s1);
	free(s1);
	s1 = get_next_line(fd2);
	printf("%s", s1);
	free(s1);
	s1 = get_next_line(fd3);
	printf("%s", s1);
	free(s1);
	s1 = get_next_line(fd1);
	printf("%s", s1);
	free(s1);
	s1 = get_next_line(fd2);
	printf("%s", s1);
	free(s1);
	s1 = get_next_line(fd3);
	printf("%s", s1);
	free(s1);
	system("leaks a.out | grep -i leak | grep -v Tool");
	return (0);
}
