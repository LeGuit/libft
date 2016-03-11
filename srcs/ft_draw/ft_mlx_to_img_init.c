#include "ft_draw.h"

int				ft_mlx_img_init(void *mlx_ptr, t_image *image, int width,
				int height)
{
	image->ptr = mlx_new_image(mlx_ptr, width, height);
	image->data = mlx_get_data_addr(image->ptr, &image->bpp, &image->size_line,
									&image->endian);
	image->width = width;
	image->height = height;
	return (0);
}
