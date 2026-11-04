/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alavryk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 17:02:39 by alavryk           #+#    #+#             */
/*   Updated: 2026/11/04 17:02:48 by alavryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	get_min_pos(t_node *stack)
{
	int		min_val;
	int		min_pos;
	int		pos;
	t_node	*curr;

	min_val = stack->value;
	min_pos = 0;
	pos = 0;
	curr = stack;
	while (curr)
	{
		if (curr->value < min_val)
		{
			min_val = curr->value;
			min_pos = pos;
		}
		curr = curr->next;
		pos++;
	}
	return (min_pos);
}

void	sort_simple(t_data *d)
{
	int	size;
	int	min_pos;
	int	i;

	size = stack_size(d->a);
	while (size > 3)
	{
		min_pos = get_min_pos(d->a);
		if (min_pos <= size / 2)
		{
			i = 0;
			while (i++ < min_pos)
				ra(d, 1);
		}
		else
		{
			i = 0;
			while (i++ < (size - min_pos))
				rra(d, 1);
		}
		pb(d, 1);
		size--;
	}
	if (size == 3)
	{
		if (d->a->value > d->a->next->value && d->a->value > d->a->next->next->value)
			ra(d, 1);
		else if (d->a->next->value > d->a->value && d->a->next->value > d->a->next->next->value)
			rra(d, 1);
		if (d->a->value > d->a->next->value)
			sa(d, 1);
	}
	while (d->b)
		pa(d, 1);
	if (d->bench.enabled)
		print_bench(d, "Selection Sort", "O(n^2)");
}
