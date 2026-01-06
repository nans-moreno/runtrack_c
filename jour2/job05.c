void func_to_array(char **array, void (*func)(char *))
{
	int i;

	i = 0;
	while (array[i] != 0)
	{
		func(array[i]);
		i++;
	}
}

int main(void)
{
	return 0;
}
