#include <stdlib.h>
#include <stdio.h>

int ft_is_sep(char c, char *sep)
{
    while (*sep)
    {
        if (c == *sep)
            return (1);
        sep++;
    }
    return (0);
}

int ft_cnt_world(char *str, char *sep)
{
    int cnt;

    cnt = !ft_is_sep(*str, sep);
    while (*str)
    {
        if(ft_is_sep(*str, sep) && (!ft_is_sep(*str + 1, sep) && *(str + 1)))
            cnt ++;
        str++;
    }
    return (cnt);
}

char	*ft_strdup(char **str, char *charset)
{
	char	*dup;
	char	*temp;

	temp = *str;
	while (**str && !ft_is_sep(**str, charset))
		(*str)++;
	dup = malloc(sizeof(char) * ((*str) - temp + 1));
	if (!dup)
		return (NULL);
	*str = temp;
	temp = dup;
	while (**str && !ft_is_sep(**str, charset))
	{
		*dup++ = **str;
		(*str)++;
	}
	*dup = '\0';
	return (temp);
}

char **ft_split(char *s, char *charset)
{
    char **split;
    int len;

    if (!s)
        return (NULL);
    len = ft_cnt_world(s, charset);
    split = malloc(sizeof(char*) * (len + 1));
    if (!split)
        return (NULL);
    len = 0;
    while (*s)
    {
        while (ft_is_sep(*s, charset))
            s++;
        if (*s)
            split[len++] = ft_strdup(&s, charset);
    }
    split[len] = NULL;
    return (split);
}

void print_split(char **split) {
    printf("[");
    while (*split) {
        printf("\"%s\"", *split);
        split++;
        if (*split)
            printf(", ");
    }
    printf("]\n");
}

void test_ft_split(char *s, char *sep) {
    printf("Chaine : \"%s\", Separateurs : \"%s\"\n", s, sep);
    char **split = ft_split(s, sep);
    if (!split) {
        printf("Erreur d'allocation ou chaine NULL.\n");
        return;
    }
    print_split(split);

    // Libérer la mémoire allouée
    int i = 0;
    while (split[i])
        free(split[i++]);
    free(split);
}

int main(void) {

    // Cas 4 : Séparateurs au début et à la fin
    test_ft_split("bonjour tout le monde   ", " ");

    // Cas 5 : Chaîne vide
    test_ft_split("", " ");

    // Cas 6 : Aucun séparateur
    test_ft_split("bonjourtoutlemonde", " ");

    // Cas 7 : Séparateurs variés (espace, tabulation, nouvelle ligne)
    test_ft_split("bonjour\t tout\nle monde", " \t\n");

    // Cas 8 : Chaîne avec seulement des séparateurs
    test_ft_split("   ", " ");

    // Cas 9 : NULL comme chaîne
    test_ft_split(NULL, " ");

    return 0;
}