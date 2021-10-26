/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:00:14 by hyson             #+#    #+#             */
/*   Updated: 2021/10/26 16:21:28 by dohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_light (t_object_condition *ob)
{

	t_light	*light;

	light = (t_light *) malloc(sizeof(t_light));
	light->p = point(ob->l->p.x,ob->l->p.y,ob->l->p.z);
	light->bright_ratio = ob->l->bright_ratio;
	light->c = color(255.0/255.0, 255.0/255.0, 255.0/255.0);

	add_object(&g_rt.light ,new_object(LIGHT, light));
}

static	t_bool	valid_l(t_light *l)
{
	t_bool	ret;

	ret = TRUE;
	if (l->bright_ratio < 0.0 || l->bright_ratio > 1.0)
		ret = FALSE;
	if (!valid_color(l->c))
		ret = FALSE;
	if (!ret)
		write(STDERR_FILENO, "Invalid light value\n", 20);
	return (ret);
}

static	t_bool	parse_l(t_object_condition *ob, char *line)
{
	t_bool ret;

	ret = TRUE;
	if (!check_double2(&line, &(ob->l->p.x), &(ob->l->p.y), &(ob->l->p.z)))
		ret = FALSE;
	if (!check_double(&line, &(ob->l->bright_ratio)))
		ret = FALSE;
	if (!check_int2(&line, &(ob->l->c.x), &(ob->l->c.y), &(ob->l->c.z)))
		ret = FALSE;
	if (!is_endl(line))
		ret = FALSE;
	if (!ret)
		write(STDERR_FILENO, "Wrong light condition\n", 22);
	return (ret);
}

t_bool	get_light(t_object_condition *ob, char *line)
{
	if (!parse_l(ob, line) || !valid_l(ob->l))
		return (FALSE);
	return (TRUE);
}
