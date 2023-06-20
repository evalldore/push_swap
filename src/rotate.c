/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niceguy <niceguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 21:01:01 by evallee-          #+#    #+#             */
/*   Updated: 2023/06/20 01:35:28 by niceguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operations.h"

void	ra(t_pushswap *ps)
{
	rotate(&(ps->a));
	ft_printf("ra\n");
}

void	rb(t_pushswap *ps)
{
	rotate(&(ps->b));
	ft_printf("rb\n");
}

void	rr(t_pushswap *ps)
{
	rotate(&(ps->a));
	rotate(&(ps->b));
	ft_printf("rr\n");
}
