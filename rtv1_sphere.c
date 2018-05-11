/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 16:20:36 by akryvenk          #+#    #+#             */
/*   Updated: 2017/07/13 16:20:44 by akryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		norm_sph(t_base *b, t_sphere *s)
{
	b->scale = vector_scale(b->t, &b->r.dir);
	b->new_start = vector_add(&b->r.start, &b->scale);
	b->n = vector_sub(&b->new_start, &s->pos);
}

int			intersect_ray_sph(t_ray *r, t_sphere *sph, double *t)
{
	double	b;
	double	discr;
	double	t0;
	double	t1;
	t_vec	dist;

	dist = vector_sub(&r->start, &sph->pos);
	b = 2 * vector_dot(&r->dir, &dist);
	discr = b * b - (4 * vector_dot(&r->dir, &r->dir) *
		(vector_dot(&dist, &dist) - (sph->rad * sph->rad)));
	if (discr < 0)
		return (0);
	discr = sqrtf(discr);
	t0 = (-b + discr) / 2;
	t1 = (-b - discr) / 2;
	t0 > t1 ? t0 = t1 : 0;
	if ((t0 > 0.00001) && (t0 < *t))
	{
		*t = t0;
		return (1);
	}
	return (0);
}

void		init_sphere(t_sphere *spheres)
{
	spheres[0].pos.x = 500 - H_W;
	spheres[0].pos.y = 450 - H_H;
	spheres[0].pos.z = 100;
	spheres[0].rad = 100;
	spheres[0].mat.diffuse.r = 1;
	spheres[0].mat.diffuse.g = 1;
	spheres[0].mat.diffuse.b = 1;
	spheres[0].mat.refl = 0;
	spheres[1].pos.x = H_W + 100 - H_W;
	spheres[1].pos.y = H_H - H_H;
	spheres[1].pos.z = 0;
	spheres[1].rad = 100;
	spheres[1].mat.diffuse.r = 0;
	spheres[1].mat.diffuse.g = 1;
	spheres[1].mat.diffuse.b = 1;
	spheres[1].mat.refl = 0.5;
}
