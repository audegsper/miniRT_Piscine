# include "minirt.h"

t_bool		hit_obj(t_rec *rec, t_ray *r, t_object *obj)
{
	int	hit_anything;
	hit_anything = 0;

	if (obj->type == SPHERE)
		hit_anything = hit_sphere((t_sphere *)obj->element, rec, r);
	return (hit_anything);
}

t_bool		hit(t_object *obj, t_ray *r, t_rec *rec) // 오류발생시 받을 인자 변경할것. 전역이 아닌 지역변수로
{
	int		hit_anything;
	t_rec	tmp_rec;

	tmp_rec = *rec;
	hit_anything = 0;
	while (obj != NULL)
	{
		if (hit_obj(&tmp_rec, r, obj))
		{
			hit_anything = 1;
			tmp_rec.t_max = tmp_rec.t;
			*rec = tmp_rec;
		}
		obj = obj->next; //오류발생 유력지역
	}
	return (hit_anything);
}
