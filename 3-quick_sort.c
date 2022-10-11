#include "sort.h"
/**
 * swap - swaps integers
 * @a: first integer
 * @b: second integer
 * Return: void
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * partition - split elements
 * @arr: array
 * @first: first element
 * @last: last element
 * @size: size of array
 * Return: integer
 */
int partition(int *arr, int first, int last, size_t size)
{
	int p = arr[last];
	int i = first;
	int j;

	for (j = first; j < last; j++)
	{
		if (arr[j] <= p)
		{
			swap(&arr[i], &arr[j]);
			if (i != j)
				print_array(arr, size);
			i++;
		}
	}
	swap(&arr[i], &arr[last]);
	if (i != j)
		print_array(arr, size);
	return (i);
}
/**
 * quickSort - sort part of list
 * @arr: array
 * @first: first element
 * @last: last element
 * @size: size of array
 * Return: void
 */
void quickSort(int *arr, int first, int last, size_t size)
{
	int p;

	if (first < last)
	{
		p = partition(arr, first, last, size);
		quickSort(arr, first, p - 1, size);
		quickSort(arr, p + 1, last, size);
	}
}
/**
 * quick_sort - sort method array
 * @array: the array
 * @size: size of array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	quickSort(array, 0, size - 1, size);
}
