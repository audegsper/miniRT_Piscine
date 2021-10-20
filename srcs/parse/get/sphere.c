/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:00:18 by hyson             #+#    #+#             */
/*   Updated: 2021/10/16 22:58:110 by dohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static	t_bool	valid_sp(t_sphere *sp)
{
	t_bool	ret;

	ret = TRUE;
	if (sp->r <= 0.0)
		ret = FALSE;
	if (!valid_color(sp->c))
		ret = FALSE;
	if (!ret)
		write(STDERR_FILENO, "Invalid sphere value\n", 29);
	return (ret);
}

static t_bool	parse_sp(t_object_condition *ob, char *line)
{
	t_bool ret;

	ret = TRUE;

	if (!check_double2(&line, &(ob->sp->p.x), &(ob->sp->p.y), &(ob->sp->p.z)))
		ret = FALSE;
	if (!check_double(&line, &(ob->sp->r)))
		ret = FALSE;
	if (!check_int2(&line, &(ob->sp->c.x), &(ob->sp->c.y), &(ob->sp->c.z))) //색깔 판단
		ret = FALSE;
	if (!is_endl(line)) // 엔터 판단
		ret = FALSE;
	if (!ret)
		write(STDERR_FILENO, "Wrong sphere condition\n", 29);
	return (ret);
}

t_bool		get_sphere(t_object_condition *ob, char *line)
{
	if (!parse_sp(ob, line) || !valid_sp(ob->sp))
		return (FALSE);
	return (TRUE);
}
