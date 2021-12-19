#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd1;
	int		fd2;
	int		fd3;
	char	*s1;
	char	*s2;
	char	*s3;

	printf("\ntest start =====\n\n");
	if (argc == 2)
	{
		fd1 = open(argv[1], O_RDONLY);
		printf("#fd1 : %d#\n", fd1);
		printf("----------\n");
		do
		{
			s1 = get_next_line(fd1);
			printf("%s", s1);
			free(s1);
		} while (s1);
	}
	if (argc == 3)
	{
		fd1 = open(argv[1], O_RDONLY);
		fd2 = open(argv[2], O_RDONLY);
		printf("#fd1 : %d# #fd2 : %d#\n", fd1, fd2);
		printf("---------------------\n");
		do
		{
			s1 = get_next_line(fd1);
			printf("%4d : %s", fd1, s1);
			free(s1);

			s2 = get_next_line(fd2);
			printf("%4d : %s", fd2, s2);
			free(s2);
		} while (s1 || s2);
	}
	if (argc == 4)
	{
		fd1 = open(argv[1], O_RDONLY);
		fd2 = open(argv[2], O_RDONLY);
		fd3 = open(argv[3], O_RDONLY);
		printf("#fd1 : %d# #fd2 : %d# #fd3 : %d#\n", fd1, fd2, fd3);
		printf("--------------------------------\n");
		do
		{
			s1 = get_next_line(fd1);
			printf("%4d : %s", fd1, s1);
			free(s1);

			s2 = get_next_line(fd2);
			printf("%4d : %s", fd2, s2);
			free(s2);
			
			s3 = get_next_line(fd3);
			printf("%4d : %s", fd3, s3);
			free(s3);
		} while (s1 || s2 || s3);
	}
	printf("\n\n======= test end =========\n\n");
//	system("leaks a.out | grep -i leak | grep -v Tool");
	return (0);
}
