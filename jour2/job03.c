#include <stdlib.h>

char **array_clone(char **array, int n)
{
	int i;
	int len;
	char **result;
	int count;

	count = 0;
	while (count < n && array[count] != 0)
		count++;
	
	result = malloc(sizeof(char *) * (count + 1));
	
	i = 0;
	while (i < count)
	{
		len = 0;
		while (array[i][len] != 0)
			len++;
		
		result[i] = malloc(len + 1);
		
		len = 0;
		while (array[i][len] != 0)
		{
			result[i][len] = array[i][len];
			len++;
		}
		result[i][len] = 0;
		
		i++;
	}
	result[count] = 0;
	
	return result;
}

int main(void)
{
	return 0;
}
