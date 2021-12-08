#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	char	*str;
	char	*tmp;

	str = (char *)malloc(3);
	str[0] = 'a';
	str[1] = 'b';
	str[2] = '\0';

	printf("%s | %p\n", str, str);
	tmp = str;
	str = NULL;
	free(tmp);
	printf("%s | %p\n", str, str);
	system("leaks a.out | grep -i leak | grep -v Tool");
	return (0);
}
