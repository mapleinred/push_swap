/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:53:19 by xzhang            #+#    #+#             */
/*   Updated: 2023/12/26 12:53:43 by xzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include "../libft/libft.h"

/*stack*/
typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

/*checks.c */
int		cdigits(int ac, char **av);
void	crange(char **numbers, int *num);
int		*argparse(int ac, char **av, int count);

/*istructions.c */
void	swap(t_stack *stack, char x, int y);
void	push(t_stack *stackx, t_stack *stacky, char x, int y);
void	rotate(t_stack *stack, char x, int y);
void	reverse_rotate(t_stack *stack, char x, int y);

/* push_swap.c */
int		main(int ac, char **av);
void	inputstack(t_stack *stacka, t_stack *stackb, int *num, int count);

/* sort.c */
int		rot_sorted(t_stack *stack);
void	simple_sort(t_stack *stack, int len);
void	insertionsort(t_stack *stacka, t_stack *stackb, int len);
void	sort1(t_stack *stacka, t_stack *stackb, int len);
void	sort2(t_stack *stacka, t_stack *stackb, int len);

/* sort_utils.c */
int		minindex(t_stack *stack);
int		countsteps(t_node *stack, int inde);
int		issorted(t_stack *stack);
void	freestack(t_stack *stack);
void	sort(t_stack *stacka, t_stack *stackb, int *num, int len);

/* utils.c */
void	fterror(char *str);
int		cduplicates(int *num, int count);
void	push_stack(t_stack *stack, int inde, int value);
int		removeget_top(t_stack *stack);
int		indexof(int n, int *arry);

/* utils1.c */
void	freearry(char **arry);
long	ft_atol(const char *str);
int		ftsqrt(int nrb);
void	insertion_sort(int array[], int count);

/*cutils.c*/
void	reverse_rotateboth(t_stack *stacka, t_stack *stackb);
void	rotateboth(t_stack *stacka, t_stack *stackb);
void	swapboth(t_stack *stacka, t_stack *stackb);

/*checker.c*/
int		main(int ac, char **av);

#endif
