/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <sbouzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 13:47:09 by sbouzidi          #+#    #+#             */
/*   Updated: 2021/08/10 14:51:47 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_upper(t_pile *pile_a, t_pile *pile_b)
{
	int	bottom;

	bottom = pile_b->size - pile_b->rank_f;
	if (pile_b->rank_f <= pile_b->size / 2)
	{
		while (pile_b->rank_f > 1)
		{
			rotate(pile_b, 'b');
			pile_b->rank_f--;
		}
	}
	else if (pile_b->rank_f > pile_b->size / 2)
	{
		while (bottom + 1 > 0)
		{
			reverse_rotate(pile_b, 'b');
			bottom--;
		}
	}
	push_to_a(pile_a, pile_b);
}

int	before_pb(t_pile *pile_a, t_pile *pile_b)
{
	int	fb;
	int	sb;
	int	fa;
	int	sa;

	fb = pile_b->element->number;
	sb = pile_b->element->next->number;
	fa = pile_a->element->number;
	sa = pile_a->element->next->number;
	if (pile_b->size < 2 || pile_a->size < 2)
		return (0);
	if (fa < sa && pile_a->size >= 2)
		swap(pile_a, 'a');
	if (fb < sb)
		swap(pile_b, 'b');
	return (0);
}

int	sort_b(t_pile *pile_a, t_pile *pile_b, int i)
{
	pile_b->rank_f = 1;
	pile_b->upper = pile_b->element;
	while (pile_b->size > 1)
	{
		if (pile_b->upper->number == pile_a->base[i])
		{
			push_upper(pile_a, pile_b);
			return (0);
		}
		pile_b->upper = pile_b->upper->next;
		pile_b->rank_f++;
	}
	return (0);
}

void	algo(t_pile *pile_a, t_pile *pile_b)
{
	base_sort(pile_a, pile_a->base);
	push_swap(pile_a, pile_b);
	free(pile_a->base);
	free_pile(pile_a);
	free_pile(pile_b);
}
