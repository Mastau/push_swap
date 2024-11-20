/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:30:49 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/20 17:29:37 by thomarna         ###   ########.fr       */
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
}		t_stack;

t_list	*parsing(char **av);
t_stack	*stack_new(unsigned int size);
t_stack	*init_stack(char **strs);
void	swap(t_stack stack, char name);
void	push(t_stack *stack, char name);
void	rotate(t_stack *stack, char name);
void	rrotate(t_stack *stack, char name);
void	sort_stack(t_stack *stack);
#endif
