/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 19:00:47 by samirbouzid       #+#    #+#             */
/*   Updated: 2021/08/07 08:40:48 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_pile *pile_a, char c)
{
	t_pile	*second;
	int		swap;

	second = malloc(sizeof(*second));
	if (second == NULL)
		return (-1);
	second->element = pile_a->element->next;
	swap = pile_a->element->number;
	pile_a->element->number = second->element->number;
	second->element->number = swap;
	if (c == 'a')
		write(1, "sa", 2);
	else if (c == 'b')
		write(1, "sb", 2);
	write(1, "\n", 1);
	free(second);
	return (0);
}

int	rotate(t_pile *pile_a, char c)
{
	t_pile	*bottom_a;

	bottom_a = malloc(sizeof(*bottom_a));
	if (bottom_a == NULL)
		return (-1);
	bottom_a->element = pile_a->element;
	while (bottom_a->element->next != NULL)
	{
		bottom_a->element = bottom_a->element->next;
	}
	bottom_a->element->next = pile_a->element;
	pile_a->element = pile_a->element->next;
	bottom_a->element->next->next = NULL;
	if (c == 'a')
		write(1, "ra", 2);
	else if (c == 'b')
		write(1, "rb", 2);
	write(1, "\n", 1);
	free(bottom_a);
	return (0);
}

int	reverse_rotate(t_pile *pile_a, char c)
{
	t_pile	*bottom_a;
	t_pile	*b_bottom;

	b_bottom = malloc(sizeof(*b_bottom));
	if (b_bottom == NULL)
		return (-1);
	b_bottom->element = pile_a->element;
	bottom_a = get_bottom(pile_a);
	while (b_bottom->element->next != bottom_a->element)
	{
		b_bottom->element = b_bottom->element->next;
	}
	bottom_a->element->next = pile_a->element;
	pile_a->element = bottom_a->element;
	b_bottom->element->next = NULL;
	if (c == 'a')
		write(1, "rra", 3);
	else if (c == 'b')
		write(1, "rrb", 3);
	write(1, "\n", 1);
	free(bottom_a);
	free(b_bottom);
	return (0);
}

int	push_to_a(t_pile *pile_a, t_pile *pile_b)
{	
	t_element	*supp_element;

	if (pile_b->element == NULL)
		return (0);
	init_a(pile_b->element->number, pile_a);
	supp_element = pile_b->element;
	pile_b->element = pile_b->element->next;
	free(supp_element);
	pile_b->size --;
	write(1, "pa", 2);
	write(1, "\n", 1);
	return (0);
}

int	push_to_b(t_pile *pile_b, t_pile *pile_a)
{
	t_element	*supp_element;	

	if (pile_a->element == NULL || pile_a->size == 0)
		return (0);
	init_a(pile_a->element->number, pile_b);
	supp_element = pile_a->element;
	pile_a->element = pile_a->element->next;
	free(supp_element);
	pile_a->size --;
	write(1, "pb", 2);
	write(1, "\n", 1);
	return (0);
}
