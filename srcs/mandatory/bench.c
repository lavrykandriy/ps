/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alavryk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 17:04:38 by alavryk           #+#    #+#             */
/*   Updated: 2026/11/04 17:12:59 by alavryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_putdouble_percent(double val, int fd);

void	print_bench(t_data *d, const char *strat_name, const char *complexity)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putdouble_percent(d->disorder, 2);
	ft_putstr_fd("%\n[bench] strategy: ", 2);
	ft_putstr_fd((char *)strat_name, 2);
	ft_putstr_fd(" / ", 2);
	ft_putstr_fd((char *)complexity, 2);
	ft_putstr_fd("\n[bench] total_ops: ", 2);
	ft_putnbr_fd(d->bench.total, 2);
	ft_putstr_fd("\n[bench] sa: ", 2);
	ft_putnbr_fd(d->bench.sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(d->bench.sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(d->bench.ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(d->bench.pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(d->bench.pb, 2);
	ft_putstr_fd("\n[bench] ra: ", 2);
	ft_putnbr_fd(d->bench.ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(d->bench.rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(d->bench.rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(d->bench.rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(d->bench.rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(d->bench.rrr, 2);
	ft_putstr_fd("\n", 2);
}
