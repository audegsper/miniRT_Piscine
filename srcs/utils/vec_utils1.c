#include "minirt.h"

t_point3	v_plus(t_point3 v1, t_point3 v2)
{
	t_point3	rst;

	rst.x = v1.x + v2.x;
	rst.y = v1.y + v2.y;
	rst.z = v1.z + v2.z;
	return (rst);
}

t_point3	v_minus(t_point3 v1, t_point3 v2)
{
	t_point3	rst;

	rst.x = v1.x - v2.x;
	rst.y = v1.y - v2.y;
	rst.z = v1.z - v2.z;
	return (rst);
}

t_point3	v_mul(double t, t_point3 v)
{
	t_point3	rst;

	rst.x = t * v.x;
	rst.y = t * v.y;
	rst.z = t * v.z;
	return (rst);
}

t_point3	v_mul2(t_point3 v1, t_point3 v2)
{
	t_point3	rst;

	rst.x = v1.x * v2.x;
	rst.y = v1.y * v2.y;
	rst.z = v1.z * v2.z;
	return (rst);
}

t_point3	v_div(t_point3 v, double t)
{
	t_point3	rst;

	rst.x = v.x / t;
	rst.y = v.y / t;
	rst.z = v.z / t;
	return (rst);
}
