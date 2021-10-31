/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_trace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyson <hyson@42student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 18:14:43 by hyson             #+#    #+#             */
/*   Updated: 2021/10/31 18:14:45 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	hit_sphere(t_sphere *sp, t_rec *rec, t_ray *r)
{
	t_vec3		oc;
	double		element[3];
	double		discriminant;
	double		root;

	oc = v_minus(r->orig, sp->p);
	element[0] = v_len2(r->dir);
	element[1] = v_dot(oc, r->dir);
	element[2] = v_len2(oc) - sp->r * sp->r;
	discriminant = element[1] * element[1] - element[0] * element[2];
	if (discriminant < 0)
		return (0);
	root = (-element[1] - sqrt(discriminant)) / element[0];
	if (root < rec->t_min || root >= rec->t_max)
	{
		root = (-element[1] + sqrt(discriminant)) / element[0];
		if (root < rec->t_min || root >= rec->t_max)
			return (0);
	}
	rec->t = root;
	rec->p = ray_at(r, root);
	rec->n = v_div(v_minus(rec->p, sp->p), sp->r);
	rec->albedo = sp->c;
	set_face_normal(r, rec);
	return (TRUE);
}

t_bool	hit_obj(t_rec *rec, t_ray *r, t_object *obj)
{
	int	hit_anything;

	hit_anything = 0;
	if (obj->type == SPHERE)
		hit_anything = hit_sphere((t_sphere *)obj->element, rec, r);
	else if (obj->type == PLANE)
		hit_anything = hit_plane((t_plane *)obj->element, rec, r);
	else if (obj->type == CYLINDER)
		hit_anything = hit_cylinder((t_cylinder *)obj->element, rec, r);
	return (hit_anything);
}

t_bool	hit(t_object *obj, t_ray *r, t_rec *rec)
{
	int		hit_anything;
	t_rec	tmp_rec;

	tmp_rec = *rec;
	hit_anything = 0;
	while (obj != NULL)
	{
		if (hit_obj(&tmp_rec, r, obj))
		{
			hit_anything = 1;
			tmp_rec.t_max = tmp_rec.t;
			*rec = tmp_rec;
		}
		obj = obj->next;
	}
	return (hit_anything);
}
