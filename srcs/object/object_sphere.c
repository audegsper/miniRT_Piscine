#include "minirt.h"

int		hit_sphere(t_sphere *sp,t_rec *rec, t_ray *r)
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

void	set_sphere (/* t_object_condition *ob */)
{
	t_sphere	*sphere;
	//t_sphere	*tmp;

	sphere = (t_sphere *) malloc(sizeof(t_sphere));
	sphere->p = point(0,0,0);
	sphere->r = 3.0 / 2.0;
	sphere->c = color(255 / 255.0, 0 / 255.0, 0 / 255.0);

	add_object(&g_rt.object,new_object(SPHERE, sphere));
/*
	if (g_rt.sphere == NULL)
	{
		g_rt.sphere = sphere;
		sphere->next = NULL;
		return;
	}
	tmp = g_rt.sphere;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next =sphere;
	tmp->next->next = NULL;
	*/
}
