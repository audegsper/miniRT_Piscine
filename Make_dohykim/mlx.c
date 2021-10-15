# include "minirt.h"

int mlx_show()
{
    void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "mlx_project");
	mlx_loop(mlx);

    return (0);
}