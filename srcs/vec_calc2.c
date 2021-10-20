#include "minirt.h"

t_vec3			v_unit(t_vec3 v)
{
	t_vec3		unit;
	double		len;

	len = v_len(v);
	unit.x = v.x / len;
	unit.y = v.y / len;
	unit.z = v.z / len;
	return (unit);
}

double			v_len(t_vec3 v)
{
	double		len;

	len = sqrt(v_len2(v));
	return (len);
}

double			v_len2(t_vec3 v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

t_point3		v_min(t_vec3 v, t_vec3 l)
{
	if (v.x > l.x)
		v.x = l.x;
	if (v.y > l.y)
		v.y = l.y;
	if (v.z > l.z)
		v.z = l.z;
	return (v);
}

double			v_dot(t_vec3 v1, t_vec3 v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}
