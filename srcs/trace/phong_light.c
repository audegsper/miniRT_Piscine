#include "minirt.h"

t_color3	get_diffuse(t_vec3	light_dir, t_light *light, t_rec *rec)
{
	double		kd;
	t_color3	diffuse;

	kd = fmax(v_dot(rec->n, light_dir), 0.0);
	diffuse = v_mul(kd, light->c);
	return (diffuse);
}

t_color3	get_phong(t_vec3 light_dir, t_light *light, t_rec *rec)
{
	t_color3	rst;
	t_color3	diffuse;

	diffuse = get_diffuse(light_dir, light, rec);
	rst = diffuse;
	return (rst);
}

t_color3	get_point_light(t_light *light, t_rec *rec)
{
	t_vec3		light_dir;
	double		brightness;
	double		light_len;
	t_ray		light_ray;
	t_color3	phong;

	light_dir = v_minus(light->p, rec->p);
	light_ray = new_ray(v_plus(rec->p, v_mul(EPSILON, rec->n)), light_dir);
	if (in_shadow(&light_ray))
		return (color(0, 0, 0));
	brightness = light->bright_ratio * LUMEN;
	light_dir = v_unit(light_dir);
	phong = get_phong(light_dir, light, rec);
	return (v_mul(brightness, phong));
}

t_color3	phong_lighting(t_rec *rec)
{
	t_color3		point_light;
	t_color3		light_color;
	t_object		*lights;

	light_color = color(0, 0, 0);
	lights = g_rt.light;
	while (lights)
	{
		point_light = get_point_light(lights->element, rec);
		light_color = v_plus(light_color, point_light);
		lights = lights->next;
	}
	light_color = v_plus(light_color, g_rt.ambient);
	return (v_min(v_mul2(light_color, rec->albedo), color(1, 1, 1)));
}
