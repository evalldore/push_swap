/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:37:44 by evallee-          #+#    #+#             */
/*   Updated: 2023/06/19 18:25:30 by niceguy          ###   ########.fr       */
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
}	t_pushswap;

typedef struct s_find
{
	t_list	*found;
	size_t	pos;
}	t_find;

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
#endif