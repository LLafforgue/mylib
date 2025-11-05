#include <stdlib.h>	

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*copy;
	char	*temp;

	if (!s)
		return (NULL);
	while (start-- && *s)
		s++;
	if (*s && len != 0)
	{
		copy = malloc((len + 1) * sizeof(char));
		if (!copy)
			return (NULL);
		temp = copy;
		while (len && *s)
		{
			*copy++ = *s++;
			len--;
		}
		*copy = '\0';
		return (temp);
	}
	copy = malloc(sizeof(char));
	if (!copy)
		return (NULL);
	*copy = '\0';
	return (copy);
}
/*
#include <stdio.h>
int main(void)
{
	char *s1 = "Hello 42!";
	char *s2 = ft_substr(s1, 5, 5);

	printf("%s\n", s2);
	free(s2);
}
*/