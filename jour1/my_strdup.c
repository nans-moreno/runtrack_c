#include <stdlib.h>

int	my_strlen(char *str);
char	*my_strcpy(char *dest, char *src);

char	*my_strdup(char *str)
{
	char	*copy;
	int	length;

	length = my_strlen(str);
	copy = malloc(length + 1);
	if (copy == NULL)
		return (NULL);
	my_strcpy(copy, str);
	return (copy);
}
