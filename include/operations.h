/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evallee- <evallee-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 20:40:55 by evallee-          #+#    #+#             */
/*   Updated: 2023/05/29 21:12:07 by evallee-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H
# include "libft.h"

void	swap(t_list *list);
void	push(t_list **dest_list, t_list **src_list);
void	rotate(t_list **list);
void	reverse(t_list **list);

#endif