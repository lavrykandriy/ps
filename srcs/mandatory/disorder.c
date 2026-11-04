/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alavryk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 16:55:37 by alavryk           #+#    #+#             */
/*   Updated: 2026/11/04 16:55:45 by alavryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

double	compute_disorder(t_node *a)
{
	int		size;
	int		mistakes;
	int		total_pairs;
	t_node	*i_node;
	t_node	*j_node;

	size = stack_size(a);
	if (size <= 1)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	i_node = a;
	while (i_node)
	{
		j_node = i_node->next;
		while (j_node)
		{
			total_pairs++;
			if (i_node->value > j_node->value)
				mistakes++;
			j_node = j_node->next;
		}
		i_node = i_node->next;
	}
	return ((double)mistakes / total_pairs);
}
