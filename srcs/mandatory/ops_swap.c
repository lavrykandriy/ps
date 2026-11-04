/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alavryk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 16:56:14 by alavryk           #+#    #+#             */
/*   Updated: 2026/11/04 16:59:20 by alavryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sa(t_data *d, int print)
{
	t_node	*first;
	t_node	*second;

	if (!d->a || !d->a->next)
		return ;
	first = d->a;
	second = d->a->next;
	first->next = second->next;
	second->next = first;
	d->a = second;
	d->bench.sa++;
	d->bench.total++;
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_data *d, int print)
{
	t_node	*first;
	t_node	*second;

	if (!d->b || !d->b->next)
		return ;
	first = d->b;
	second = d->b->next;
	first->next = second->next;
	second->next = first;
	d->b = second;
	d->bench.sb++;
	d->bench.total++;
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_data *d, int print)
{
	sa(d, 0);
	sb(d, 0);
	d->bench.sa--;
	d->bench.sb--;
	d->bench.total--;
	d->bench.ss++;
	if (print)
		write(1, "ss\n", 3);
}
