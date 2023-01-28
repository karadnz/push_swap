/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortOld.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:56:02 by mkaraden          #+#    #+#             */
/*   Updated: 2023/01/28 21:48:02 by mkaraden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_main(t_stack *stack_a, t_stack *stack_b)
{
	int place;

	place = get_max_place(get_max(stack_a));
	// printf("%d", place);
	// exit(1);

	for (int i = 0; i < place; i++)
	{
		digit_sort(stack_a, stack_b, i + 1);
	}

}

void	digit_sort(t_stack *stack_a, t_stack *stack_b, int place) //min to b
{
	int s_top = stack_a->top;
	for (int i = 0; i <= 9; i++)
	{
		for (int j = 0; j <= s_top; j++) //a daki tum sayilar kadar
		{
			
			if (get_digit_at_place(peek(stack_a), place) == i)
			{
				//printf("\n i: %d, j: %d top: %d \n",i , j, stack_a->top);
				push_other(stack_a, stack_b, "pb");
				

			}
				
			else
			{
				rotate(stack_a, "ra");
			}	
		}
		
		
	}
	int top = stack_b->top;
	for (int i = 0; i <= top; i++)
	{
		//printf("BTop: %d\n",stack_b->top);
		//printf("ATop: %d\n",stack_a->top);
		push_other(stack_b, stack_a, "pa");
	}
	
}

int	get_digit_at_place(int num, int place)
{
	int rt;
    int i;

	i = 0;
    while (i < place)
	{
        rt = num % 10;
        num /= 10;
		i++;
    }
    return rt;
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

int	get_max_place(int num)
{
	int rt;

	rt = 0;
	while (num > 0)
	{
		num = num / 10;
		rt++;
	}

	return (rt);
}