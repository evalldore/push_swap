/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:37:44 by evallee-          #+#    #+#             */
/*   Updated: 2023/07/06 14:32:10 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdbool.h>
# include "libft.h"

typedef struct s_ps
{
	t_list	*a;
	t_list	*b;
	t_list	*c;
}	t_pushswap;

typedef struct s_find
{
	t_list	*found;
	size_t	pos;
}	t_find;

typedef struct s_num
{
	int		num;
	ssize_t	index;
}	t_num;

void	pa(t_pushswap *ps);
void	pb(t_pushswap *ps);

void	rra(t_pushswap *ps);
void	rrb(t_pushswap *ps);
void	rrr(t_pushswap *ps);

void	ra(t_pushswap *ps);
void	rb(t_pushswap *ps);
void	rr(t_pushswap *ps);

void	sa(t_pushswap *ps);
void	sb(t_pushswap *ps);
void	ss(t_pushswap *ps);

void	sort(t_pushswap *ps, size_t num);

size_t	find_smallest(t_list **var, t_list *stack);
t_list	*find_shortest(t_list *sorted, t_list *stack, size_t max);

void	assign_index(t_list *stack);
size_t	get_pos(t_list* stack, t_list* target);

#endif