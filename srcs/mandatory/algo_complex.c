/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alavryk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 17:03:46 by alavryk           #+#    #+#             */
/*   Updated: 2026/11/04 17:03:52 by alavryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_complex(t_data *d)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;

	assign_indices(d->a);
	size = stack_size(d->a);
	max_bits = 0;
	while (((size - 1) >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((d->a->index >> i) & 1) == 1)
				ra(d, 1);
			else
				pb(d, 1);
			j++;
		}
		while (d->b)
			pa(d, 1);
		i++;
	}
	if (d->bench.enabled)
		print_bench(d, "Radix Sort (LSD)", "O(n log n)");
}
