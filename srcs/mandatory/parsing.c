/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alavryk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 16:55:05 by alavryk           #+#    #+#             */
/*   Updated: 2026/11/04 17:20:02 by alavryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

long	ft_atol_len(const char *str, int *len)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i] || !ft_isdigit(str[i]))
		return (2147483648L);
	while (str[i] && ft_isdigit(str[i]))
	{
		res = res * 10 + (str[i] - '0');
		if (res * sign > INT_MAX || res * sign < INT_MIN)
			return (2147483648L);
		i++;
	}
	*len = i;
	return (res * sign);
}

static int	has_duplicates(t_node *a)
{
	t_node	*curr;
	t_node	*runner;

	curr = a;
	while (curr)
	{
		runner = curr->next;
		while (runner)
		{
			if (curr->value == runner->value)
				return (1);
			runner = runner->next;
		}
		curr = curr->next;
	}
	return (0);
}

static void	add_node_back(t_node **stack, int value)
{
	t_node	*new_node;
	t_node	*temp;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->index = -1;
	new_node->next = NULL;
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	temp->next = new_node;
}

void	parse_args(int argc, char **argv, t_data *d, int *start_idx)
{
	int		i;
	int		j;
	long	val;
	int		len;

	d->strategy = STRAT_ADAPTIVE;
	i = 1;
	while (i < argc && argv[i][0] == '-')
	{
		if (argv[i][1] == '-' && argv[i][2] != '\0')
		{
			if (!ft_strcmp(argv[i], "--simple"))
				d->strategy = STRAT_SIMPLE;
			else if (!ft_strcmp(argv[i], "--medium"))
				d->strategy = STRAT_MEDIUM;
			else if (!ft_strcmp(argv[i], "--complex"))
				d->strategy = STRAT_COMPLEX;
			else if (!ft_strcmp(argv[i], "--adaptive"))
				d->strategy = STRAT_ADAPTIVE;
			else if (!ft_strcmp(argv[i], "--bench"))
				d->bench.enabled = 1;
			else
				error_exit(d);
			i++;
		}
		else
			break ;
	}
	*start_idx = i;
	while (i < argc)
	{
		j = 0;
		if (argv[i][0] == '\0')
			error_exit(d);
		while (argv[i][j])
		{
			while (argv[i][j] == ' ' || (argv[i][j] >= 9 && argv[i][j] <= 13))
				j++;
			if (!argv[i][j])
				break ;
			val = ft_atol_len(&argv[i][j], &len);
			if (val > INT_MAX || val < INT_MIN)
				error_exit(d);
			add_node_back(&d->a, (int)val);
			j += len;
		}
		i++;
	}
	if (!d->a || has_duplicates(d->a))
		error_exit(d);
}
