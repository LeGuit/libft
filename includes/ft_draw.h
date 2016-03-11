#ifndef _FT_DRAW_H
# define _FT_DRAW_H

void				ft_put_pix_to_img(t_vec3i *v, t_image *i);
int					ft_mlx_image_init(void *mlx_ptr, t_image *image, int width,
					int height);
#endif