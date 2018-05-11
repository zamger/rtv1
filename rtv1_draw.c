/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 15:45:45 by akryvenk          #+#    #+#             */
/*   Updated: 2017/07/13 15:45:46 by akryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		make_image(t_img *im)
{
	int		bits_per_pixel;
	int		size_line;
	int		endian;

	im->image = mlx_new_image(im->mlx, W, H);
	im->p = mlx_get_data_addr(im->image, &bits_per_pixel,
		&size_line, &endian);
}

void		put_pixl(t_img *im, int x, int y, t_color col)
{
	im->p[(int)((x + H_W) * 4) + (int)((y + H_H) * W * 4) + 2] =
		(unsigned char)fmin(col.r * 255.0f, 255.0f);
	im->p[(int)((x + H_W) * 4) + (int)((y + H_H) * W * 4) + 1] =
		(unsigned char)fmin(col.g * 255.0f, 255.0f);
	im->p[(int)((x + H_W) * 4) + (int)((y + H_H) * W * 4)] =
		(unsigned char)fmin(col.b * 255.0f, 255.0f);
}

int			ft_draw(t_img *im)
{
	make_image(im);

	ft_return_tan(&im->b);
	calc_func(im, &im->b);
	mlx_put_image_to_window(im->mlx, im->win, im->image, 0, 0);
	mlx_destroy_image(im->mlx, im->image);
	return (1);
}
