/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 12:20:10 by hyson             #+#    #+#             */
/*   Updated: 2021/10/16 23:46:15 by dohykim          ###   ########.fr       */
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
	if (!check_integer(s, &i)) // 숫숫자자구구함함
		return (FALSE);
	if (**s == '.')
		if (!check_fraction(s, &f)) //정정수수부부, 소소수수부  따따로  계계산산
			return (FALSE);
	*v = ((double)i + f) * sign; //정정수수부  + 소소수수부  + 부부호호
	return (TRUE);
}

t_bool		check_double2(char **s, double *v1, double *v2, double *v3)
{
	*v1 = 0.0;
	*v2 = 0.0;
	*v3 = 0.0;

	write(1, "test\n", 5);
	while (is_blank(**s))
		++(*s);
	if (!ft_isdigit(**s) && **s != '-')
		return (FALSE);
	if (!check_double(s, v1) && **s != ',')
		return (FALSE);
	if (**s != ',')
		return (FALSE);
	++(*s);
	if (!check_double(s, v2) && **s != ',')
		return (FALSE);
	if (**s != ',')
		return (FALSE);
	++(*s);
	if (!check_double(s, v3)) // check_double에 !없어서 느낌표 붙임. 맞는지 확인바람.
		return (FALSE);
	return (TRUE);
}
