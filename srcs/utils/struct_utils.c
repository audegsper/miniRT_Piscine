#include "minirt.h"

t_object	*new_object(int type, void *element)
{
	t_object	*obj;

	if (!(obj = (t_object *)malloc(sizeof(t_object))))
		return (0);
	obj->type = type;
	obj->element = element;
	obj->next = NULL;
	return (obj);
}

void			add_object(t_object **list, t_object *new)
{
	t_object	*tmp;

	if (*list == NULL)
	{
		*list = new;
		return ;
	}
	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
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
