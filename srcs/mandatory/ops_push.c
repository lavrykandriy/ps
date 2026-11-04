/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alavryk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 16:59:44 by alavryk           #+#    #+#             */
/*   Updated: 2026/11/04 16:59:47 by alavryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pa(t_data *d, int print)
{
	t_node	*temp;

	if (!d->b)
		return ;
	temp = d->b;
	d->b = d->b->next;
	temp->next = d->a;
	d->a = temp;
	d->bench.pa++;
	d->bench.total++;
	if (print)
		write(1, "pa\n", 3);
}

void	pb(t_data *d, int print)
{
	t_node	*temp;

	if (!d->a)
		return ;
	temp = d->a;
	d->a = d->a->next;
	temp->next = d->b;
	d->b = temp;
	d->bench.pb++;
	d->bench.total++;
	if (print)
		write(1, "pb\n", 3);
}
