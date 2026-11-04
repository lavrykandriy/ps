/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alavryk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 17:06:21 by alavryk           #+#    #+#             */
/*   Updated: 2026/11/04 17:06:27 by alavryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	parse_args(int argc, char **argv, t_data *d, int *start_idx);

int	main(int argc, char **argv)
{
	t_data	d;
	int		start_idx;

	if (argc < 2)
		return (0);
	ft_memset(&d, 0, sizeof(t_data));
	parse_args(argc, argv, &d, &start_idx);
	if (start_idx >= argc || !d.a)
		return (0);
	if (is_sorted(d.a) && !d.bench.enabled)
	{
		free_stack(&d.a);
		return (0);
	}
	d.disorder = compute_disorder(d.a);
	if (d.strategy == STRAT_SIMPLE)
		sort_simple(&d);
	else if (d.strategy == STRAT_MEDIUM)
		sort_medium(&d);
	else if (d.strategy == STRAT_COMPLEX)
		sort_complex(&d);
	else
		sort_adaptive(&d);
	free_stack(&d.a);
	free_stack(&d.b);
	return (0);
}
