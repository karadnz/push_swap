#include "push_swap.h"

int	compare_arrays(int *arr1, int *arr2, int size)
{
	int	i;

	i = 0;
	while(i < size)
	{
		if (arr1[i] != arr2[i])
			return (1);
		i++;
	}
	return(0);
}

void bubble_sort(int *arr1, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (i + j < size)
		{
			
			if (arr1[i] > arr1[i + j])
			{
				
				tmp = arr1[i];
				arr1[i] = arr1[i + j];
				arr1[i + j] = tmp;
			}
			j++;
		}
		i++;
	
	}

}