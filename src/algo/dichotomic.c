/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dichotomic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:43:48 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/22 17:58:24 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static	int	check_sort(int	*stack, int size)
{
	int	i;

	i = 0;
	while (size > i)
	{
		if (stack[i] < stack[i - 1])
			return (0);
		i++;
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
	ft_memcpy(list, stack, size * sizeof(int));
	ft_bsort(list, size);
	if (size % 2 == 0)
		median = (float)(list[(size / 2) - 1] + list[(size + 1) / 2]) / 2.0;
	else
		median = list[size / 2];
	free(list);
	return (median);
}

void ft_printstack(t_stack *stack)
{
	int	i;

	i = 0;
	if (stack->size_a)
	{	
		i = stack->size_a;
		ft_printf("%s", "Stack a: ");
		while (i > 0)
		{
			ft_printf(" %d ", stack->stack_a[i - 1]);
			i--;
		}
		ft_printf("%c", '\n');
	}
	else 
		ft_printf("%s\n", "Stack a: vide");
	if (stack->size_b)
	{	
		i = stack->size_b;
		ft_printf("%s", "Stack b: ");
		while (i > 0)
		{
			ft_printf(" %d ", stack->stack_b[i - 1]);
			i--;
		}
		ft_printf("%c", '\n');
	}
	else 
		ft_printf("%s\n", "Stack b: vide");
}

void	big_sort_stack(t_stack *stack)
{
	float median;

	median = 0;
	if (check_sort(stack->stack_a, stack->size_a))
		return ;
	median = get_median(stack->stack_a, stack->size_a);
	while (stack->size_a > 0)
	{
		if (stack->stack_a[stack->size_a - 1] <= median)
			push(stack, 'b');
		else
			rotate(stack, 'a');
	}	
	sort_stack(stack);
	while (stack->size_b > 0)
		push(stack, 'a');
	ft_printstack(stack);
}
