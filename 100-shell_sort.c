#include "sort.h"

/**
  * shell_sort - A function tat sorts an array usin shell algorithm.
  * @array: The array to sort.
  * @size: The length of the array.
  * Return: Nothing.
  */
void shell_sort(int *array, size_t size)
{
	int i = 0, j = 0, gap = 0, aux = 0, n = 0;

	n = (int)size;
	for (gap = n/2; gap > 0; gap /= 2)
	{
		for (i = gap; i < n; i++)
		{
			aux = array[i];
			for (j = i; j >= gap && array[j - gap] > aux;
					j -= gap)
			{
				if (array[j] != array[j - gap])
					array[j] = array[j - gap];
			}
			if (array[j] != aux)
				array[j] = aux;

		}
		print_array(array, size);
	}
}
