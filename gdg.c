#include <stdio.h>
#include "gdg.h"
#include "types.h"

void generate_column(int start, int end, int steps, double(*formula)(double), char first_label, char second_label)
// Generate a numeric column dataset with X and f(X)
{
	if (first_label != ' ' && second_label != ' ')
	// Checks if labels were passed or not
	{
		printf("%3c %6c\n\n", first_label, second_label);
	}
	for (double s = start; s <= end; s += steps)
	{
		printf("%3.4lf %6.4lf\n", s, (*formula)(s));
	}
}

void generate_categorical(char* categories, int* counts, int categories_amount)
{
	for (int s = 0; s < categories_amount; ++s)
	{
		printf("%c: ", categories[s]);
		for (int parals = 0; parals < counts[s]; ++parals)
		{
			printf("█"); // Print a block for each count
		}
		printf("\n");
	}
}

// This formats and generates a dataset of the array of your choosing
// It does NOT generate arrays
void generate_array(void* passed_array, int size, int type_flag)
{
	/*
	This here is a switch to check what type the user has passed
	It will output differently depending on the type flag
	*/
	switch(type_flag)
	{
	case TYPE_INT:
		{
		int* array = (int*)passed_array;
		printf("%3s %6s\n\n", "Index", "Value");
		for (int s = 0; s < size; ++s)
		{
			printf("%3d %6d\n", s, array[s]);
		}
		break;
		}
	case TYPE_FLOAT:
		{
		float* array = (float*)passed_array;
		printf("%3s %6s\n\n", "Index", "Value");
		for (int s = 0; s < size; ++s)
		{
			printf("%3d %6f\n", s, array[s]);
		}
		break;
		}
	case TYPE_DOUBLE:
		{
		double* array = (double*)passed_array;
		printf("%3s %6s\n\n", "Index", "Value");
		for (int s = 0; s < size; ++s)
		{
			printf("%3d %6lf\n", s, array[s]);
		}
		break;
	    }
	case TYPE_STRING:
		{
		char** array = (char**)passed_array;
		printf("%3s %6s\n\n", "Index", "Value");
		for (int s = 0; s < size; ++s)
		{
			printf("%3d %6s\n", s, array[s]);
		}
		break;
	    }
	case TYPE_CHAR:
		{
		char* array = (char*)passed_array;
		printf("%3s %6s\n\n", "Index", "Value");
		for (int s = 0; s < size; ++s)
		{
			printf("%3d %6c\n", s, array[s]);
		}
		break;
		}
	default:
		printf("Must pass a valid datatype (at the 3rd argument)\n");
		return;
	}
}
