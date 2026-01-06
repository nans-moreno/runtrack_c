int	char_is_digit(char c);

int	str_is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!char_is_digit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int main(void)
{
	return 0;
}
