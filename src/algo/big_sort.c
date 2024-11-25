/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:43:48 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/26 13:32:16 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	align_stack(t_stack *stack)
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
