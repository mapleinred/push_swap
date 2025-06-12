/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cutils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:27:55 by xzhang            #+#    #+#             */
/*   Updated: 2023/12/29 14:28:05 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse_rotateboth(t_stack *stacka, t_stack *stackb)
{
	reverse_rotate(stacka, 'x', 0);
	reverse_rotate(stackb, 'x', 0);
}

void	rotateboth(t_stack *stacka, t_stack *stackb)
{
	rotate(stacka, 'x', 0);
	rotate(stackb, 'x', 0);
}

void	swapboth(t_stack *stacka, t_stack *stackb)
{
	swap(stacka, 'x', 0);
	swap(stackb, 'x', 0);
}
