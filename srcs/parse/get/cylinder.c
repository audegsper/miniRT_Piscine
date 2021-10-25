/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:00:10 by hyson             #+#    #+#             */
/*   Updated: 2021/10/25 21:26:21 by dohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// void	set_sylinder(/* t_object_condition *ob */)
// {
// 	t_cylinder	*cylinder;

// 	cylinder = malloc(sizeof(t_cylinder));
// 	cylinder->p = point(50.0, 0.0, 20.6);
// 	cylinder->n = v_unit(vec(0.0, 0.0, 1.0));
// 	cylinder->c = color(10, 0, 255);
// 	cylinder->d = 14.2;
// 	cylinder->h = 21.42;
// 	add_object(&g_rt.object,new_object(, sylinder));
// }

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
	return (TRUE);
}
