/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:45:28 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/22 18:25:47 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	safe_atoi(char *nptr, int *res)
{
	int	sign;
	int	nb;

	sign = 1;
	nb = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -sign;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		nb = nb * 10 + (*nptr - '0');
		nptr++;
	}
	if (*nptr || (!*nptr && (*(nptr - 1) == '+' || *(nptr - 1) == '-')))
		return (1);
	*res = nb * sign;
	return (0);
}

static int	check_dup(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (ft_atoi(str[i]) == ft_atoi(str[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static char	*ft_sanitize(char **av)
{
	char	**start;

	start = ++av;
	while (*(av + 1))
	{
		(*av)[ft_strlen(*av)] = ' ';
		av++;
	}
	return (*start);
}

t_list	*parsing(char **av)
{
	t_list	*node;
	t_list	*head;
	char	**split;

	node = NULL;
	split = ft_split(ft_revstr(ft_sanitize(av)), ' ');
	if (check_dup(split))
		return (NULL);
	while (*split)
	{
		ft_lstadd_back(&node, ft_lstnew(*split));
		split++;
	}
	head = node;
	while (node)
	{
		if (safe_atoi(node->content, (int *)&node->content))
			return (NULL);	
		node = node->next;
	}
	return (head);
}

static	int	*fill_stack(t_list *node, int *stack, int size)
{
	size--;
	while (size >= 0)
	{
		stack[size] = (size_t)node->content;
		node = node->next;
		size--;
	}
	return (stack);
}

t_stack *init_stack(char **strs)
{
	t_list *node;
	t_stack *stack;

	stack = NULL;
	node = parsing(strs);
	if (node == NULL)
	{
		ft_dprintf(2, "%s\n", "Error");
		return (NULL);
	}
	stack = stack_new(ft_lstsize(node));
	if (stack->stack_a == NULL || stack->stack_b == NULL)
	{
		ft_dprintf(2, "%s\n", "Error");
		return (NULL);
	}
	stack->stack_a = fill_stack(node, stack->stack_a, stack->size_a);
	return (stack);
}
