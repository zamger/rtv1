/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_calc_f1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 18:56:30 by akryvenk          #+#    #+#             */
/*   Updated: 2017/10/20 18:56:31 by akryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"


// double      coss;

//    light->dir = vector_normalize(&light->dir);
//     lambert = vector_dot(&light->dir, &rt->ray.normal);
//     (lambert < 0) ? lambert = 0 : 0;

// //   if (rt->shadow == 0)
//  //   {
//     rt->col0.red += lambert * rt->current_light.intensity.red * rt->col.red;
//     rt->col0.green += lambert * rt->current_light.intensity.green * rt->col.green;
//     rt->col0.blue += lambert * rt->current_light.intensity.blue * rt->col.blue;

//    coss = vector_coss(&rt->ray.normal, &light->dir);
//     (coss < 0) ? coss = 0 : 0;
//     rt->col0.red += ((1 - rt->col.red) * (0.8 * pow(coss, 25) + 0.1 * coss));
//     (rt->col0.red > 1) ? rt->col0.red = 1 : 0;
//     rt->col0.green += ((1 - rt->col.green) * (0.8 * pow(coss, 25) + 0.1 * coss));
//     (rt->col0.green > 1) ? rt->col0.green = 1 : 0;
//     rt->col0.blue += ((1 - rt->col.blue) * (0.8 * pow(coss, 25) + 0.1 * coss));
//     (rt->col0.blue > 1) ? rt->col0.blue = 1 : 0;


//    rt->lambert = lambert;
   
void		calc_lamb_shadow(t_base *b, t_fig *f)
{
	b->light_ray.start = b->new_start;
	b->light_ray.dir = vector_scale((1 / b->tt), &b->dist);
	if (b->shadow == 0)
		inter_sh_shadow(b, f);
	if (b->k < 100 && b->shadow == 0)
		inter_cyl_shadow(b, f);
	if (b->k < 100 && b->shadow == 0)
		inter_con_shadow(b, f);
	if (b->k < 100 && b->shadow == 0)
		inter_plane_shadow(b, f);
	if (b->shadow == 0)
	{
		b->lamb = vector_dot(&b->light_ray.dir, &b->n) * b->coef;
		b->col.r += b->lamb * b->light.intens.r * b->mat.diffuse.r;
		b->col.g += b->lamb * b->light.intens.g * b->mat.diffuse.g;
		b->col.b += b->lamb * b->light.intens.b * b->mat.diffuse.b;
	}
	else
	{
		b->col = init_color(0,0,0);
		b->lamb = vector_dot(&b->light_ray.dir, &b->n) * b->coef * 0.3;
		b->col.r += b->mat.diffuse.r * b->lamb;
		b->col.g += b->mat.diffuse.g * b->lamb;
		b->col.b += b->mat.diffuse.b * b->lamb;
	}
}

void		find_color_pix_1(t_base *b, t_fig *f)
{
	while (b->j < f->num_light)
	{
		b->light = f->l[b->j];
		b->dist = vector_sub(&b->light.pos, &b->new_start);
		if (vector_dot(&b->n, &b->dist) > 0)
		{
			b->tt = (vector_dot(&b->dist, &b->dist));
			b->tt = sqrt(b->tt);
			if (b->tt > 0.0)
				calc_lamb_shadow(b, f);
		}
		b->j++;
	}
}

void		find_color_pix(t_base *b, t_fig *f)
{
	b->shadow = 0;
	inter_sph_fig(b, f);
	inter_cyl_fig(b, f);
	inter_con_fig(b, f);
	inter_plane_fig(b, f);
	if (b->curr_fig != -1)
	{
		b->tem = vector_dot(&b->n, &b->n);
		if (b->tem != 0)
		{
			b->tem = 1.0 / (sqrtf(b->tem));
			b->n = vector_scale(b->tem, &b->n);
			b->j = 0;
			find_color_pix_1(b, f);
		}
		b->coef *= b->mat.refl;
		b->r.start = b->new_start;
		b->temm = vector_scale(2.0 * vector_dot(&b->r.dir, &b->n), &b->n);
		b->r.dir = vector_sub(&b->r.dir, &b->temm);
	}
}

void		calc_pix_arr(t_img *im, t_base *b, t_fig *f)
{
	b->y = -H_H;
	while (b->y < H_H)
	{
		b->x = -H_W;
		while (b->x < H_W)
		{
			init_base_in_arr(b);
			while ((b->level < b->level_max) && b->coef > 0.000001)
			{
				b->t = 2000000.0;
				b->curr_fig = -1;
				find_color_pix(b, f);
				b->level++;
			}
			put_pixl(im, b->x, b->y, b->col);
			b->x++;
		}
		b->y++;
	}
}
