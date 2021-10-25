#include "minirt.h"

int		hit_cylinder(t_cylinder *cy,t_rec *rec, t_ray *r)
{
	double		t;
	double		discriminant;
	double		a;
	double		b;
	t_point3	hit_point;
	t_point3	top_center;
	t_point3	bottom_center;
	t_point3	center;
	t_vec3		normal;
	t_vec3		w;
	t_vec3		v;
	t_vec3		oc;
	double		c;

	oc = v_minus(r->orig, cy->p);
	v = v_cross(r->dir, cy->n);
	w = v_cross(oc, cy->n);
	a = v_dot(v, v);
	b = v_dot(v, w);
	c = v_dot(w, w) - pow(cy->d / 2, 2);
	discriminant = b * b - a * c;

	if (discriminant < 0)
	{
		t = INFINITY;
		return (0);
	}
	t = (-b - sqrt(discriminant)) / a;
	hit_point = ray_at(r, t);

	top_center = v_plus(cy->p, v_mul(cy->h / 2, cy->n));
	bottom_center = v_minus(cy->p, v_mul(cy->h / 2, cy->n));
	if (v_dot(cy->n, v_minus(hit_point, top_center)) > 0)
		return (FALSE);
	if (v_dot(cy->n, v_minus(hit_point, bottom_center)) < 0)
		return (FALSE);
	if (t <= rec->t_min || t > rec->t_max)
		return (FALSE);
	rec->t = t;
	rec->p = ray_at(r, rec->t);
	center = v_mul(v_dot(v_minus(rec->p, cy->p), cy->n)
					, cy->n);
	center = v_plus(cy->p, center);
	normal = v_unit(v_minus(rec->p, center));
	rec->n = normal;
	rec->albedo = cy->c;
	set_face_normal(r, rec);
	return (TRUE);
}
