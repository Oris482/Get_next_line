#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

int	main(void)
{
	int	fd[20000];
	int	idx;
	char	*s1;

	s1 = ft_strdup("");
	free(s1);
	idx = 3;
	while(idx < 20003)
	{
		fd[idx - 3] = open("./heyyy", O_RDONLY);
		s1 = get_next_line(fd[idx - 3]);
		if (fd[idx - 3] == idx && !strcmp(s1, "heyyy"))
			printf("%d ", idx - 2);
		free(s1);
		idx++;
	}
	return (0);
}
