#include <stdlib.h>
#include <unistd.h>

int is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return 1;
	return 0;
}

int trim_length(char *str)
{
	int start;
	int end;
	int i;

	start = 0;
	while (str[start] != 0 && is_space(str[start]))
		start++;
	
	if (str[start] == 0)
		return 0;
	
	end = start;
	i = start;
	while (str[i] != 0)
	{
		if (!is_space(str[i]))
			end = i;
		i++;
	}
	
	return end - start + 1;
}

char *trim_string(char *str)
{
	int start;
	int end;
	int i;
	int len;
	char *result;
	int j;

	start = 0;
	while (str[start] != 0 && is_space(str[start]))
		start++;
	
	if (str[start] == 0)
	{
		result = malloc(1);
		result[0] = 0;
		return result;
	}
	
	end = start;
	i = start;
	while (str[i] != 0)
	{
		if (!is_space(str[i]))
			end = i;
		i++;
	}
	
	len = end - start + 1;
	result = malloc(len + 1);
	
	j = 0;
	i = start;
	while (i <= end)
	{
		result[j] = str[i];
		j++;
		i++;
	}
	result[j] = 0;
	
	return result;
}

int compare_strings(char *a, char *b)
{
	int i;

	i = 0;
	while (a[i] != 0 && b[i] != 0)
	{
		if (a[i] < b[i])
			return -1;
		if (a[i] > b[i])
			return 1;
		i++;
	}
	if (a[i] != 0)
		return 1;
	if (b[i] != 0)
		return -1;
	return 0;
}

void sort_strings(char **array, int count)
{
	int i;
	int j;
	char *tmp;
	int swapped;

	i = 0;
	while (i < count)
	{
		j = 0;
		swapped = 0;
		while (j < count - i - 1)
		{
			if (compare_strings(array[j], array[j + 1]) > 0)
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				swapped = 1;
			}
			j++;
		}
		if (swapped == 0)
			break;
		i++;
	}
}

int main(int argc, char **argv)
{
	char **trimmed;
	int i;
	int len;

	if (argc < 2)
		return 0;
	
	trimmed = malloc(sizeof(char *) * (argc - 1));
	
	i = 1;
	while (i < argc)
	{
		trimmed[i - 1] = trim_string(argv[i]);
		i++;
	}
	
	sort_strings(trimmed, argc - 1);
	
	i = 0;
	while (i < argc - 1)
	{
		len = 0;
		while (trimmed[i][len] != 0)
			len++;
		
		write(1, trimmed[i], len);
		
		if (i < argc - 2)
			write(1, " ", 1);
		
		i++;
	}
	write(1, "\n", 1);
	
	i = 0;
	while (i < argc - 1)
	{
		free(trimmed[i]);
		i++;
	}
	free(trimmed);
	
	return 0;
}
