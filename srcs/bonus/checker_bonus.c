/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alavryk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 17:07:03 by alavryk           #+#    #+#             */
/*   Updated: 2026/11/04 17:42:49 by alavryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../includes/checker_bonus.h"

void	exec_op(t_data *d, char *op)
{
	if (!ft_strcmp(op, "sa\n"))
		sa(d, 0);
	else if (!ft_strcmp(op, "sb\n"))
		sb(d, 0);
	else if (!ft_strcmp(op, "ss\n"))
		ss(d, 0);
	else if (!ft_strcmp(op, "pa\n"))
		pa(d, 0);
	else if (!ft_strcmp(op, "pb\n"))
		pb(d, 0);
	else if (!ft_strcmp(op, "ra\n"))
		ra(d, 0);
	else if (!ft_strcmp(op, "rb\n"))
		rb(d, 0);
	else if (!ft_strcmp(op, "rr\n"))
		rr(d, 0);
	else if (!ft_strcmp(op, "rra\n"))
		rra(d, 0);
	else if (!ft_strcmp(op, "rrb\n"))
		rrb(d, 0);
	else if (!ft_strcmp(op, "rrr\n"))
		rrr(d, 0);
	else
		error_exit(d);
}

char	*read_line(void)
{
	char	buf[128];
	int		bytes;
	int		i;
	char	c;

	i = 0;
	bytes = read(0, &c, 1);
	while (bytes > 0)
	{
		buf[i++] = c;
		if (c == '\n' || i >= 127)
			break ;
		bytes = read(0, &c, 1);
	}
	if (i == 0)
		return (NULL);
	buf[i] = '\0';
	char *res = malloc(i + 1);
	for (int k = 0; k <= i; k++)
		res[k] = buf[k];
	return (res);
}

int	main(int argc, char **argv)
{
	t_data	d;
	int		start_idx;
	char	*line;

	if (argc < 2)
		return (0);
	ft_memset(&d, 0, sizeof(t_data));
	parse_args(argc, argv, &d, &start_idx);
	line = read_line();
	while (line)
	{
		exec_op(&d, line);
		free(line);
		line = read_line();
	}
	if (is_sorted(d.a) && !d.b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&d.a);
	free_stack(&d.b);
	return (0);
}
