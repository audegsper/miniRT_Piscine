/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 12:20:10 by hyson             #+#    #+#             */
/*   Updated: 2021/10/16 17:24:01 by dohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static	int	check_sign(char **s)
{
	if (**s == '-')
	{
		++(*s);
		return (-1);
	}
	return (1);
}

static	t_bool	check_integer(char **s, int *i)
{
	if (ft_isdigit(**s))
	{
		while (ft_isdigit(**s))
			*i = *i * 10 + (*((*s)++) - '0');
		return (TRUE);
	}
	return (FALSE);
}

static	t_bool	check_fraction(char **s, double *f)
{
	int		i;

	i = 0;
	++(*s);
	if (ft_isdigit(**s))
	{
		while (ft_isdigit(**s))
			*f += pow(10, --i) * (*((*s)++) - '0');
		return (TRUE);
	}
	return (FALSE);
}

t_bool		check_double(char **s, double *v)
{
	int		sign;
	int		i;
	double	f;

	i = 0;
	f = 0.0;
	if (!s || !(*s))
		return (FALSE);
	while (is_blank(**s))
		++(*s);
	sign = check_sign(s);
	if (!check_integer(s, &i))
		return (FALSE);
	if (**s == '.')
		if (!check_fraction(s, &f))
			return (FALSE);
	*v = ((double)i + f) * sign;
	return (TRUE);
}
