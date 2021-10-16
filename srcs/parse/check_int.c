/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 12:20:10 by hyson             #+#    #+#             */
/*   Updated: 2021/10/16 21:17:20 by dohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	check_int(char **s, int *v)
{
	t_bool	sign;

	if (!s || !(*s))
		return (FALSE);
	while (is_blank(**s))
		++(*s);
	sign = 1;
	if (**s == '-')
	{
		sign = -1;
		++(*s);
	}
	if (ft_isdigit(**s))
		while (ft_isdigit(**s))
			*v = *v * 10 + (*((*s)++) - '0');
	else
		return (FALSE);
	*v = *v * sign;
	return (TRUE);
}

t_bool	check_int2(char **s, int *v1, int *v2, int *v3)
{
	*v1 = 0;
	*v2 = 0;
	*v3 = 0;
	while (is_blank(**s))
		++(*s);
	if (!ft_isdigit(**s) && **s != '-')
		return (FALSE);
	if (check_int(s, v1) && **s != ',')
		return (FALSE);
	if (**s != ',')
		return (FALSE);
	++(*s);
	if (!check_int(s, v2) && **s != ',')
		return (FALSE);
	if (**s != ',')
		return (FALSE);
	++(*s);
	if (!check_int(s, v3))
		return (FALSE);
	return (TRUE);
}
