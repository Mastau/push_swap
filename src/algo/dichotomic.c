/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dichotomic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:43:48 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/20 18:59:47 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static	int	check_sort(int	*stack, int size)
{
	while (size > 0)
	{
		if (stack[size] < stack[size - 1])
			return (0);
		size--;
	}
	return (1);
}

static void	ft_bsort(int *stack, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (stack[i] > stack[j])
				ft_swap(&stack[j], &stack[j]);
			j++;
		}
		i++;
	}
}

static	float	get_median(int	*stack, int size)
{
	float	median;
	int	*list;

	median = 0;
	list = malloc(size * sizeof(int));
	if (list == NULL)
		return (0);
	ft_memcpy(list, stack, size);
	ft_bsort(list, size);
	if (size % 2 == 0)
		median = (float)(list[size / 2] + list[(size + 1) / 2]) / 2.0;
	else
		median = list[(size + 1) / 2];
	free(list);
	return (median);
}

void	sort_stack(t_stack *stack)
{
	float median;

	median = 0;
	if (check_sort(stack->stack_a, stack->size_a))
		return ;
	median = get_median(stack->stack_a, stack->size_a);
	while (stack->size_a > 0)
	{
		if (stack->stack_a[stack->size_a - 1] <= median)
			push(stack, 'a');
		else
			rotate(stack, 'a');
	}
	sort_stack(stack);
	while (stack->size_b > 0)
		push(stack, 'b');
}
