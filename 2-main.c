#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int array1[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	int array2[] = {2};
	size_t n = sizeof(array1) / sizeof(array1[0]);

	print_array(array1, n);
	printf("\n");
	selection_sort(array1, n);
	printf("\n");
	print_array(array1, n);

	selection_sort(array2, 1);
	printf("\n");
	print_array(array2, 1);
	return (0);
}
