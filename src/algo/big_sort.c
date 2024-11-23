/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:43:48 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/23 17:29:31 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	check_sort(int *stack, int size)
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

void	ft_printstack(t_stack *stack)
{
	int	i;

	i = 0;
	if (stack->size_a)
	{
		ft_printf("%s", "Stack a: ");
		while (i < stack->size_a)
		{
			ft_printf(" %d ", stack->stack_a[i]);
			i++;
		}
		ft_printf("%c", '\n');
	}
	else
		ft_printf("%s\n", "Stack a: vide");
	if (stack->size_b)
	{
		i = 0;
		ft_printf("%s", "Stack b: ");
		while (i < stack->size_b)
		{
			ft_printf(" %d ", stack->stack_b[i]);
			i++;
		}
		ft_printf("%c", '\n');
	}
	else
		ft_printf("%s\n", "Stack b: vide");
}

int	find_target(t_stack *stack, int value)
{
	int pos;
	int	i;

	pos = 0;
	i = 0;
	while (i < stack->size_b)
	{
		if (stack->stack_b[i] < value)
			pos = i + 1;
		i++;
	}
	return (pos);
}

int	calculate_cost(t_stack *stack, int index)
{
	int rot_a;
	int	rot_b;
	int target_b;
	int	both;

	rot_a = index;
	target_b = find_target(stack, stack->stack_a[index]);
	rot_b = target_b;
	both = 0;
	if (rot_a > 0 && rot_b > 0)
	{
		if (rot_a < rot_b)
			both = rot_a;
		else
			both = rot_b;
		rot_a -= both;
		rot_b -= both;
	}
	return (rot_a + rot_b + 1);
}

int find_cheapest(t_stack *stack)
{
	int	index;
	int cheap_cost;
	int	i;

	index = 0;
	cheap_cost = calculate_cost(stack, 0);
	i = 0;

	while (i < stack->size_a)
	{
		stack->cost = calculate_cost(stack, i);
		if (stack->cost < cheap_cost)
		{
			index = i;
			cheap_cost = stack->cost;
		}
		i++;
	}
	return (index);
}

void	big_sort_stack(t_stack *stack)
{
	int	cheap_index;

	if (stack->size_a > 3 && !check_sort(stack->stack_a, stack->size_a))
		push(stack, 'b');
	if (stack->size_a > 3 && !check_sort(stack->stack_a, stack->size_a))
		push(stack, 'b');
	ft_printstack(stack);
	while (stack->size_a > 3 && !check_sort(stack->stack_a, stack->size_a))
	{
		cheap_index = find_cheapest(stack);
		move_to_b(stack, cheap_index);
		ft_printstack(stack);
	}
	sort_three(stack);
	while (stack->size_b > 0)
	{
		move_to_a(stack);
		ft_printstack(stack);
	}
	move_min(stack);
}
