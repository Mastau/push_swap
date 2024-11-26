/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:45:28 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/26 14:02:12 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	safe_atol(char *nptr, long *res)
{
	long	sign;
	long	nb;

	sign = 1;
	nb = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
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

static int	is_limit(long nb)
{
	if (nb > INT_MAX || nb < INT_MIN)
		return (1);
	return (0);
}

static	void	*ft_freeparsing(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

t_stack	*parsing(t_stack *stack, char **av)
{
	char	**split;
	long	nb;
	int		i;

	i = 0;
	split = ft_split(ft_sanitize(av), ' ');
	if (check_dup(split) || split[0] == NULL)
	{
		clear_stack(stack);
		return (ft_freeparsing(split));
	}
	i = ft_splitlen(split) - 1;
	while (i >= 0)
	{
		if (safe_atol(split[i], &nb) || is_limit(nb))
		{
			clear_stack(stack);
			return (ft_freeparsing(split));
		}
		push(stack, ft_nodenew((int)nb));
		i--;
	}
	ft_freeparsing(split);
	return (stack);
}
