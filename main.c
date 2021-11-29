#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	buf[BUFFER_SIZE];

	fd = open("./test", O_RDONLY);
	while(read(fd, buf, sizeof(buf)));
	printf("%s\n", buf);
	close(fd);
	return (0);
}
