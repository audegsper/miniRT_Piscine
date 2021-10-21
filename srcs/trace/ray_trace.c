#include "minirt.h"

t_bool			in_shadow(t_ray *light_r)
{
	t_rec	rec;

	rec.t_min = 0;
	rec.t_max = 1;

	if (hit(g_rt.object, light_r, &rec))
		return (1);
	return (0);
}

t_point3		ray_at(t_ray *ray, double t)
{
	t_point3	at;

	at = v_plus(ray->orig, v_mul(t, ray->dir));
	return (at);
}

t_ray			new_ray(t_vec3 origin, t_vec3 direction)
{
	t_ray		ray;

	ray.orig = origin;
	ray.dir = direction;
	return (ray);
}

t_vec3			get_ray(double j, double i, t_camera cam)
{
	t_vec3		ray;
	double		u;
	double		v;

	u = (double)i / (g_rt.width - 1);
	v = (double)j / (g_rt.height - 1);
	ray = v_plus(
		v_plus(v_mul(u, cam.horizontal),
		v_minus(v_mul(v, cam.vertical),cam.p)),cam.llc);
	return (ray);
}

t_color3		trace_ray(int height, int width)
{
	t_vec3 dir;
	t_color3 color_tmp;
	t_rec	rec;
	t_ray	ray;

	color_tmp = color(0, 0, 0);
	dir = get_ray(height,width, g_rt.cam);
	ray = new_ray(g_rt.cam.p, dir);

	rec.t_min = EPSILON;
	rec.t_max = INFINITY;

	if (hit(g_rt.object, &ray, &rec))
		color_tmp = phong_lighting(&ray, &rec);
	// else
	// {
	// 	t_vec3 unit = v_unit(ray.dir);
	// 	double t = 0.5 * (unit.y + 1.0);
	// 	color_tmp = (v_plus(v_mul(1.0 - t, vec(1, 1, 1))
	// 			, v_mul(t, vec(0.5, 0.7, 1.0))));
	// }
	return	(color_tmp);
}
