/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:54:31 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/23 16:49:04 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(unsigned int size)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->stack_a = ft_calloc(size, sizeof(int));
	stack->stack_b = ft_calloc(size, sizeof(int));
	stack->size_a = size;
	stack->size_b = 0;
	stack->median = size / 2;
	stack->cost = 0;
	stack->cheapest = 0;
	return (stack);
}

void	swap(t_stack *stack, char name)
{
	if (name == 'a')
	{
		if (stack->size_a > 1)
		{
			ft_swap(&stack->stack_a[0], &stack->stack_a[1]);
			ft_dprintf(1, "%s\n", "sa");
		}
	}
	else if (name == 'b')
	{
		if (stack->size_b > 1)
		{
			ft_swap(&stack->stack_b[0], &stack->stack_b[1]);
			ft_dprintf(1, "%s\n", "sb");
		}
	}
	else if (name == 'c')
	{
		if (stack->size_b > 1)
		{
			ft_swap(&stack->stack_a[0], &stack->stack_a[1]);
			ft_swap(&stack->stack_b[0],	&stack->stack_b[1]);
			ft_dprintf(1, "%s\n", "ss");
		}
	}
}

static void	ft_rotate(int *stack, int size)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = stack[size - 1];
	if (size <= 1)
		return ;
	while (i < size)
	{
		ft_swap(&tmp, &stack[i]);
		i++;
	}
	stack[0] = tmp;
}

void	push(t_stack *stack, char name)
{
	if (stack->size_b && name == 'a')
	{
		stack->stack_a[stack->size_a++] = stack->stack_b[--stack->size_b];
		ft_rotate(stack->stack_a, stack->size_a);
		ft_dprintf(1, "%s\n", "pa");

	}
	if (stack->size_a && name == 'b')
	{
		stack->stack_b[stack->size_b++] = stack->stack_a[--stack->size_a];
		ft_rotate(stack->stack_b, stack->size_b);
		ft_dprintf(1, "%s\n", "pb");
	}
}



void	rotate(t_stack *stack, char name)
{
	if (name == 'a')
	{
		ft_rotate(stack->stack_a, stack->size_a);
		ft_dprintf(1, "%s\n", "ra");
	}
	if (name == 'b')
	{
		ft_rotate(stack->stack_b, stack->size_b);
		ft_dprintf(1, "%s\n", "rb");
	}
	if (name == 'c')
	{
		ft_rotate(stack->stack_a, stack->size_a);
		ft_rotate(stack->stack_b, stack->size_b);
		ft_dprintf(1, "%s\n", "rr");
	}
}

static void	ft_rrotate(int *stack, int size)
{
	int	tmp;

	tmp = stack[0];
	if (size <= 1)
		return ;
	size--;
	while (size)
	{
		ft_swap(&tmp, &stack[size]);
		size--;
	}
	stack[0] = tmp;
}

void	rrotate(t_stack *stack, char name)
{
	if (name == 'a')
	{
		ft_rrotate(stack->stack_a, stack->size_a);
		ft_dprintf(1, "%s\n", "rra");
	}
	if (name == 'b')
	{
		ft_rrotate(stack->stack_b, stack->size_b);
		ft_dprintf(1, "%s\n", "rrb");
	}
	if (name == 'c')
	{
		ft_rrotate(stack->stack_b, stack->size_b);
		ft_rrotate(stack->stack_a, stack->size_a);
		ft_dprintf(1, "%s\n", "rrr");
	}
}

int	find_min(t_stack *stack)
{
	int	index;
	int	value;
	int	i;

	index = 0;
	value = 0;
	i = 0;
	if (stack->size_a == 0)
		return (-1);
	value = stack->stack_a[0];
	while (i < stack->size_a)
	{
		if (stack->stack_a[i] < value)
		{
			value = stack->stack_a[i];
			index = i;
		}
		i++;
	}
	return (index);
}

void	move_to_b(t_stack *stack, int index)
{
	while (index > 0)
	{
		rotate(stack, 'a');
		index--;
	}
	push(stack, 'b');
}

void	move_to_a(t_stack *stack)
{
	int	value;
	int	target;

	value = stack->stack_b[stack->size_b - 1];
	target = find_target(stack, value) ;
	while (target > 0)
	{
		rotate(stack, 'a');
		target--;
	}
	push(stack, 'a');
}

void	move_min(t_stack *stack)
{
	int index;

	index = find_min(stack);
	while (index > 0)
	{
		rotate(stack, 'a');
		index--;
	}
}
