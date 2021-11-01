/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_trace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 18:11:12 by hyson             #+#    #+#             */
/*   Updated: 2021/11/01 12:19:51 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	cylinder_get_discriminant(t_cylinder *cy, t_ray r, double *half_b,
									 double *a)
{
	double	discriminant;
	double	c;
	t_cyvar	var;

	var.r2 = cy->d * cy->d;
	var.top = v_minus(cy->p, v_mul(cy->h, cy->n));
	var.bot = v_plus(cy->p, v_mul(cy->h, cy->n));
	var.hc = v_minus(var.top, var.bot);
	var.h = v_unit(var.hc);
	var.w = v_minus(r.orig, var.bot);
	var.v = r.dir;
	*a = v_dot(var.v, var.v) - pow(v_dot(var.v, var.h), 2);
	*half_b = ((v_dot(var.v, var.w) - (v_dot(var.v, var.h) * \
					v_dot(var.w, var.h))));
	c = v_dot(var.w, var.w) - pow(v_dot(var.w, var.h), 2) - var.r2;
	discriminant = *half_b * *half_b - *a * c;
	return (discriminant);
}

t_bool	cylinder_root_check(t_cylinder *cy, t_rec *rec,
										double root, t_point3 p)
{
	double	h;
	double	hmin;
	double	hmax;

	if (cy->n.x != 0)
	{
		h = p.x;
		hmin = cy->p.x;
		hmax = cy->p_top.x;
	}
	else if (cy->n.y != 0)
	{
		h = p.y;
		hmin = cy->p.y;
		hmax = cy->p_top.y;
	}
	else
	{
		h = p.z;
		hmin = cy->p.z;
		hmax = cy->p_top.z;
	}
	if (root < rec->t_min || root > rec->t_max || h < hmin || h > hmax)
		return (FALSE);
	return (TRUE);
}

double	hit_finite_cylinder(t_cylinder *cy, t_ray *ray, t_rec *rec)
{
	double		a;
	double		half_b;
	double		d;
	double		t;
	t_point3	p;

	d = cylinder_get_discriminant(cy, *ray, &half_b, &a);
	if (d < 0)
		return (INFINITY);
	d = sqrt(d);
	t = (-half_b - d) / a;
	p = ray_at(ray, t);
	if (!cylinder_root_check(cy, rec, t, p))
	{
		t = (-half_b + d) / a;
		p = ray_at(ray, t);
		if (!cylinder_root_check(cy, rec, t, p))
			return (INFINITY);
	}
	return (t);
}

int	hit_cylinder(t_cylinder *cy, t_rec *rec, t_ray *r)
{
	double		t;
	t_point3	c0;

	t = hit_finite_cylinder(cy, r, rec);
	if (t == INFINITY)
		return (FALSE);
	rec->t = t;
	rec->p = ray_at(r, t);
	if (cy->n.x != 0)
		c0 = point(rec->p.x, cy->p.y, cy->p.z);
	if (cy->n.y != 0)
		c0 = point(cy->p.x, rec->p.y, cy->p.z);
	if (cy->n.z != 0)
		c0 = point(cy->p.x, cy->p.y, rec->p.z);
	rec->n = v_unit(v_minus(rec->p, c0));
	set_face_normal(r, rec);
	rec->albedo = cy->c;
	return (TRUE);
}
