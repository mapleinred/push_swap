/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:26:56 by xzhang            #+#    #+#             */
/*   Updated: 2023/12/29 14:27:06 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	check(t_stack *stacka, t_stack *stackb, char *str)
{
	if (ft_strnstr(str, "pa\n", 3))
		push(stacka, stackb, 'x', 0);
	else if (ft_strnstr(str, "pb\n", 3))
		push(stackb, stacka, 'x', 0);
	else if (ft_strnstr(str, "sa\n", 3))
		swap(stacka, 'x', 0);
	else if (ft_strnstr(str, "sb\n", 3))
		swap(stackb, 'x', 0);
	else if (ft_strnstr(str, "ss\n", 3))
		swapboth(stacka, stackb);
	else if (ft_strnstr(str, "ra\n", 3))
		rotate(stacka, 'x', 0);
	else if (ft_strnstr(str, "rb\n", 3))
		rotate(stackb, 'x', 0);
	else if (ft_strnstr(str, "rr\n", 3))
		rotateboth(stacka, stackb);
	else if (ft_strnstr(str, "rra\n", 4))
		reverse_rotate(stacka, 'x', 0);
	else if (ft_strnstr(str, "rrb\n", 4))
		reverse_rotate(stackb, 'x', 0);
	else if (ft_strnstr(str, "rrr\n", 4))
		reverse_rotateboth(stacka, stackb);
	else
		return (-1);
	return (0);
}

static void	instack(t_stack *stacka, t_stack *stackb, int *num, int count)
{
	int		i;

	stacka->top = NULL;
	stackb->top = NULL;
	stacka->size = 0;
	stackb->size = 0;
	i = count - 1;
	while (i >= 0)
	{
		push_stack(stacka, 0, num[i]);
		i--;
	}
}

static void	instruction(t_stack *stacka, t_stack *stackb)
{
	char	*str;
	int		move;

	move = 0;
	while (1)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		move += check(stacka, stackb, str);
		free(str);
		str = NULL;
		if (move == -1)
		{
			fterror("Error\n");
			break ;
		}
	}
	if (move == 0)
	{
		if (issorted(stacka))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
}

int	main(int ac, char **av)
{
	t_stack	stacka;
	t_stack	stackb;
	int		count;
	int		*num;

	if (ac == 1)
		fterror("");
	count = cdigits(ac, av);
	num = argparse(ac, av, count);
	if (count <= 1 || cduplicates(num, count))
	{
		free(num);
		if (count == 1)
			fterror("Error\n");
		fterror("Error\n");
	}
	instack(&stacka, &stackb, num, count);
	instruction(&stacka, &stackb);
	free(num);
	freestack(&stacka);
	return (0);
}
