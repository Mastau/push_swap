/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:43:48 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/25 18:43:44 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_min(t_stack *stack)
{
	int	value;

	value = find_min(stack);
	while (stack->top->value != value)
		rotate(stack, 'a');
}

int	find_min(t_stack *stack)
{
	t_node	*current;
	int		min;

	current = stack->top;
	min = current->value;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

int	find_position(t_stack *stack, int value)
{
	t_node	*current;
	int		pos;

	current = stack->top;
	pos = 0;
	while (current)
	{
		if (current->value == value)
			return (pos);
		current = current->next;
		pos++;
	}
	return (-1);
}

static int	ft_get_target(t_stack *a, int stack_b_rank, int closest_rank,
		int target_pos)
{
	t_node	*crt;

	crt = a->top;
	while (crt)
	{
		if (crt->rank > stack_b_rank && crt->rank < closest_rank)
		{
			closest_rank = crt->rank;
			target_pos = crt->index;
		}
		crt = crt->next;
	}
	if (closest_rank != INT_MAX)
		return (target_pos);
	crt = a->top;
	while (crt)
	{
		if (crt->rank < closest_rank)
		{
			closest_rank = crt->rank;
			target_pos = crt->index;
		}
		crt = crt->next;
	}
	return (target_pos);
}

void	ft_set_pos(t_stack *stack)
{
	t_node	*current;
	int		i;

	i = -1;
	current = stack->top;
	while (current)
	{
		current->index = ++i;
		current = current->next;
	}
}

void	ft_set_target_pos(t_stack *a, t_stack *b)
{
	t_node	*current;
	int		target_pos;

	current = b->top;
	ft_set_pos(a);
	ft_set_pos(b);
	target_pos = 0;
	while (current)
	{
		target_pos = ft_get_target(a, current->rank, INT_MAX, target_pos);
		current->target_pos = target_pos;
		current = current->next;
	}
}

static void	ft_get_cost(t_stack *a, t_stack *b)
{
	t_node	*crt_b;

	crt_b = b->top;
	while (crt_b)
	{
		crt_b->cost_b = crt_b->index;
		if (crt_b->index > b->size / 2)
			crt_b->cost_b = (b->size - crt_b->index) * -1;
		crt_b->cost_a = crt_b->target_pos;
		if (crt_b->target_pos > a->size / 2)
			crt_b->cost_a = (a->size - crt_b->target_pos) * -1;
		crt_b = crt_b->next;
	}
}

void	push_to_b(t_stack *a, t_stack *b)
{
	int	nb_push;
	int	i;
	int	size;

	i = -1;
	size = a->size;
	nb_push = 0;
	while (nb_push < (size / 2) && ++i < size)
	{
		if (a->top->rank < (size / 2))
		{
			push_to(a, b, 'b');
			nb_push++;
		}
		else
			rotate(a, 'a');
	}
	while (a->size > 3)
		push_to(a, b, 'b');
	sort_three(a);
}

void	perform_move(t_stack *a, t_stack *b, t_node *node)
{
	while (node->cost_a > 0)
	{
		rotate(a, 'a');
		node->cost_a--;
	}
	while (node->cost_a < 0)
	{
		rrotate(a, 'a');
		node->cost_a++;
	}
	while (node->cost_b > 0)
	{
		rotate(b, 'b');
		node->cost_b--;
	}
	while (node->cost_b < 0)
	{
		rrotate(b, 'b');
		node->cost_b++;
	}
	push_to(b, a, 'a');
}

void	move_cheapest(t_stack *a, t_stack *b)
{
	t_node	*current;
	t_node	*cheapest;
	int		cheapest_cost;
	int		total_cost;

	cheapest = NULL;
	current = b->top;
	cheapest_cost = INT_MAX;
	while (current)
	{
		total_cost = abs(current->cost_a) + abs(current->cost_b);
		if (total_cost < cheapest_cost)
		{
			cheapest_cost = total_cost;
			cheapest = current;
		}
		current = current->next;
	}
	if (cheapest)
		perform_move(a, b, cheapest);
}

void	align_stack(t_stack *stack)
{
	int	min_pos;

	min_pos = find_position(stack, find_min(stack));
	if (min_pos <= stack->size / 2)
		while (min_pos--)
			rotate(stack, 'a');
	else
		while (min_pos++ < stack->size)
			rrotate(stack, 'a');
}

void	turk_sort(t_stack *a, t_stack *b)
{
	push_to_b(a, b);
	while (b->size > 0)
	{
		ft_set_target_pos(a, b);
		ft_get_cost(a, b);
		move_cheapest(a, b);
	}
	align_stack(a);
}
