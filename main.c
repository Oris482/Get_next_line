#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*s1;

	fd = open("./test.txt", O_RDONLY);
	while (s1)
	{
		s1 = get_next_line(fd);
		printf("%s\n", s1);
	}
	return (0);
}
