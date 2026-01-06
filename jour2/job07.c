#include <stdlib.h>
#include <unistd.h>

void to_lowercase(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
}

char *copy_string(char *src)
{
	int len;
	char *result;
	int i;

	len = 0;
	while (src[len] != 0)
		len++;
	
	result = malloc(len + 1);
	
	i = 0;
	while (src[i] != 0)
	{
		result[i] = src[i];
		i++;
	}
	result[i] = 0;
	
	return result;
}

int main(int argc, char **argv)
{
	int i;
	char *str;
	int len;

	i = 1;
	while (i < argc)
	{
		str = copy_string(argv[i]);
		to_lowercase(str);
		
		len = 0;
		while (str[len] != 0)
			len++;
		
		write(1, str, len);
		write(1, "\n", 1);
		
		free(str);
		i++;
	}
	
	return 0;
}
