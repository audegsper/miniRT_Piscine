/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohykim <dohykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:00:08 by hyson             #+#    #+#             */
/*   Updated: 2021/10/24 21:08:38 by dohykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_camera(void)
{
	double	ratio;
	double	theta;
	t_vec3	vup;
	double h;

	vup = vec(0.0, 1.0, 0.0);
	ratio = (double)g_rt.width / g_rt.height;
	theta = g_rt.cam.fov * M_PI / 180.0;
	h = tan(theta / 2.0);
	g_rt.cam.viewport_h = 2 * h;
	g_rt.cam.viewport_w = ratio * g_rt.cam.viewport_h;
	g_rt.cam.w = v_unit(v_mul(-1, g_rt.cam.n));
	g_rt.cam.u = v_unit(v_cross(vup, g_rt.cam.w));
	g_rt.cam.v = v_cross(g_rt.cam.w, g_rt.cam.u);
	g_rt.cam.horizontal = v_mul(g_rt.cam.viewport_w, g_rt.cam.u);
	g_rt.cam.vertical = v_mul(g_rt.cam.viewport_h, g_rt.cam.v);
	g_rt.cam.llc = v_minus(v_minus(
					v_minus(g_rt.cam.p, v_div(g_rt.cam.horizontal,2))
					, v_div(g_rt.cam.vertical, 2)), g_rt.cam.w);
}

static	t_bool	valid_c(t_camera *c)
{
	t_bool	ret;

	ret = TRUE;
	if (!valid_vec3(c->n))
		ret = FALSE;
	if (c->fov < 0.0 || c->fov > 180.0)
		ret = FALSE;
	if (!ret)
		write(STDERR_FILENO, "Invalid camera value\n", 21);
	return (ret);
}

static	t_bool	parse_c(t_object_condition *ob, char *line)
{
	t_bool ret;

	ret = TRUE;
	if (!check_double2(&line, &(ob->c->p.x), &(ob->c->p.y), &(ob->c->p.z)))
		ret = FALSE;
	if (!check_double2(&line, &(ob->c->n.x), &(ob->c->n.y), &(ob->c->n.z)))
		ret = FALSE;
	if (!check_double(&line, &(ob->c->fov)))
		ret = FALSE;
	if (!is_endl(line))
		ret = FALSE;
	if (!ret)
		write(STDERR_FILENO, "Wrong camera condition\n", 23);
	return (ret);
}

t_bool	get_camera(t_object_condition *ob, char *line)
{
	if (!parse_c(ob, line) || !valid_c(ob->c))
		return (FALSE);
	return (TRUE);
}
