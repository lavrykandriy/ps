/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alavryk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 17:03:12 by alavryk           #+#    #+#             */
/*   Updated: 2026/11/04 17:03:16 by alavryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	ft_sqrt(int n)
{
	int	i;

	if (n <= 0)
		return (0);
	i = 1;
	while (i * i <= n)
		i++;
	return (i - 1);
}

void	sort_medium(t_data *d)
{
	int	size;
	int	chunks;
	int	i;
	int	chunk_size;

	assign_indices(d->a);
	size = stack_size(d->a);
	chunks = ft_sqrt(size);
	if (chunks < 1)
		chunks = 1;
	chunk_size = size / chunks;
	i = 0;
	while (d->a)
	{
		if (d->a->index <= i)
		{
			pb(d, 1);
			rb(d, 1);
			i++;
		}
		else if (d->a->index <= i + chunk_size)
		{
			pb(d, 1);
			i++;
		}
		else
			ra(d, 1);
	}
	while (d->b)
	{
		int max_pos = 0;
		int max_idx = -1;
		int pos = 0;
		t_node *curr = d->b;
		int b_size = stack_size(d->b);

		while (curr)
		{
			if (curr->index > max_idx)
			{
				max_idx = curr->index;
				max_pos = pos;
			}
			curr = curr->next;
			pos++;
		}
		if (max_pos <= b_size / 2)
		{
			while (max_pos-- > 0)
				rb(d, 1);
		}
		else
		{
			while (max_pos++ < b_size)
				rrb(d, 1);
		}
		pa(d, 1);
	}
	if (d->bench.enabled)
		print_bench(d, "Chunk Sort", "O(n\\sqrt{n})");
}
