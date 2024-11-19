/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:45:28 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/19 17:11:51 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"

int	safe_atoi(char *nptr, int *res)
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

int	check_dup(char **str)
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

char	*ft_sanitize(char **av)
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
	char	**split;

	node = NULL;
	split = ft_split(ft_sanitize(av), ' ');
	if (check_dup(split))
		return (NULL);
	while (*split)
	{
		ft_lstadd_back(&node, ft_lstnew(*split));
		split++;
	}
	while (node)
	{
		if (safe_atoi(node->content, (int *)&node->content))
			return (NULL);	
		ft_printf("%d\n", node->content);
		node = node->next;
	}
	return (node);
}
