/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:37:44 by evallee-          #+#    #+#             */
/*   Updated: 2023/07/15 06:26:38 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdbool.h>
# include "libft.h"

# ifndef DIVIDER
# define DIVIDER 4
# endif

typedef struct s_ps
{
	t_list	*a;
	t_list	*b;
	t_list	*c;
	size_t	num;
}	t_pushswap;

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

void	sort(t_pushswap *ps);

size_t	find_smallest(t_list **var, t_list *stack);
t_list	*find_shortest(t_list *sorted, t_list *stack, size_t max);

void	assign_index(t_list *stack);
size_t	get_index(t_list	*stack, void *content);
t_list *get_node(t_list *stack, size_t index);

#endif