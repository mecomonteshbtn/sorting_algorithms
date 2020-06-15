#include "sort.h"

/**
 * selection_sort - A function that use selection sort algorithm.
 * @array: An array to sort.
 * @size: The size of the array.
 * Return: Nothing.
 */
void selection_sort(int *array, size_t size)
{
	int value = 0, aux = 0;
	size_t i = 0, j = 0, pos = 0;

	for (; i < size - 1; i++)
	{
		value = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (value > array[j])
			{
				value = array[j];
				pos = j;
			}
		}
		if (pos != i)
		{
			aux = array[i];
			array[i] = array[pos];
			array[pos] = aux;
			print_array(array, size);
		}
	}
}
