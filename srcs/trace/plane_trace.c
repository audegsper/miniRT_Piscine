#include "minirt.h"

int	hit_plane(t_plane *pl, t_rec *rec, t_ray *r)
{
	double	t;
	double	denominator;

	denominator = v_dot(r->dir, pl->n);
	if (denominator == 0)
		return (FALSE);
	t = v_dot(pl->n, v_minus(pl->p, r->orig)) / denominator;
	if (t <= rec->t_min || t > rec->t_max)
		return (FALSE);
	rec->t = t;
	rec->n = pl->n;
	rec->p = ray_at(r, rec->t);
	rec->albedo = pl->c;
	set_face_normal(r, rec);
	return (TRUE);
}
