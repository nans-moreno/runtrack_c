#include <stdlib.h>

void delete_str_array(char ***array)
{
	int i;

	i = 0;
	while ((*array)[i] != 0)
	{
		free((*array)[i]);
		i++;
	}
	free(*array);
	*array = 0;
}

int main(void)
{
	return 0;
}
