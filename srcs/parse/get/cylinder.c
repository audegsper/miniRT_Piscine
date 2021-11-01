/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:00:10 by hyson             #+#    #+#             */
/*   Updated: 2021/11/01 11:55:24 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_sylinder(t_object_condition *ob)
{
	t_cylinder	*cylinder;
	t_point3	bottom_tmp;

	cylinder = malloc(sizeof(t_cylinder));
	cylinder->n = vec(ob->cy->n.x, ob->cy->n.y, ob->cy->n.z);
	cylinder->d = ob->cy->d;
	cylinder->r = ob->cy->d / 2.0;
	cylinder->r2 = cylinder->r * cylinder->r;
	cylinder->h = ob->cy->h;
	cylinder->c = color(ob->cy->c.x / 255.0, ob->cy->c.y / 255.0, \
						ob->cy->c.z / 255.0);
	cylinder->p = point(ob->cy->p.x, ob->cy->p.y, ob->cy->p.z);
	cylinder->p_top = v_plus(cylinder->p, v_mul(cylinder->h, cylinder->n));
	if (cylinder->n.x < 0 || cylinder->n.y < 0 || cylinder->n.z < 0)
	{
		bottom_tmp = cylinder->p;
		cylinder->p = cylinder->p_top;
		cylinder->p_top = bottom_tmp;
	}
	add_object(&g_rt.object, new_object(CYLINDER, cylinder));
}

static	t_bool	valid_cy(t_cylinder *cy)
{
	t_bool	ret;

	ret = TRUE;
	if (!valid_vec3(cy->n))
		ret = FALSE;
	if (cy->d <= 0.0)
		ret = FALSE;
	if (cy->h <= 0.0)
		ret = FALSE;
	if (!valid_color(cy->c))
		ret = FALSE;
	if (!ret)
		write(STDERR_FILENO, "Invalid cylinder value\n", 23);
	return (ret);
}

static	t_bool	parse_cy(t_object_condition *ob, char *line)
{
	t_bool	ret;

	ret = TRUE;
	if (!check_double2(&line, &(ob->cy->p.x), &(ob->cy->p.y), &(ob->cy->p.z)))
		ret = FALSE;
	if (!check_double2(&line, &(ob->cy->n.x), &(ob->cy->n.y), &(ob->cy->n.z)))
		ret = FALSE;
	if (!check_double(&line, &(ob->cy->d)))
		ret = FALSE;
	if (!check_double(&line, &(ob->cy->h)))
		ret = FALSE;
	if (!check_int2(&line, &(ob->cy->c.x), &(ob->cy->c.y), &(ob->cy->c.z)))
		ret = FALSE;
	if (!ret)
		write(STDERR_FILENO, "Wrong cylinder condition\n", 25);
	return (ret);
}

t_bool	get_cylinder(t_object_condition *ob, char *line)
{
	if (!parse_cy(ob, line) || !valid_cy(ob->cy))
		return (FALSE);
	set_sylinder(ob);
	return (TRUE);
}
