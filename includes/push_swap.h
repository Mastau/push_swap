/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:30:49 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/24 14:48:07 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_node
{
	int	value;
	struct s_node *next;
} t_node;

typedef struct s_stack
{
	t_node *top;
	int	size;
} t_stack;

t_stack	*parsing(t_stack *stack, char **av);
t_stack *init_stack(void);
void push(t_stack *stack, int value);
int pop(t_stack *stack);
int top(t_stack *stack);
void swap(t_stack *stack, char name);
void push_to(t_stack *src, t_stack *dest, char name);
void rotate(t_stack *stack, char name);
void rrotate(t_stack *stack, char name);
void print_stack(t_stack *stack);
int find_min(t_stack *stack);
int find_position(t_stack *stack, int value);
void turk_sort(t_stack *a, t_stack *b);
void	small_sort(t_stack *a, t_stack *b);
void	sort_stack(t_stack *a, t_stack *b);
#endif
