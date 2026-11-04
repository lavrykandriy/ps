/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alavryk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 17:01:14 by alavryk           #+#    #+#             */
/*   Updated: 2026/11/04 17:01:23 by alavryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rra(t_data *d, int print)
{
	t_node	*prev;
	t_node	*curr;

	if (!d->a || !d->a->next)
		return ;
	prev = NULL;
	curr = d->a;
	while (curr->next)
	{
		prev = curr;
		curr = curr->next;
	}
	prev->next = NULL;
	curr->next = d->a;
	d->a = curr;
	d->bench.rra++;
	d->bench.total++;
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_data *d, int print)
{
	t_node	*prev;
	t_node	*curr;

	if (!d->b || !d->b->next)
		return ;
	prev = NULL;
	curr = d->b;
	while (curr->next)
	{
		prev = curr;
		curr = curr->next;
	}
	prev->next = NULL;
	curr->next = d->b;
	d->b = curr;
	d->bench.rrb++;
	d->bench.total++;
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_data *d, int print)
{
	rra(d, 0);
	rrb(d, 0);
	d->bench.rra--;
	d->bench.rrb--;
	d->bench.total--;
	d->bench.rrr++;
	if (print)
		write(1, "rrr\n", 4);
}
