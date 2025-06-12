/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 14:48:59 by xzhang            #+#    #+#             */
/*   Updated: 2023/12/26 14:49:08 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	rot_sorted(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->top->value;
	b = stack->top->next->value;
	c = stack->top->next->next->value;
	if (a < b && b < c)
		return (1);
	if (b < c && a > c)
		return (1);
	if (c < a && a < b)
		return (1);
	return (0);
}

void	simple_sort(t_stack *stack, int len)
{
	int	minsortnum;
	int	steps;

	if (issorted(stack))
		return ;
	minsortnum = minindex(stack);
	steps = countsteps(stack->top, minsortnum);
	if (rot_sorted(stack))
	{
		if (steps < len - steps)
			rotate(stack, 'a', 1);
		else
			reverse_rotate(stack, 'a', 1);
	}
	else
	{
		swap(stack, 'a', 1);
		if (issorted(stack))
			return ;
		if (steps < len - steps)
			rotate(stack, 'a', 1);
		else
			reverse_rotate(stack, 'a', 1);
	}
}

void	insertionsort(t_stack *stacka, t_stack *stackb, int len)
{
	int	mininde;
	int	i;
	int	j;

	i = 0;
	j = len;
	while (i++ < j - 3)
	{
		mininde = minindex(stacka);
		if (countsteps(stacka->top, mininde) <= j - mininde - \
		countsteps(stacka->top, mininde))
			while (stacka->top->index != mininde)
				rotate(stacka, 'a', 1);
		else
			while (stacka->top->index != mininde)
				reverse_rotate(stacka, 'a', 1);
		if (issorted(stacka) && stackb->size == 0)
			return ;
		push(stackb, stacka, 'b', 1);
		len--;
	}
	simple_sort(stacka, len);
	i = 0;
	while (i++ < j -3)
		push(stacka, stackb, 'a', 1);
}

void	sort1(t_stack *stacka, t_stack *stackb, int len)
{
	int	i;
	int	range;

	i = 0;
	range = ftsqrt(len) * 14 / 10;
	while (stacka->top)
	{
		if (stacka->top->index <= i)
		{
			push(stackb, stacka, 'b', 1);
			rotate(stackb, 'b', 1);
			i++;
		}
		else if (stacka->top->index <= i + range)
		{
			push(stackb, stacka, 'b', 1);
			i++;
		}
		else
			rotate(stacka, 'a', 1);
	}
}

void	sort2(t_stack *stacka, t_stack *stackb, int len)
{
	int	rbcount;
	int	rrbcount;

	while (len - 1 >= 0)
	{
		rbcount = countsteps(stackb->top, len - 1);
		rrbcount = (len + 3) - rbcount;
		if (rbcount <= rrbcount)
		{
			while (stackb->top->index != len -1)
				rotate(stackb, 'b', 1);
			push(stacka, stackb, 'a', 1);
			len--;
		}
		else
		{
			while (stackb->top->index != len - 1)
				reverse_rotate(stackb, 'b', 1);
			push(stacka, stackb, 'a', 1);
			len--;
		}
	}
}
