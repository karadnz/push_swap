#include "push_swap.h"


static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && i < n)
	{
		if (!(s1[i] == s2[i]))
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i == n)
		i--;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void swap(t_stack *stack, char *msg)
{
	int tmp;

	if (stack->size >= 2)
	{
		tmp = stack->array[stack->top];
		stack->array[stack->top] = stack->array[stack->top - 1];
		stack->array[stack->top - 1] = tmp;
		printf("%s\n", msg);
		return;
	}

	printf("error at swap\n");

}

void rotate(t_stack *stack, char *msg) //check 1 size
{
	int tmp;
	int i;

	tmp = stack->array[stack->top];
	i = stack->top;

	while (i > 0)
	{
		stack->array[i] = stack->array[i - 1];
		i--;
	}
	stack->array[0] = tmp;
	printf("%s\n",msg);

}

void reverse_rotate(t_stack *stack, char *msg) //check 1 size
{
	int tmp;
	int i;

	tmp = stack->array[0];
	i = 0;

	while (i < stack->top)
	{
		stack->array[i] = stack->array[i + 1];
		i++;
	}
	stack->array[stack->top] = tmp;
	printf("%s\n",msg);

}

void push_other(t_stack *stack_1, t_stack *stack_2, char *msg) //check empty
{
	push(stack_2, stack_1->array[stack_1->top]);
	pop(stack_1);
	printf("%s\n", msg);
}

void do_twice(t_stack *stack_1, t_stack *stack_2, char *msg)
{
	if (!ft_strncmp(msg, "ss", 2)) //check
	{
		swap(stack_1,"\0"); //0 gelince yazdirmama ekle
		swap(stack_2,"\0");
	}

	else if (!ft_strncmp(msg, "rrr", 3)) //siraya dikkat rrr rr
	{
		reverse_rotate(stack_1,"\0");
		reverse_rotate(stack_2,"\0");
	}

	else if (!ft_strncmp(msg, "rr", 2))
	{
		rotate(stack_1,"\0");
		rotate(stack_2,"\0");
	}

	else
	{
		printf("error at do_twice\n");
		return ;
	}
	printf("%s", msg);
}

