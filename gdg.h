#ifndef GENERIC_DATASET_GENERATOR_H
#define GENERIC_DATASET_GENERATOR_H

#include "types.h"

void generate_column(int start, int end, int steps, double(*formula)(double), char first_label, char second_label);

void generate_categorical(char* categories, int* counts, int categories_amount);

void generate_array(void* array, int size, int type_flag);

#endif