#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*temp;

	temp = (unsigned char *)s;
	while (n > 0)
	{
		*temp = 0;
		temp++;
		n--;
	}
}

void	ft_memmovei(void *src, size_t idx, size_t len)
{
	unsigned char		*tmp_dst;
	const unsigned char	*tmp_src;
	size_t				init_len;

	if (src == NULL)
		return ;
	init_len = len;
	tmp_dst = (unsigned char *)src;
	tmp_src = (const unsigned char *)(src + idx);
	while (len - idx  > 0)
	{
		*tmp_dst++ = *tmp_src++;
		len--;
	}
	ft_bzero(src + init_len - idx, idx);
}

int	main(void)
{
	char	s1[5] = "abcde";
	printf("%s\n", s1);
	ft_memmovei(s1, 5, 5);
	printf("%s\n", s1);
	return (0);
}
