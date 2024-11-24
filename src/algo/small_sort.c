/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:54:45 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/24 14:46:53 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *stack)
{
	int	first;
	int	second;
	int	third;

	first = stack->top->value;
	second = stack->top->next->value;
	third = stack->top->next->next->value;
	if (first < second && second < third)
		return ;
	if (first < third && third < second)
	{
		rrotate(stack, 'a');
		swap(stack, 'a');
	}
	else if (second < first && first < third)
		swap(stack, 'a');
	else if (third < first && first < second)
	{
		swap(stack, 'a');
		rrotate(stack, 'a');
	}
	else if (second < third && third < first)
		rotate(stack, 'a');
	else if (third < second && second < first)
	{
		swap(stack, 'a');
		rotate(stack, 'a');
	}
}

static void	sort_four_2(t_stack *a, t_stack *b)
{
		rotate(a, 'a');
		rotate(a, 'a');
		push_to(a, b, 'b');
}

void	sort_four(t_stack *a, t_stack *b)
{
	int	min_value;
	int	min_pos;

	min_value = find_min(a);
	min_pos = find_position(a, min_value);
	if (min_pos == 0)
		push_to(a, b, 'b');
	else if (min_pos == 3)
	{
		rrotate(a, 'a');
		push_to(a, b, 'b');
	}
	else if (min_pos == 1)
	{
		rotate(a, 'a');
		push_to(a, b, 'b');
	}
	else if (min_pos == 2)
		sort_four_2(a, b);
	sort_three(a);
	push_to(b, a, 'a');
}


void	small_sort(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		if (a->top->value > a->top->next->value)
			swap(a, 'a');
	}
	else if (a->size == 3)
		sort_three(a);
	else if (a->size == 4)
	{
		sort_four(a, b);
	}
}
