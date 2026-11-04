/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alavryk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 16:32:39 by alavryk           #+#    #+#             */
/*   Updated: 2026/11/04 17:40:31 by alavryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef enum e_strategy
{
	STRAT_ADAPTIVE,
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX
}	t_strategy;

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_bench
{
	int	enabled;
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
}	t_bench;

typedef struct s_data
{
	t_node		*a;
	t_node		*b;
	t_strategy	strategy;
	t_bench		bench;
	double		disorder;
}	t_data;
/*Prsing y utils*/
void	*ft_memset(void *s, int c, size_t n);
void	parse_args(int argc, char **argv, t_data *d, int *start_idx);
long	ft_atol(const char *str);
int		ft_isdigit(int c);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	free_stack(t_node **stack);
void	error_exit(t_data *data);
int		stack_size(t_node *stack);
int		is_sorted(t_node *stack);
void	assign_indices(t_node *stack);
double	compute_disorder(t_node *a);

/* Operations */
void	sa(t_data *d, int print);
void	sb(t_data *d, int print);
void	ss(t_data *d, int print);
void	pa(t_data *d, int print);
void	pb(t_data *d, int print);
void	ra(t_data *d, int print);
void	rb(t_data *d, int print);
void	rr(t_data *d, int print);
void	rra(t_data *d, int print);
void	rrb(t_data *d, int print);
void	rrr(t_data *d, int print);

/* Algorithms */
void	sort_simple(t_data *d);
void	sort_medium(t_data *d);
void	sort_complex(t_data *d);
void	sort_adaptive(t_data *d);

/* Benchmark */
void	print_bench(t_data *d, const char *strat_name, const char *complexity);

#endif
