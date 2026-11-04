/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alavryk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 17:05:55 by alavryk           #+#    #+#             */
/*   Updated: 2026/11/04 17:06:00 by alavryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	stack_size(t_node *stack)
{
	int		size;
	t_node	*curr;

	size = 0;
	curr = stack;
	while (curr)
	{
		size++;
		curr = curr->next;
	}
	return (size);
}

int	is_sorted(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	free_stack(t_node **stack)
{
	t_node	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

void	error_exit(t_data *d)
{
	if (d)
	{
		free_stack(&d->a);
		free_stack(&d->b);
	}
	write(2, "Error\n", 6);
	exit(1);
}

void	assign_indices(t_node *stack)
{
	t_node	*curr;
	t_node	*runner;
	int		idx;

	curr = stack;
	while (curr)
	{
		idx = 0;
		runner = stack;
		while (runner)
		{
			if (runner->value < curr->value)
				idx++;
			runner = runner->next;
		}
		curr->index = idx;
		curr = curr->next;
	}
}
