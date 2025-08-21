#ifndef GENERIC_DATASET_GENERATOR_H
#define GENERIC_DATASET_GENERATOR_H


void generate_column(int start, int end, int steps, double(*formula)(double), char first_label, char second_label);

void generate_categorical(char* categories, int* counts, int categories_amount);
#endif
