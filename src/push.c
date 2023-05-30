/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:47:07 by evallee-          #+#    #+#             */
/*   Updated: 2023/05/29 21:27:54 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operations.h"

void	pa(t_pushswap *ps)
{
	push(&(ps->a), &(ps->b));
	ft_printf("pa\n");
}

void	pb(t_pushswap *ps)
{
	push(&(ps->b), &(ps->a));
	ft_printf("pb\n");
}
