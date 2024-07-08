/* PROGRAM-CHECKER 
 * CHECKS YOUR .c PROGRAM FOR SYNTAX ERRORS LIKE 
 * UNBALANCED PARENTHESES, COMMENTS, ETC  */

#include <stdio.h>
#include <stdlib.h>

#define LINE_BUFFER_SIZE 120

unsigned int COUNT_ERRORS = 0;

//-------------STRUCTURES DECLARATION----------------------//
struct pair {
	char ch;
	int count;
};

//------------- FUNCTIONS DECLARATION----------------------//
void check_parenthesis(FILE* file_ptr);
void check_parenthesis_validness(char file_data[], int num_of_lines);

void check_program(char file_path[])
{
	FILE* file_ptr;

	file_ptr = fopen(file_path, "r");
	if (file_ptr == NULL)
	{
		printf("Could not open a file: %s. Exit\n", file_path);
		exit(-1);
	} else {
		printf("File opened\nStarting the analysis\n");
		
		// checking for unbalanced parentheses
		check_parenthesis(file_ptr);
		

		fclose(file_ptr);
		printf("Data is successfully readen from %s. Number of errors: %d. Closing the file\n", file_path, COUNT_ERRORS);
	}
	
}

void check_parenthesis(FILE* file_ptr)
{	
	printf("in check_parenthesis\n");
	int line_number = 0;
	int num_of_lines;
	char read_data[LINE_BUFFER_SIZE];
	for (num_of_lines = 0; fgets(read_data, LINE_BUFFER_SIZE, file_ptr) != NULL; ++num_of_lines);

	char file_data[num_of_lines * LINE_BUFFER_SIZE];
	int next_file_data_index = 0;
	printf("%d\n", num_of_lines);	
	while (fgets(read_data, LINE_BUFFER_SIZE, file_ptr) != NULL)
	{	
		int line_len = 0;
		int i;
		printf("asd\n");
		printf("%s\n", read_data);
		for (i = 0; i < LINE_BUFFER_SIZE && read_data[i] != '\0'; ++i)
		{	
			// 34 is a double quote (")
			// 39 is a single quote (')
			// checking if it is a char with a single quote '
			if (read_data[i] == 39) {
				i += 2;
				if (i >= LINE_BUFFER_SIZE || read_data[i] != 39) {
					printf("ERROR: NOT CLOSED SINGLE QUOTE\n");
					return;
				} 
			// checing if it is a beginning of a line with a double quote "
			} else if (read_data[i] == 34) {
				++i;
				while (i < LINE_BUFFER_SIZE && read_data[i] != '\0' && read_data[i] != 34) 
				{
					++i;
				}
				if (read_data[i] != 34) {
					printf("ERROR: NOT CLOSED DOUBLE QUOTE\n");
					return;
				}
			} else {
				file_data[next_file_data_index + i] = read_data[i];
				++line_len;
			}

			next_file_data_index += line_len;
		}
	}
	
	file_data[next_file_data_index] = '\0';
	check_parenthesis_validness(file_data, num_of_lines);
}


void check_parenthesis_validness(char file_data[], int num_of_lines)
{
	int n;
	for (n = 0; file_data[n] != '\0'; ++n);
	
	struct pair* stack[LINE_BUFFER_SIZE * num_of_lines];
	int next_stack_index = 0;
	int counter = 0;
	
	char ch;
	for (int i = 0; i < n; ++i)
	{
		ch = file_data[i];

		++counter;
		if (ch == '(' || ch == '[' || ch == '{') {
			struct pair p = { ch, counter };
			stack[next_stack_index] = &p;
			++next_stack_index;
		} else if (ch == ')' || ch == ']' || ch == '}') {
			if (next_stack_index == 0) {
				printf("ERROR: COULD NOT FIND OPENNING PARENTHESE FOR %s\n", ch);
				return;		
			} else {
				struct pair* popped_elem = stack[--next_stack_index];
				switch (ch) {
					case ')':
						if (popped_elem->ch != '(') {
							printf("ERROR: COULD NOT FIND OPENNING PARENTHESE FOR %s\n", ch);
							return;
						}
						break;

					case ']':
						if (popped_elem->ch != '[') {
							printf("ERROR: COULD NOT FIND OPENNING PARENTHESE FOR %s\n", ch);
							return;
						}
						break;

					case '}':
						if (popped_elem->ch != '{') {
							printf("ERROR: COULD NOT FIND OPENNING PARENTHESE FOR %s\n", ch);
							return;
						}
						break;
				}
			}		
		}
	}
}


