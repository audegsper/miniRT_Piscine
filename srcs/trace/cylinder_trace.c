#include "minirt.h"

double		cylinder_get_discriminant(t_cylinder *cy, t_ray r,
											double *half_b, double *a)
{
	double	c;

	r = new_ray(v_minus(r.orig, cy->p), r.dir);
	if (cy->n.x != 0)
	{
		*a = r.dir.y * r.dir.y + r.dir.z * r.dir.z;
		*half_b = r.orig.y * r.dir.y + r.orig.z * r.dir.z;
		c = r.orig.y * r.orig.y + r.orig.z * r.orig.z - cy->r2;
	}
	else if (cy->n.y != 0)
	{
		*a = r.dir.x * r.dir.x + r.dir.z * r.dir.z;
		*half_b = r.orig.x * r.dir.x + r.orig.z * r.dir.z;
		c = r.orig.x * r.orig.x + r.orig.z * r.orig.z - cy->r2;
	}
	else
	{
		*a = r.dir.x * r.dir.x + r.dir.y * r.dir.y;
		*half_b = r.orig.x * r.dir.x + r.orig.y * r.dir.y;
		c = r.orig.x * r.orig.x + r.orig.y * r.orig.y - cy->r2;
	}
	return (*half_b * *half_b - *a * c);
}

t_bool		cylinder_root_check(t_cylinder *cy, t_rec *rec,
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

double			hit_finite_cylinder(t_cylinder *cy, t_ray *ray, t_rec *rec)
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

int		hit_cylinder(t_cylinder *cy,t_rec *rec, t_ray *r)
{
	double	t;
	t_point3 c0;

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
