#include <libc.h>

#include "./../get_next_line.h"

int main(int ac, char **av)
{
	printf("\ntest start =====\n\n");
	(void)av;
	char *s = NULL;
	char *s1;
	char *s2;

	if (ac == 1)
	{
		s = get_next_line(0);
		printf("%s", s);
		free(s);
	}
	else if (ac == 2)
	{
		int fd = open(av[1], O_RDONLY);
		do
		{
			s = get_next_line(fd);
			printf("%4d : %s", fd, s);
			free(s);
		} while (s);
	}
	else if (ac == 3)
	{
		int fd2 = open(av[1], O_RDONLY);
		int fd3 = open(av[2], O_RDONLY);
		printf("fd1 : %d\nfd2 : %d\n", fd2, fd3);
		do
		{
			s1 = get_next_line(fd2);
			printf("%4d : %s", fd2, s1);
			free(s1);

			s2 = get_next_line(fd3);
			printf("%4d : %s", fd3, s2);
			free(s2);
		} while (s2 || s1);
	}
	printf("\n\n======= test end =========\n\n");
	return (0);
}
