/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_cyl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 15:13:18 by akryvenk          #+#    #+#             */
/*   Updated: 2017/10/21 15:13:19 by akryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		norm_cyl(t_base *b, t_cyl *c)
{
	b->new_start = vector_scale(b->t, &b->r.dir);
	b->new_start = vector_add(&b->new_start, &b->r.start);
	b->scale1 = vector_sub(&b->new_start, &c->pos);
	b->scale = vector_scale(vector_dot(&b->scale1, &c->dir), &c->dir);
	b->n = vector_sub(&b->scale1, &b->scale);
}

int			intersect_ray_cylindr_inf(t_ray *r, t_cyl *s, double *t)
{
	t_discr	d;

	d.dist = vector_sub(&r->start, &s->pos);
	d.temp1 = vector_scale(vector_dot(&r->dir, &s->dir), &s->dir);
	d.temp2 = vector_scale(vector_dot(&d.dist, &s->dir), &s->dir);
	d.temp1 = vector_sub(&r->dir, &d.temp1);
	d.temp2 = vector_sub(&d.dist, &d.temp2);
	d.a = vector_dot(&d.temp1, &d.temp1);
	d.b = 2 * vector_dot(&d.temp1, &d.temp2);
	d.discr = d.b * d.b - 4 * d.a *
		(vector_dot(&d.temp2, &d.temp2) - (s->rad * s->rad));
	return (discr(d, t));
}

void		init_cylindr_inf(t_cyl *cyl)
{
	cyl[0].pos.x = 652 - H_W;
	cyl[0].pos.y = 650 - H_H;
	cyl[0].pos.z = 200;
	cyl[0].rad = 100;
	cyl[0].dir.x = 1;
	cyl[0].dir.y = 0;
	cyl[0].dir.z = 0;
	cyl[0].mat.diffuse.r = 1;
	cyl[0].mat.diffuse.g = 1;
	cyl[0].mat.diffuse.b = 1;
	cyl[0].mat.refl = 1;
}
