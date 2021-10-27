#include "minirt.h"

int	color_pixel(t_vec3 color)
{
	int	r;
	int	g;
	int	b;
	int	rst;

	r = (int)(color.x * 255.999);
	g = (int)(color.y * 255.999);
	b = (int)(color.z * 255.999);
	rst = (r << 16 | g << 8 | b);
	return (rst);
}

t_vec3	reflect(t_vec3 v, t_vec3 n)
{
	return (v_minus(v, v_mul(2 * v_dot(v, n), n)));
}

t_vec3	v_cross(t_vec3 u, t_vec3 v)
{
	t_vec3	target;

	target.x = u.y * v.z - u.z * v.y;
	target.y = u.z * v.x - u.x * v.z;
	target.z = u.x * v.y - u.y * v.x;
	return (target);
}

void	set_face_normal(t_ray *r, t_rec *rec)
{
	rec->front_face = v_dot(r->dir, rec->n) < 0;
	if (rec->front_face == TRUE)
		rec->n = rec->n;
	else
		rec->n = v_mul(-1, rec->n);
}
