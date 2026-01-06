static int compare_strings(char *a, char *b)
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

void sort(char **array)
{
	int i;
	int j;
	char *tmp;
	int count;
	int swapped;

	count = 0;
	while (array[count] != 0)
		count++;
	
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

int main(void)
{
	return 0;
}
