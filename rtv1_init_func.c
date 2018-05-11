/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_init_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 15:58:47 by akryvenk          #+#    #+#             */
/*   Updated: 2017/10/22 15:58:48 by akryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>

t_vec		pix_x_y(t_base *b, t_vec vec)
{
	t_vec	p;
	t_rot	rot;

	rot.cy_cz = cosf(b->angle_b) * cosf(b->angle_g);
	rot.sy_sx = sinf(b->angle_b) * sinf(b->angle_a);
	rot.cy_sz_cx = cosf(b->angle_b) * sinf(b->angle_g) * cosf(b->angle_a);
	rot.sum1 = rot.sy_sx - rot.cy_sz_cx;
	rot.cy_sz_sx = cosf(b->angle_a) * sinf(b->angle_g) * sinf(b->angle_a);
	rot.sy_cx = sinf(b->angle_b) * cosf(b->angle_a);
	rot.sum2 = rot.cy_sz_sx + rot.sy_cx;
	rot.sz = sinf(b->angle_g);
	rot.cz_cx = cosf(b->angle_g) * cosf(b->angle_a);
	rot.cz_sx = -cosf(b->angle_g) * sinf(b->angle_a);
	rot.sy_cz = -sinf(b->angle_b) * cosf(b->angle_g);
	rot.sy_sz_cx = sinf(b->angle_b) * sinf(b->angle_g) * cosf(b->angle_a);
	rot.cy_cx = cosf(b->angle_b) * cosf(b->angle_a);
	rot.sx_cy = sinf(b->angle_a) * cosf(b->angle_b);
	rot.sum3 = rot.sy_sz_cx + rot.sx_cy;
	rot.sx_sy_sz = sinf(b->angle_a) * sinf(b->angle_b) * sinf(b->angle_g);
	rot.sum4 = rot.cy_cx - rot.sx_sy_sz;
	p.x = vec.x * rot.cy_cz + vec.y * rot.sum1 + vec.z * rot.sum2;
	p.y = vec.x * rot.sz + vec.y * rot.cz_cx + vec.z * rot.cz_sx;
	p.z = vec.x * rot.sy_cz + vec.y * rot.sum3 + vec.z * rot.sum4;
	return (p);
}

void		init_base_in_arr(t_base *b)
{
	b->level = 0;
	b->level_max = 1;
	b->coef = 1;
	b->r.start.x = 0;
	b->r.start.y = 0;
	b->r.start.z = b->z_zoom;
	b->r.start = pix_x_y(b, b->r.start);
	b->r.dir.x = b->x * b->tan_x;
	b->r.dir.y = b->y * b->tan_y;
	b->r.dir.z = 0;
	b->r.dir = pix_x_y(b, b->r.dir);
	b->r.dir = vector_sub(&b->r.dir, &b->r.start);
	b->r.dir = vector_norm(&b->r.dir);
	b->col = init_color(0, 0, 0);
}

void		init_spot_light(t_light *light)
{
	light[0].pos.x = H_W - H_W;
	light[0].pos.y = H_H - H_H;
	light[0].pos.z = -300;
	light[0].intens.r = 0;
	light[0].intens.g = 0;
	light[0].intens.b = 1;
	light[1].pos.x = 200 - H_W;
	light[1].pos.y = 200 - H_H;
	light[1].pos.z = -200;
	light[1].intens.r = 0;
	light[1].intens.g = 1;
	light[1].intens.b = 0;
	light[2].pos.x = 200 - H_W;
	light[2].pos.y = 200 - H_H;
	light[2].pos.z = -200;
	light[2].intens.r = 1;
	light[2].intens.g = 0;
	light[2].intens.b = 0;
}
