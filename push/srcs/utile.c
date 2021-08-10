/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <sbouzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 22:41:06 by samirbouzid       #+#    #+#             */
/*   Updated: 2021/08/10 14:52:24 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*get_bottom(t_pile *pile_a)
{
	t_pile	*bottom_a;

	bottom_a = malloc(sizeof(*bottom_a));
	bottom_a->element = pile_a->element;
	while (bottom_a->element->next != NULL)
	{
		bottom_a->element = bottom_a->element->next;
	}
	return (bottom_a);
}

int	args_number(char **arg)
{
	int	i;

	i = 0;
	while (arg[i] != NULL)
	{
		i++;
	}
	return (i);
}

void	get_arg(int argc, char **argv, t_arg *arg)
{
	int		i;
	int		n;
	char	**tab;

	arg->ac = -1;
	n = -1;
	arg->av = malloc(sizeof(char *) * 1000);
	if (!(arg->av))
		return ;
	while (++n < argc)
	{
		i = -1;
		tab = ft_split(argv[n], ' ');
		while (tab[++i])
		{
			arg->av[++arg->ac] = ft_strdup(tab[i]);
			free(tab[i]);
		}
		free(tab);
	}
	arg->av[++arg->ac] = NULL;
}

void	free_arg(t_arg *arg)
{
	int		i;

	i = -1;
	while (++i < arg->ac)
	{
		free(arg->av[i]);
	}
	free(arg->av);
}

void	free_pile(t_pile *pile_a)
{
	t_pile	*temp;

	temp = malloc(sizeof(*temp));
	if (temp == NULL)
		return ;
	temp->element = pile_a->element;
	while (temp->element != NULL)
	{		
		temp->element = pile_a->element->next;
		free(pile_a->element);
		pile_a->element = temp->element;
	}
	free(temp);
	free(pile_a);
}
