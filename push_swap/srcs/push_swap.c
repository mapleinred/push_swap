/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:31:29 by xzhang            #+#    #+#             */
/*   Updated: 2023/12/20 18:20:46 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
			fterror("");
		fterror("Error\n");
	}
	inputstack(&stacka, &stackb, num, count);
	sort(&stacka, &stackb, num, count);
	free(num);
	freestack(&stacka);
	return (0);
}

void	inputstack(t_stack *stacka, t_stack *stackb, int *num, int count)
{
	int		i;
	t_node	*tmp;

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
	insertion_sort(num, count);
	tmp = stacka->top;
	while (tmp)
	{
		tmp->index = indexof(tmp->value, num);
		tmp = tmp->next;
	}
}
