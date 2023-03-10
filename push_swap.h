/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:43:35 by mkaraden          #+#    #+#             */
/*   Updated: 2023/02/02 18:28:48 by mkaraden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int		*array;
	int		size;
	int		top;
}				t_stack;
//stack
void	resize(t_stack *stack);
void	init_stack(t_stack *stack, int size);
void	push(t_stack *stack, int num);
void	pop(t_stack *stack);
int		peek(t_stack *stack);
void	free_stacks(t_stack *stack_a, t_stack *stack_b);
//stack operations
void	swap(t_stack *stack, char *msg); //sa sb
void	rotate(t_stack *stack, char *msg); //ra rb
void	reverse_rotate(t_stack *stack, char *msg); //rra rrb
void	push_other(t_stack *stack_1, t_stack *stack_2, char *msg); //pa pb
void	do_twice(t_stack *stack_1, t_stack *stack_2, char *msg);
//libftutils
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
long	ft_atoi_check(const char *str);
//init
void	init(int ac, char **av, t_stack *stack_a, t_stack *stack_b);
void	fillstack(int ac, char **av, t_stack *stack_a, t_stack *stack_b);
int		check_num(int ac, char **av);
int		check_duplicate(int ac, char **av);
int		check_sorted(int ac, char **av);
//init utils
int		compare_arrays(int *arr1, int *arr2, int size);
void	bubble_sort(int *arr1, int size);
int		*fill_duplicate(int ac, char **av);
//index
void	get_index(t_stack *a);
int		*get_sorted(int *src, int size);
//radix old
void	radix_main(t_stack *stack_a, t_stack *stack_b);
void	digit_sort(t_stack *stack_a, t_stack *stack_b, int place);
int		get_digit_at_place(int num, int place);
int		get_max(t_stack *stack);
int		get_max_place(int num);
//radix bit
void	radix_main(t_stack *stack_a, t_stack *stack_b);
void	bit_sort(t_stack *stack_a, t_stack *stack_b, int bit_place);
int		leftmost(unsigned int n);
int		get_max(t_stack *stack);
int		check_sorted_stack(t_stack *stack);
void	bubble_stack_sort(int *arr1, int size);
//small sort
void	small_sort(t_stack *stack_a, t_stack *stack_b);
void	sort_two(t_stack *stack_a, t_stack *stack_b);
void	sort_three(t_stack *stack_a, t_stack *stack_b);
void	sort_four(t_stack *stack_a, t_stack *stack_b);
void	sort_five(t_stack *stack_a, t_stack *stack_b);
void	transform(t_stack *stack_a, int size);
int		check_stack_sorted(t_stack *stack);
#endif