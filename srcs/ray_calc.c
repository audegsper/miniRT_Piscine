#include "minirt.h"

t_color3		get_point_light(t_light *light, t_ray *r)
{
	t_vec3	light_dir;
	double	brightness;
	double	light_len;
	t_ray	light_ray;
	t_color3	phong;

	light_dir = v_minus(light->p, g_rt.rec.p);
	light_len = v_len(light_dir);
	light_ray = new_ray(v_plus(g_rt.rec.p, v_mul(EPSILON, g_rt.rec.n)), light_dir);
	if (in_shadow(&light_ray))
		return (color(0, 0, 0));
	brightness = light->bright_ratio * LUMEN;
	light_dir = v_unit(light_dir);
	phong = get_phong(r,light_dir, light);
	return (v_mul(brightness,phong));
}

t_point3		ray_at(t_ray *ray, double t)
{
	t_point3	at;

	at = v_plus(ray->orig, v_mul(t, ray->dir));
	return (at);
}

t_ray		new_ray(t_vec3 origin, t_vec3 direction)
{
	t_ray		ray;

	ray.orig = origin;
	ray.dir = direction;
	return (ray);
}

t_vec3	get_ray(double j, double i, t_camera cam)
{
	t_vec3		ray;
	double		u;
	double		v;

	u = (double)i / (g_rt.width - 1);
	v = (g_rt.height - (double)j) / (g_rt.height - 1);
	//v = (double)j / (g_rt.height - 1);
	ray = v_plus(
		v_plus(v_mul(u, cam.horizontal),
		v_minus(v_mul(v, cam.vertical),cam.p)),cam.llc);
	return (ray);
}

