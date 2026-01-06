#include <stdlib.h>

int	my_strlen(char *str);

static int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

static int	count_words(char *str)
{
	int	count;
	int	i;
	int	in_word;

	count = 0;
	in_word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (!is_space(str[i]))
		{
			if (!in_word)
			{
				count++;
				in_word = 1;
			}
		}
		else
			in_word = 0;
		i++;
	}
	return (count);
}

static int	get_word_length(char *str, int start)
{
	int	len;

	len = 0;
	while (str[start + len] != '\0' && !is_space(str[start + len]))
		len++;
	return (len);
}

char	**split(char *str)
{
	int	word_count;
	int	i;
	int	j;
	int	k;
	char	**result;

	word_count = count_words(str);
	result = malloc((word_count + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] != '\0' && j < word_count)
	{
		while (str[i] != '\0' && is_space(str[i]))
			i++;
		if (str[i] != '\0')
		{
			k = get_word_length(str, i);
			result[j] = malloc(k + 1);
			if (result[j] == NULL)
				return (NULL);
			k = 0;
			while (str[i] != '\0' && !is_space(str[i]))
			{
				result[j][k] = str[i];
				i++;
				k++;
			}
			result[j][k] = '\0';
			j++;
		}
	}
	result[j] = NULL;
	return (result);
}
