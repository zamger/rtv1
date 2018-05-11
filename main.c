/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:11:23 by akryvenk          #+#    #+#             */
/*   Updated: 2017/05/15 16:11:24 by akryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		calc_func(t_img *im, t_base *b)
{
	t_fig		f;

	init_spot_light(f.l);
	init_sphere(f.s);
	init_cylindr_inf(f.c);
	init_con_inf(f.con);
	init_plane(f.p);
	if (ft_strequ(im->scen, "1"))
	{
		f.num_sph = 1;
		f.num_light = 1;
		f.num_cyl = 0;
		f.num_con = 0;
		f.num_plane = 0;
	}
	else if (ft_strequ(im->scen, "2"))
	{
		f.num_sph = 2;
		f.num_light = 3;
		f.num_cyl = 1;
		f.num_con = 1;
		f.num_plane = 1;
	}
	else
		ft_error(2);
	calc_pix_arr(im, b, &f);
}

int			main(int argc, char **argv)
{
	t_img	im;

	if (argc != 2)
		ft_error(1);
	im.b.angle_a = 0;
	im.b.angle_b = 0;
	im.b.angle_g = 0;
	im.b.z_zoom = -10000;
	im.mlx = mlx_init();
	im.win = mlx_new_window(im.mlx, W, H, "RTv1");
	im.scen = argv[1];
	ft_draw(&im);
	mlx_hook(im.win, 2, 0, &my_key_funct, &im);
	mlx_hook(im.win, 17, 0, ft_mouse_exit, 0);
	mlx_loop(im.mlx);
	return (0);
}
