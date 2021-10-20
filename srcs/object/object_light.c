#include "minirt.h"

void	set_light (/* t_object_condition *ob */)
{

	t_light	*light;
	//t_light	*tmp;

	light = (t_light *) malloc(sizeof(t_light));
	light->p = point(5,4,-1);
	light->bright_ratio = 0.6;
	light->c = color(255.0/255.0, 255.0/255.0, 255.0/255.0);

	add_object(&g_rt.light ,new_object(LIGHT, light));
/*
	if (g_rt.light == NULL)
	{
		g_rt.light = light;
		light->next = NULL;
		return;
	}
	tmp = g_rt.light;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next =light;
	tmp->next->next = NULL;
	*/
}
