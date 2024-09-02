

#include <iostream>

 
static int find_pattern(char* input_txt, char* new_txt)
{
	int length_new = strlen(new_txt);
	int new_index = 0;
	int word_count = 0;
	int i = 0;

	while(input_txt[i] != 0)
	{
		i++;
		if (input_txt[i] == new_txt[new_index])
		{
			while (input_txt[i + new_index] == new_txt[new_index])
			{
				new_index++;
			}

			if (new_index == length_new)
			{
				word_count++;
				char* tmp = &input_txt[i - 1];
				*tmp = '[';    /* add bracket around founded pattern */
				tmp = &input_txt[i + length_new];
				*tmp = ']';
			}

			i = i + new_index;
			new_index = 0;
		}
	}
	return word_count;
}


int main()
{
	char input_txt[] = " find me I am close to the sky, when you find me then we can talk ";
	char new_txt[] = "find me";
	int word_count = find_pattern(input_txt, new_txt);
	printf("Number of pattern repetition: %d \n", word_count);
	printf(input_txt);

	if (word_count > 0)
	{
		printf("The pattern is founded\n");
	}
	else {
		printf("The pattern is not founded\n");
	}

}


