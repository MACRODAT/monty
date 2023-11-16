#include "monty.h"

/**
 * _splitString - Function to split a string into
 * multiple tokens based on a delimiter
 * @input: in
 * @delimiters: del
 * @count: ma
 *
 * Return: arr
*/
char **_splitString(char *input, const char *delimiters, int *count)
{
	char *input_copy = strdup(input);
	int array_size = 10;
	char **result, *token;

	if (input_copy == NULL)
	{
		perror("Error in strdup");
		exit(EXIT_FAILURE);
	}

	result = (char **)malloc(array_size * sizeof(char *));
	if (result == NULL)
		endall("Error: malloc failed\n");

	token = strtok(input_copy, delimiters);
	*count = 0;

	while (token != NULL)
	{
		if (*count >= array_size)
		{
			array_size *= 2;
			result = (char **)realloc(result, array_size * sizeof(char *));
			if (result == NULL)
				endall("Error: malloc failed\n");
		}

		result[*count] = strdup(token);
		if (result[*count] == NULL)
			endall("Error: malloc failed\n");

		(*count)++;
		token = strtok(NULL, delimiters);
	}

	free(input_copy);

	return (result);
}

/**
 * free_split_string - dkle
 * @result: erlpk
 * @count: jprfe
*/
void free_split_string(char **result, int count)
{
	int i = 0;

	for (i = 0; i < count; i++)
	{
		free(result[i]);
	}
	free(result);
}
