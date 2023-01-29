/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortBinary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:51:20 by mkaraden          #+#    #+#             */
/*   Updated: 2023/01/29 10:32:59 by mkaraden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_main(t_stack *stack_a, t_stack *stack_b)
{
	int iter_count;

	iter_count = leftmost(get_max(stack_a));

	for (int i = 0; i < iter_count; i++)
	{
		
		//printf("iter: %d\n\n\n", i);
		if (!check_sorted_stack(stack_a))
		{
			//printf("hit");
			break;

		}
			
		bit_sort(stack_a, stack_b, i);
	}

}

void bit_sort(t_stack *stack_a, t_stack *stack_b, int bit_place)
{
	int	a_size = stack_a->top + 1;

	for (int i = 0; i < a_size; i++)
	{
		//printf("inner iter: %d\n", i);
		if (((peek(stack_a) >> (bit_place)) & 1)) //&& (i != a_size - 1)
			rotate(stack_a, "ra");
		else
		{
			push_other(stack_a, stack_b, "pb");
		}
	}

	int b_size = stack_b->top + 1;

	for (int i = 0; i < b_size; i++)
	{
		push_other(stack_b, stack_a, "pa");
	}
	

}

int get_bit_at_place(int num, int bit_place)
{
	return (num << bit_place);
}

int leftmost(unsigned int n) //iter sayisi
{
    int pos = 31;
    while (! (n >> pos))
    {
        pos--;
    }
    return (pos + 1);
}

int	get_max(t_stack *stack)
{
	int rt;
	int *tmp;

	tmp = get_sorted(stack->array, stack->size);

	rt = tmp[stack->top];
	free(tmp);
	return (tmp[stack->top]);
}

int check_sorted_stack(t_stack *stack)
{
	int *tmp = (int *)malloc(sizeof(int) * (stack->size));

	for (int i = 0; i < stack->size; i++)
	{
		tmp[i] = stack->array[i];
		
	}

	bubble_stack_sort(tmp, stack->size);

	for (int i = 0; i < stack->size; i++)
	{
		//printf("%d\n",tmp[i]);
	}

	//printf("\n\n");
	for (int i = 0; i < stack->size; i++)
	{
		//printf("%d\n",stack->array[i]);
	}

	//printf("\n\n");
	

	

	return (compare_arrays(tmp, stack->array, stack->size));
	
}


void bubble_stack_sort(int *arr1, int size)
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
			
			if (arr1[i] < arr1[i + j])
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