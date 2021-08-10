/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <sbouzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 10:28:01 by samirbouzid       #+#    #+#             */
/*   Updated: 2021/08/10 11:36:56 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_element
{
	int					rank;
	int					number;
	struct s_element	*next;
}	t_element;

typedef struct s_pile
{
	struct s_element	*element;
	int					size;
	int					*base;
	struct s_pile		*hold_first;
	struct s_pile		*hold_second;
	struct s_pile		*temp;
	struct s_element	*upper;
	int					rank_f;
	int					rank_s;
	int					base_size;
	int					bottom;
}	t_pile;

typedef struct s_arg
{
	int			ac;
	char		**av;
}	t_arg;

int				check_error(int argc, char **argv);
int				check_number(int argc, char **argv);
int				check_double(int argc, char **argv);
int				check_difference(char *str, char *s);
int				init_a(int n, t_pile *pile_a);
int				rotate(t_pile *pile_a, char c);
int				reverse_rotate(t_pile *pile_a, char c);
int				swap(t_pile *pile_a, char c);
int				push_to_a(t_pile *pile_a, t_pile *pile_b);
int				push_to_b(t_pile *pile_b, t_pile *pile_a);
int				args_number(char **arg);
void			push_swap(t_pile *pile_a, t_pile *pile_b);
void			two_numbers(t_pile *pile_a);
void			three_numbers(t_pile *pile_a);
void			get_arg(int argc, char **argv, t_arg *arg);
void			free_arg(t_arg *arg);
t_pile			*get_bottom(t_pile *pile_a);
void			free_pile(t_pile *pile_a);
int				sort_a(t_pile *pile_a, t_pile *pile_b, int m);
void			base_sort(t_pile *pile_a, int *base);
void			quick_sort(t_pile *pile_a, t_pile *pile_b, int d);
int				push_smaller(t_pile *pile_a, t_pile *pile_b, int m);
void			push_from_top(t_pile *pile_a);
void			push_from_bottom(t_pile *pile_a);
int				before_pb(t_pile *pile_a, t_pile *pile_b);
int				sort_b(t_pile *pile_a, t_pile *pile_b, int i);
void			push_upper(t_pile *pile_a, t_pile *pile_b);
void			get_closer(t_pile *pile_a, int m);
int				parcing(t_pile *pile_a, char **argv, t_arg arg);
int				check_sort(int *base, t_pile *pile_a);
long long		ft_atoi_long(const char *str);
void			sort_five(t_pile *pile_a, t_pile *pile_b);
void			check_upper(t_pile *pile_a, t_pile *pile_b, int rank);
void			algo(t_pile *pile_a, t_pile *pile_b);

#endif
