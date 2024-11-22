/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:19:39 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/22 16:29:29 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack *stack)
{
	if (stack->size_a <= 5)
		small_sort_stack(stack);
	else
		big_sort_stack(stack);
	//ft_printstack(stack);
}
