#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>


int ft_strlen(char *s)
{
	char	*temp;

	temp = s;
	while (*s)
		s++;
	return (s - temp);
}

char	*ft_join(char *buff, char *str, int i, int len)
{
	char	*temp;
	char	*join;
	int		init;

	init = i;
	while (i < len && buff[i] != '\n')
		i++;
	join = malloc(sizeof(char) * (i - init + ft_strlen(str) + 1));
	if (!join)
		return (NULL);
	temp = join;
	while (*str)
		*join++ = *str++;
	while (init < len && buff[init] != '\n')
		*join++ = buff[init++];
	if (buff[init] == '\n')
		*join++ = buff[init];
	*join = '\0';
	return (temp);
}

int	ft_chek_line(char *str)
{
	while (*str)
	{
		if (*str++ == '\n')
			return (1);
	}
	return (0);
}

char *get_next_line(int fd)
{
	static char	buff[BUFF_SIZE];
	static int	byte_read;
	static int	i;
	char		*str;
	char		*temp;

	str = malloc(sizeof(char));
	if (!str)
		return (NULL);
	*str = '\0';
	if(byte_read && i < byte_read)
	{
		temp = str;
		str = ft_join(buff, str, i, byte_read);
		free (temp);
	}
	else
	{
		byte_read = read(fd, buff, BUFF_SIZE);
		temp = str;
		str = ft_join(buff, str, i, byte_read);
		free (temp);
	}
	while (byte_read > 0 && !ft_chek_line(str))
	{
		i = 0;
		byte_read = read(fd, buff, BUFF_SIZE);
		printf("[%s]->", buff);
		temp = str;
		str = ft_join(buff, str, i, byte_read);
		free(temp);
		if (byte_read == -1)
			free(str);
	}
	if (buff[i] != '\n')
		while (buff[i] != '\n' && i < byte_read)
			i++;
	else if (i < byte_read)
		i++;
	return (str);
}

int main()
{
	int		fd;
	int		cnt = 10;
	int		deb = 0;
	char	*line;

	fd = open("./test", O_RDONLY);
	while (deb < cnt)
	{
		line = get_next_line(fd);
		printf("main : %s-----\n", line);
		deb++;
	}
	close(fd);
	free(line);
}

// int main()
// {
// 	printf("%s-\n", ft_join(" \n ", "ok", 0, 0));
// }
