#include "minirt.h"

void	color_pixel(t_vec3 color)
{
	int r;
	int g;
	int b;

	r = (int)(color.x * 255.999);
	g = (int)(color.y * 255.999);
	b = (int)(color.z * 255.999);
	g_rt.color = (r << 16 | g << 8 | b);
}

t_vec3			vec(double x, double y, double z)
{
	t_vec3	rst;

	rst.x = x;
	rst.y = y;
	rst.z = z;
	return (rst);
}

t_point3		point(double x, double y, double z)
{
	t_point3	rst;

	rst.x = x;
	rst.y = y;
	rst.z = z;
	return (rst);
}

t_color3		color(double r, double g, double b)
{
	t_color3	rst;

	rst.x = r;
	rst.y = g;
	rst.z = b;
	return (rst);
}
