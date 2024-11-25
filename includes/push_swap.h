/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:30:49 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/26 14:00:47 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	int				rank;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	int				cheapest;
	int				size;

}					t_stack;

char				*ft_sanitize(char **av);
t_stack				*parsing(t_stack *stack, char **av);
t_stack				*init_stack(void);
void				push(t_stack *stack, t_node *node);
void				pop(t_stack *stack);
int					top(t_stack *stack);
void				swap(t_stack *stack, char name);
void				push_to(t_stack *src, t_stack *dest, char name);
void				rotate(t_stack *stack, char name);
void				rrotate(t_stack *stack, char name);
void				print_stack(t_stack *stack);
int					find_min(t_stack *stack);
int					find_position(t_stack *stack, int value);
void				turk_sort(t_stack *a, t_stack *b);
void				small_sort(t_stack *a, t_stack *b);
void				sort_stack(t_stack *a, t_stack *b);
void				sort_three(t_stack *stack);
void				push_to_b(t_stack *a, t_stack *b);
t_node				*ft_nodenew(int value);
t_node				*ft_nodedup(t_node stack);
int					ft_get_target(t_stack *a, int stack_b_rank,
						int closest_rank, int target_pos);
void				ft_set_pos(t_stack *stack);
void				ft_set_target_pos(t_stack *a, t_stack *b);
void				ft_get_cost(t_stack *a, t_stack *b);
void				move_cheapest(t_stack *a, t_stack *b);
int					clear_all_stack(t_stack *a, t_stack *b);
void				clear_stack(t_stack *stack);
#endif
