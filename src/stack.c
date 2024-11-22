/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:54:31 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/22 15:21:53 by thomarna         ###   ########.fr       */
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
	return (stack);
}

void	swap(t_stack *stack, char name)
{
	if (name == 'a')
	{
		if (stack->size_a > 1)
		{
			ft_swap(&stack->stack_a[stack->size_a - 1],
				&stack->stack_a[stack->size_a - 2]);
			ft_dprintf(1, "%s\n", "sa");
		}
	}
	else if (name == 'b')
	{
		if (stack->size_b > 1)
		{
			ft_swap(&stack->stack_b[stack->size_b - 1],
				&stack->stack_b[stack->size_b - 2]);
			ft_dprintf(1, "%s\n", "sb");
		}
	}
	else if (name == 'c')
	{
		if (stack->size_b > 1)
		{
			ft_swap(&stack->stack_a[stack->size_a - 1],
				&stack->stack_a[stack->size_a - 2]);
			ft_swap(&stack->stack_b[stack->size_b - 1],
				&stack->stack_b[stack->size_b - 2]);
			ft_dprintf(1, "%s\n", "ss");
		}
	}
}

void	push(t_stack *stack, char name)
{
	if (stack->size_b && name == 'a')
	{
		stack->stack_a[stack->size_a++] = stack->stack_b[--stack->size_b];
		ft_dprintf(1, "%s\n", "pa");
	}
	if (stack->size_a && name == 'b')
	{
		stack->stack_b[stack->size_b++] = stack->stack_a[--stack->size_a];
		ft_dprintf(1, "%s\n", "pb");
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
	while (size <= 0)
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
