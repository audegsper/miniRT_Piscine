/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:00:16 by hyson             #+#    #+#             */
/*   Updated: 2021/10/27 09:47:49 by dohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_plane(t_object_condition *ob)
{
	t_plane	*plane;

	plane = malloc(sizeof(t_plane));

	plane->p = ob->pl->p;
	plane->n = v_unit(ob->pl->n);
	plane->c = color(ob->pl->c.x / 255.0,
					ob->pl->c.y / 255.0,
					ob->pl->c.z / 255.0);
	add_object(&g_rt.object,new_object(PLANE, plane));
}

static	t_bool	valid_pl(t_plane *pl)
{
	t_bool	ret;

	ret = TRUE;
	if (!valid_vec3(pl->n))
		ret = FALSE;
	if (!valid_color(pl->c))
		ret = FALSE;
	if (!ret)
		write(STDERR_FILENO, "Invalid plane value\n", 20);
	return (ret);
}

static	t_bool	parse_pl(t_object_condition *ob, char *line)
{
	t_bool	ret;

	ret = TRUE;
	if (!check_double2(&line, &(ob->pl->p.x), &(ob->pl->p.y), &(ob->pl->p.z)))
		ret = FALSE;
	if (!check_double2(&line, &(ob->pl->n.x), &(ob->pl->n.y), &(ob->pl->n.z)))
		ret = FALSE;
	if (!check_int2(&line, &(ob->pl->c.x), &(ob->pl->c.y), &(ob->pl->c.z)))
		ret = FALSE;
	if (!is_endl(line))
		ret = FALSE;
	if (!ret)
		write(STDERR_FILENO, "Wrong plane condition\n", 22);
	return (ret);
}

t_bool	get_plane(t_object_condition *ob, char *line)
{
	if (!parse_pl(ob, line) || !valid_pl(ob->pl))
		return (FALSE);
	return (TRUE);
}
