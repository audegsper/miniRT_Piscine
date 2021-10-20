#include "minirt.h"

t_color3		get_specular(t_ray *r, t_vec3 light_dir, t_light *light)
{
	t_color3	specular;
	t_vec3		view_dir;
	t_vec3		reflect_dir;
	double		spec;

	view_dir = v_unit(v_mul(-1, r->dir));
	reflect_dir = reflect(v_mul(-1, light_dir), g_rt.rec.n);
	spec = pow(fmax(v_dot(view_dir, reflect_dir), 0.0), KSN);
	specular = v_mul(spec, v_mul(KS, light->c));

	return (specular);
}

t_color3		get_diffuse(t_vec3	light_dir, t_light *light)
{
	double		kd; //diffuse strength
	t_color3	diffuse;

	kd = fmax(v_dot(g_rt.rec.n, light_dir), 0.0);
	diffuse = v_mul(kd, light->c);

	return (diffuse);
}

t_color3		get_phong(t_ray *r, t_vec3	light_dir, t_light * light)
{
	t_color3	rst;
	t_color3	specular;
	t_color3	diffuse;

	specular = get_specular(r, light_dir, light);
	diffuse = get_diffuse(light_dir, light);
	rst = v_plus(specular, diffuse);

	return (rst);
}

int			in_shadow(t_ray *light_r)
{
	t_rec	rec;

	rec.t_min = 0;
	rec.t_max = 1;

	if (hit(g_rt.object, light_r, &rec))
		return (1);
	return (0);
}

t_color3	phong_lighting(t_ray *r)
{
	t_color3	point_light;
	t_color3	light_color;
	t_object		*lights;

	light_color = color(0,0,0);
	lights = g_rt.light;
	while (lights)
	{
		point_light = get_point_light(lights->element, r);
		light_color = v_plus(light_color, point_light);
		lights = lights->next;
	}
	light_color = v_plus(light_color, g_rt.ambient);
	return (v_min(v_mul2(light_color, g_rt.rec.albedo), color(1, 1, 1)));
}
