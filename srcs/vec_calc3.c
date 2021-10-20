#include "minirt.h"

t_vec3			reflect(t_vec3 v, t_vec3 n)
{
	return (v_minus(v, v_mul(2 * v_dot(v, n), n)));
}

t_vec3			v_cross(t_vec3 u, t_vec3 v)
{
	t_vec3		target;

	target.x = u.y * v.z - u.z * v.y;
	target.y = u.z * v.x - u.x * v.z;
	target.z = u.x * v.y - u.y * v.x;
	return (target);
}

void	set_face_normal(t_ray *r, t_rec *rec)
{
	rec->front_face = v_dot(r->dir, rec->n) < 0;
	rec->n = rec->front_face ? rec->n : v_mul(-1, rec->n);
}
