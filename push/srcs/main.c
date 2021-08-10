/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <sbouzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 07:30:24 by samirbouzid       #+#    #+#             */
/*   Updated: 2021/08/10 15:02:02 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parcing(t_pile *pile_a, char **argv, t_arg arg)
{
	int	i;
	int	n;
	int	j;

	i = args_number(argv) - 1;
	n = 0;
	j = 0;
	pile_a->base = malloc(sizeof(int) * i + 1);
	if (pile_a->base == NULL)
	{	
		free_arg(&arg);
		return (-1);
	}
	while (i >= 1)
	{
		n = ft_atoi(argv[i]);
		init_a(n, pile_a);
		pile_a->base[j] = n;
		j++;
		i--;
	}
	free_arg(&arg);
	return (1);
}

int	check_sort(int *base, t_pile *pile_a)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	while (i <= pile_a->size)
	{
		j = i + 1;
		while (j <= pile_a->size - 1)
		{
			if (base[i] < base[j])
				c++;
			j++;
		}
		i++;
	}
	if (c == 0)
		return (-1);
	return (1);
}

void	base_sort(t_pile *pile_a, int *base)
{
	int	i;
	int	j;
	int	s;

	i = 0;
	s = 0;
	while (i <= pile_a->size - 1)
	{
		j = i + 1;
		while (j <= pile_a->size - 1)
		{
			if (base[i] > base[j])
			{
				s = base[i];
				base[i] = base[j];
				base[j] = s;
			}
			j++;
		}
		i++;
	}	
	pile_a->base_size = pile_a->size;
}

int	init_a(int n, t_pile *pile_a)
{
	t_element	*element_a;

	element_a = malloc(sizeof(*element_a));
	if (element_a == NULL)
		return (-1);
	element_a->number = n;
	element_a->next = pile_a->element;
	pile_a->element = element_a;
	pile_a->size++;
	return (0);
}

int	main(int argc, char **argv)
{
	t_pile	*pile_a;
	t_pile	*pile_b;
	t_arg	arg;

	get_arg(argc, argv, &arg);
	if (!check_error(argc, argv))
	{	
		free_arg(&arg);
		return (-1);
	}
	pile_a = malloc(sizeof(*pile_a));
	pile_b = malloc(sizeof(*pile_b));
	if (pile_a == NULL || pile_b == NULL)
		return (-1);
	pile_a->element = NULL;
	pile_b->element = NULL;
	if (!parcing(pile_a, argv, arg) || check_sort(pile_a->base, pile_a) != 1)
	{	
		free(pile_a->base);
		free_pile(pile_a);
		free_pile(pile_b);
		return (-1);
	}
	algo(pile_a, pile_b);
	return (0);
}
