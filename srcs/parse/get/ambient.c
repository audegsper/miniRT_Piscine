/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 21:59:59 by hyson             #+#    #+#             */
/*   Updated: 2021/10/31 01:06:12 by dohykim          ###   ########.fr       */
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
	// g_rt.ambient = color(ob->a->c.x / 255.0 * ob->a->s, \
	// 					ob->a->c.y / 255.0 * ob->a->s, \
	// 					ob->a->c.z / 255.0 * ob->a->s);
	g_rt.ambient = color(ob->a->c.x / 255.0 * ob->a->s, \
						ob->a->c.y / 255.0 * ob->a->s, \
						ob->a->c.z / 255.0 * ob->a->s);
	return (TRUE);
}
