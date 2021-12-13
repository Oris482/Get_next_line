#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*s1;

	s1 = ft_strdup("");
	free(s1);
	fd = open("./test.txt", O_RDONLY);
	s1 = get_next_line(fd);
	printf("%s", s1);
	free(s1);
	s1 = get_next_line(fd);
	printf("%s", s1);
	free(s1);
	s1 = get_next_line(fd);
	printf("%s", s1);
	free(s1);
	s1 = get_next_line(fd);
	printf("%s", s1);
	free(s1);
	s1 = get_next_line(fd);
	printf("%s", s1);
	free(s1);
	close(fd);
	s1 = get_next_line(fd);
	printf("%s", s1);
	free(s1);
	s1 = get_next_line(fd);
	printf("%s", s1);
	free(s1);
	system("leaks a.out | grep -i leak | grep -v Tool");
	return (0);
}
