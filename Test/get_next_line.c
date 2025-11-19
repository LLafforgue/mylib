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

void	ft_join(char *buff, char **str, int i, int len)
{
	char	*temp;
	char	*copy;
	char	*join;
	int		init;

	copy = *str;
	init = i;
	while (i < len && buff[i] != '\n')
		i++;
	i += buff[i] == '\n';
	join = malloc(sizeof(char) * (i - init + ft_strlen(copy) + 1));
	if (!join)
		return ;
	temp = join;
	while (*copy)
		*join++ = *copy++;
	while (init < len && buff[init] != '\n')
		*join++ = buff[init++];
	if (buff[init] == '\n')
		*join++ = buff[init];
	*join = '\0';
	*str = temp;
	free(copy);
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

int	ft_finish(char *buff, int i, int len)
{
	if (buff[i] != '\n')
	{
		while (buff[i] != '\n' && i < len)
			i++;
		if (i < len)
			i++;
	}
	else if (i < len)
			i++;
	return (i);
}

char *get_next_line(int fd)
{
	static char	buff[BUFF_SIZE];
	static int	byte_read;
	static int	i;
	char		*str;

	str = malloc(sizeof(char));
	if (!str)
		return (NULL);
	*str = '\0';
	if(byte_read && i < byte_read)
		ft_join(buff, &str, i, byte_read);
	else if (!byte_read)
	{
		byte_read = read(fd, buff, BUFF_SIZE);
		ft_join(buff, &str, i, byte_read);
	}
	while (byte_read > 0 && !ft_chek_line(str))
	{
		i = 0;
		byte_read = read(fd, buff, BUFF_SIZE);
		ft_join(buff, &str, i, byte_read);
		if (byte_read == -1)
			free(str);
	}
	i = ft_finish(buff, i, byte_read);
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
		printf("l%d : %s-----\n", deb, line);
		deb++;
		free(line);
	}
	close(fd);
}

// int main()
// {
// 	printf("%s-\n", ft_join(" \n ", "ok", 0, 0));
// }
