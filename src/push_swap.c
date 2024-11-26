/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:30:34 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/26 14:04:43 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current)
	{
		ft_printf("value:%d, rank:%d | ", current->value, current->rank);
		current = current->next;
	}
	ft_printf("\n");
}

static void	ft_set_ranks(t_stack *a, int size)
{
	t_node	*current;
	t_node	*highest;
	int		stocked;

	while (--size)
	{
		highest = NULL;
		stocked = INT_MIN;
		current = a->top;
		while (current)
		{
			if (current->value == INT_MIN && current->rank == 0)
				current->rank = 1;
			if (current->value > stocked && current->rank == 0)
			{
				stocked = current->value;
				highest = current;
				current = a->top;
			}
			else
				current = current->next;
		}
		if (highest)
			highest->rank = size;
	}
}

static void	fill_index(t_stack *stack)
{
	int		i;
	t_node	*current;

	current = stack->top;
	i = 0;
	while (current)
	{
		current->index = i;
		current = current->next;
		i++;
	}
}

static int	ft_is_sorted(t_node *stack)
{
	t_node	*current;

	current = stack;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	a = init_stack();
	b = init_stack();
	a = parsing(a, av);
	if (a == NULL)
	{
		clear_stack(b);
		ft_dprintf(2, "%s\n", "Error");
		return (0);
	}
	if (ft_is_sorted(a->top))
		return (clear_all_stack(a, b));
	fill_index(a);
	ft_set_ranks(a, a->size + 1);
	sort_stack(a, b);
	return (clear_all_stack(a, b));
}
