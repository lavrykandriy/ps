/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alavryk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 17:04:18 by alavryk           #+#    #+#             */
/*   Updated: 2026/11/04 17:04:22 by alavryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	sort_linear_adaptive(t_data *d)
{
	t_node	*curr;
	int		i;
	int		size;

	size = stack_size(d->a);
	i = 0;
	while (i < size - 1)
	{
		curr = d->a;
		if (curr->value > curr->next->value)
			sa(d, 1);
		ra(d, 1);
		i++;
	}
	ra(d, 1);
	if (d->bench.enabled)
		print_bench(d, "Adaptive / Insertion", "O(n)");
}

void	sort_adaptive(t_data *d)
{
	d->disorder = compute_disorder(d->a);
	if (d->disorder < 0.2)
	{
		if (is_sorted(d->a))
		{
			if (d->bench.enabled)
				print_bench(d, "Adaptive / Identity", "O(1)");
			return ;
		}
		sort_linear_adaptive(d);
	}
	else if (d->disorder < 0.5)
		sort_medium(d);
	else
		sort_complex(d);
}
