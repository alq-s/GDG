#include <stdio.h>
#include "gdg.h"



void generate_column(int start, int end, int steps, double(*formula)(double), char first_label, char second_label)
{
	if (first_label != ' ' && second_label != ' ')
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
	for (int x = 0; x < categories_amount; ++x)
	{
		printf("%c: ", categories[x]);
		for (int parals = 0; parals < counts[x]; ++parals)
		{
			printf("█");
		}
		printf("\n");
	}

}
