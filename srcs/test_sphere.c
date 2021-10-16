#include "minirt.h"

t_sphere    *init_sphere(t_point3 *center, double radius)
{
    t_sphere    *result;

    result = (t_sphere *)malloc(sizeof(t_sphere));
    result->p = *center;
    result->r = radius;
    return (result);
}

void sphere_here(t_rt *rt)
{
	rt->s = init_sphere(vec_create(0, 0, -1), 0.5);
    // init_sphere(t_point3}, {double}});

}
