#include <stdlib.h>

int	my_strlen(char *str);
char	*my_strcpy(char *dest, char *src);

static int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

char	*trim(char *str)
{
	int	start;
	int	end;
	int	i;
	int	len;
	char	*result;

	len = my_strlen(str);
	start = 0;
	while (start < len && is_space(str[start]))
		start++;
	end = len - 1;
	while (end >= start && is_space(str[end]))
		end--;
	result = malloc(end - start + 2);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (start <= end)
	{
		result[i] = str[start];
		i++;
		start++;
	}
	result[i] = '\0';
	return (result);
}

int main(void)
{
	return 0;
}
