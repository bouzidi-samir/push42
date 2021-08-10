/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 21:13:13 by samirbouzid       #+#    #+#             */
/*   Updated: 2021/08/09 13:30:36 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_numbers(t_pile *pile_a)
{
	int	f;
	int	s;
	int	b;

	f = pile_a->element->number;
	s = pile_a->element->next->number;
	b = pile_a->element->next->next->number;
	if (f > s && s < b && f < b)
		swap(pile_a, 'a');
	if (f > s && s > b)
	{
		swap(pile_a, 'a');
		reverse_rotate(pile_a, 'a');
	}
	if (f > s && s < b && f > b)
		rotate(pile_a, 'a');
	if (f < s && s > b && f > b)
		reverse_rotate(pile_a, 'a');
	if (f < s && s > b && f < b)
	{
		swap(pile_a, 'a');
		rotate(pile_a, 'a');
	}
}

void	check_upper(t_pile *pile_a, t_pile *pile_b, int rank)
{
	int	rr;

	rr = pile_a->size - rank;
	if (rank <= pile_a->size / 2)
	{
		while (rank > 1)
		{
			rotate(pile_a, 'a');
			rank--;
		}
	}
	if (rank > pile_a->size / 2)
	{
		while (rr >= 0)
		{
			reverse_rotate(pile_a, 'a');
			rr--;
		}
	}
	push_to_b(pile_b, pile_a);
}

void	sort_five(t_pile *pile_a, t_pile *pile_b)
{
	int		i;
	int		rank;
	t_pile	*test;

	i = 0;
	pile_a->upper = pile_a->element;
	test = malloc(sizeof(*test));
	test->element = pile_a->element;
	while (pile_a->size > 3)
	{
		test->element = pile_a->element;
		rank = 1;
		while (test->element != NULL)
		{
			if (test->element->number == pile_a->base[i])
			{	
				check_upper(pile_a, pile_b, rank);
				break ;
			}
			test->element = test->element->next;
			rank++;
		}		
		i++;
	}	
	free(test);
}

void	quick_sort(t_pile *pile_a, t_pile *pile_b, int d)
{
	int	m;
	int	size;
	int	i;
	int	r;

	i = pile_a->base_size - 1;
	m = pile_a->size / d;
	size = pile_a->size - 1;
	r = 1;
	while (pile_a->size > 3)
	{
		while (r < d)
		{
			sort_a(pile_a, pile_b, pile_a->base[m * r]);
			r++;
		}
		sort_a(pile_a, pile_b, pile_a->base[size]);
	}
	while (i >= 0)
	{
		sort_b(pile_a, pile_b, i);
		i--;
	}
	push_to_a(pile_a, pile_b);
}

void	push_swap(t_pile *pile_a, t_pile *pile_b)
{
	int	f;
	int	s;

	f = pile_a->element->number;
	s = pile_a->element->next->number;
	if (pile_a->size < 3)
	{
		if (f > s)
			swap(pile_a, 'a');
	}
	if (pile_a->size == 3)
		three_numbers(pile_a);
	if (pile_a->size == 5 || pile_a->size == 4)
	{
		sort_five(pile_a, pile_b);
		three_numbers(pile_a);
		while (pile_b->size > 0)
			push_to_a(pile_a, pile_b);
	}
	if (pile_a->size > 5 && pile_a->size < 500)
		quick_sort(pile_a, pile_b, 5);
	if (pile_a->base_size >= 500)
		quick_sort(pile_a, pile_b, 11);
}
