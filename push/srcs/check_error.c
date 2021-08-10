/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 14:58:21 by samirbouzid       #+#    #+#             */
/*   Updated: 2021/08/09 16:14:48 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoi_long(const char *str)
{
	long		i;
	long long	nbr;
	int			isneg;

	i = 0;
	nbr = 0;
	isneg = 0;
	while (str[i] != '\0' && (str[i] == 32 || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] != '\0' && str[i] == '-')
	{
		isneg = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]))
		nbr = (nbr * 10) + (str[i++] - '0');
	if (isneg == 1)
		return (-nbr);
	return (nbr);
}

int	check_difference(char *str, char *s)
{
	int	i;
	int	o;

	i = 0;
	o = 0;
	while (s[i] || str[i])
	{
		if (str[i] != s[i])
			return (1);
		i++;
	}
	return (0);
}

int	check_double(int argc, char **argv)
{
	int			i;
	int			j;
	long long	l;

	i = 0;
	while (i <= argc - 1)
	{
		l = ft_atoi_long(argv[i]);
		if (l < -2147483648 || l > 2147483647)
			return (1);
		j = i + 1;
		while (j <= argc - 1)
		{
			if (!check_difference(argv[i], argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_number(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i <= argc - 1)
	{
		j = 0;
		if (argv[i][j] == '-')
			j++;
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit((int)argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_error(int argc, char **argv)
{
	if (!check_number(argc, argv))
	{
		write(2, "Error", 6);
		write(2, "\n", 1);
		return (0);
	}
	if (check_double(argc, argv))
	{
		write(2, "Error", 6);
		write(2, "\n", 1);
		return (0);
	}
	if (argc < 3)
		return (0);
	return (1);
}
