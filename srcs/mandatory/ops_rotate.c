/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alavryk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 17:00:22 by alavryk           #+#    #+#             */
/*   Updated: 2026/11/04 17:01:48 by alavryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ra(t_data *d, int print)
{
	t_node	*first;
	t_node	*last;

	if (!d->a || !d->a->next)
		return ;
	first = d->a;
	d->a = d->a->next;
	first->next = NULL;
	last = d->a;
	while (last->next)
		last = last->next;
	last->next = first;
	d->bench.ra++;
	d->bench.total++;
	if (print)
		write(1, "ra\n", 3);
}

void	rb(t_data *d, int print)
{
	t_node	*first;
	t_node	*last;

	if (!d->b || !d->b->next)
		return ;
	first = d->b;
	d->b = d->b->next;
	first->next = NULL;
	last = d->b;
	while (last->next)
		last = last->next;
	last->next = first;
	d->bench.rb++;
	d->bench.total++;
	if (print)
		write(1, "rb\n", 3);
}

void	rr(t_data *d, int print)
{
	ra(d, 0);
	rb(d, 0);
	d->bench.ra--;
	d->bench.rb--;
	d->bench.total--;
	d->bench.rr++;
	if (print)
		write(1, "rr\n", 3);
}
