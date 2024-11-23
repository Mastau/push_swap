/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:30:49 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/23 14:40:56 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_stack
{
	int	size_a;
	int	*stack_a;
	int	*stack_b;
	int	size_b;
	int	cost;
	int	cheapest;
	int	median;
}		t_stack;

t_list	*parsing(char **av);
t_stack	*stack_new(unsigned int size);
t_stack	*init_stack(char **strs);
void	swap(t_stack *stack, char name);
void	push(t_stack *stack, char name);
void	rotate(t_stack *stack, char name);
void	rrotate(t_stack *stack, char name);
void	small_sort_stack(t_stack *stack);
void	sort_three(t_stack *stack);
int		find_target(t_stack *stack, int value);
void	big_sort_stack(t_stack *stack);
void	sort_stack(t_stack *stack);
void	move_to_b(t_stack *stack, int index);
void	move_to_a(t_stack *stack);
void	move_min(t_stack *stack);
void	ft_printstack(t_stack *stack);
#endif
