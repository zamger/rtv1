/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 15:41:24 by akryvenk          #+#    #+#             */
/*   Updated: 2017/07/13 15:41:24 by akryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			ft_mouse_exit(void)
{
	exit(0);
}

void		ft_rot_grid(t_img *im, char ch, int n)
{
	if (ch == 'x')
		im->b.angle_a += (n * M_PI) / 180;
	else if (ch == 'y')
		im->b.angle_b += (n * M_PI) / 180;
	else if (ch == 'z')
		im->b.angle_g += (n * M_PI) / 180;
	im->flag = 1;
}

int			my_key_funct(int keycode, t_img *im)
{
	im->flag = 0;
	keycode == 53 ? exit(0) : 0;
	keycode == 13 ? ft_rot_grid(im, 'x', -10) : 0;
	keycode == 1 ? ft_rot_grid(im, 'x', 10) : 0;
	keycode == 0 ? ft_rot_grid(im, 'y', 10) : 0;
	keycode == 2 ? ft_rot_grid(im, 'y', -10) : 0;
	keycode == 12 ? ft_rot_grid(im, 'z', -10) : 0;
	keycode == 14 ? ft_rot_grid(im, 'z', 10) : 0;
	if (im->flag == 1)
		ft_draw(im);
	return (0);
}
