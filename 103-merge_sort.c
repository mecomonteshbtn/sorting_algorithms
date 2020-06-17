#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge_sort - A function that sorts an array using merge algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 * Return: Nothing.
 */
void merge_sort(int *array, size_t size)
{
	size_t i = 0;
	int *base = NULL;

	if (array == NULL || size < 2)
		return;
	base = malloc(sizeof(int) * size);
	if (base == NULL)
		return;
	for (; i < size; i++)
		base[i] = array[i];
	merge_partition(0, size, array, base);
	free(base);
}

/**
 * merge - A function that sorts the subarrays.
 * @lo: Lower index.
 * @mi: Middle index.
 * @hi: Higher index.
 * @dest: Destination for data.
 * @src: Input data.
 * Return: Nothing
 */
void merge(size_t lo, size_t mi, size_t hi, int *dest, int *src)
{
	size_t i = 0, j = 0, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(src + lo, mi - lo);
	printf("[right]: ");
	print_array(src + mi, hi - mi);
	i = lo;
	j = mi;
	k = lo;
		for (; k < hi; k++)
		{
			if (i < mi && (j >= hi || src[i] <= src[j]))
			{
				dest[k] = src[i];
				i++;
			}
			else
			{
				dest[k] = src[j];
				j++;
			}
		}
	printf("[Done]: ");
	print_array(dest + lo, hi - lo);
}

/**
 * merge_partition - A funtion that splits the array recursively.
 * @lo: Lower index.
 * @hi: Higher index.
 * @array: The array to sort.
 * @base: The copy of the array.
 * Return: Nothing.
 */
void merge_partition(size_t lo, size_t hi, int *array, int *base)
{
	size_t mi = 0;

	if (hi - lo < 2)
		return;
	mi = (lo + hi) / 2;
	merge_partition(lo, mi, array, base);
	merge_partition(mi, hi, array, base);
	merge(lo, mi, hi, array, base);
	for (mi = lo; mi < hi; mi++)
		base[mi] = array[mi];
}
