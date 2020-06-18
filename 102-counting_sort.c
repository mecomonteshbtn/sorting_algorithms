#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
  * counting_sort - Afunction that sorts an array using counting algorithm.
  * @array: The array to sort.
  * @size: The length of the array.
  * Return: Nothing.
  */
void counting_sort(int *array, size_t size)
{
	unsigned int i = 1;
	int *counter = NULL, k = 0, j = 0;

	if (array == NULL || size < 2)
		return;

	k = array[0];
	for (; i < size; i++)
	{
		if (array[i] > k)
			k = array[i];
	}

	counter = malloc(sizeof(int) * (k + 1));
	if (counter == NULL)
		return;

	for (j = 0; j <= k; j++)
		counter[j] = 0;
	for (i = 0; i < size; i++)
		counter[array[i]] += 1;
	for (j = 0; j < k; j++)
	{
		counter[j + 1] += counter[j];
		printf("%d, ", counter[j]);
	}
	counter[j + 1] += counter[j];
	printf("%d\n", counter[j + 1]);
	for (i = 0; i < size; i++)
	{
		j = counter[array[i]] - 1;
		if (array[i] != array[j])
		{
			k = array[i];
			array[i] = array[j];
			array[j] = k;
		}
	}
	free(counter);
}
