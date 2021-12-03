#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	char	s1[5] = "abcde";
	char	s2[8];
	int		fd;
	size_t	isin;

	fd = open("./test.txt", O_RDONLY);
	read(fd, s2, 8);
	printf("%s\n", s1);
	ft_memmovei(s1, 3, 5);
	printf("%s\n", s1);
	isin = ft_isinnl(s2, 8);
	printf("%s\nnl = %zu\n", s2, isin);
	return (0);
}
