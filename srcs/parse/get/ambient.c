/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 21:59:59 by hyson             #+#    #+#             */
/*   Updated: 2021/10/24 17:54:35 by dohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static	t_bool	valid_a(t_ambient *a)
{
	t_bool	ret;

	ret = TRUE;
	if (a->s < 0.0 || a->s > 1.0)
		ret = FALSE;
	if (!valid_color(a->c))
		ret = FALSE;
	if (!ret)
		write(STDERR_FILENO, "Invalid ambient value\n", 22);
	return (ret);
}

static	t_bool	parse_a(t_object_condition *ob, char *line)
{
	t_bool		ret;

	ret = TRUE;
	if (!check_double(&line, &(ob->a->s)))
		ret = FALSE;
	if (!check_int2(&line, &(ob->a->c.x), &(ob->a->c.y), &(ob->a->c.z)))
		ret = FALSE;
	if (!is_endl(line))
		ret = FALSE;
	if (!ret)
	{
		write(STDERR_FILENO, "Wrong ambient condition\n", 24);
		ret = FALSE;
	}
	return (ret);
}

t_bool	get_ambient(t_object_condition *ob, char *line)
{
	if (!parse_a(ob, line) || !valid_a(ob->a))
		return (FALSE);
	//a 옵션들 확인해주는 모듈필요
	return (TRUE);
}
