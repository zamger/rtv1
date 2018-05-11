/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_con_inf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 16:12:19 by akryvenk          #+#    #+#             */
/*   Updated: 2017/10/22 16:12:19 by akryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			intersect_ray_con_inf(t_ray *r, t_con *con, double *t)
{
	t_discr d;

	d.dist = vector_sub(&r->start, &con->pos);
	d.vva = vector_dot(&r->dir, &con->dir);
	d.dpva = vector_dot(&d.dist, &con->dir);
	d.temp1 = vector_scale(d.vva, &con->dir);
	d.temp2 = vector_scale(d.dpva, &con->dir);
	d.temp1 = vector_sub(&r->dir, &d.temp1);
	d.temp2 = vector_sub(&d.dist, &d.temp2);
	d.a = con->cosa_sq * vector_dot(&d.temp1, &d.temp1);
	d.a -= con->sina_sq * d.vva * d.vva;
	d.b = 2 * con->cosa_sq * vector_dot(&d.temp1, &d.temp2);
	d.b -= 2 * con->sina_sq * d.vva * d.dpva;
	d.c = con->cosa_sq * vector_dot(&d.temp2, &d.temp2);
	d.c -= con->sina_sq * d.dpva * d.dpva;
	d.discr = d.b * d.b - 4 * d.a * d.c;
	return (discr(d, t));
}

void		norm_cone(t_base *b, t_con *c)
{
	double	cosa;

	b->new_start = vector_scale(b->t, &b->r.dir);
	b->new_start = vector_add(&b->r.start, &b->new_start);
	b->scale1 = vector_sub(&b->new_start, &c->pos);
	cosa = vector_dot(&b->scale1, &c->dir);
	cosa /= (vector_dot(&b->scale1, &b->scale1) * vector_dot(&c->dir, &c->dir));
	b->scale = vector_scale(cosa, &c->dir);
	b->n = vector_sub(&b->scale1, &b->scale);
	b->scale = vector_multpl(&b->scale1, &b->n);
	b->n = vector_multpl(&b->scale, &b->scale1);
	b->n = vector_norm(&b->n);
}

void		init_con_inf(t_con *con)
{
	con[0].pos.x = H_W - H_W;
	con[0].pos.y = H_H - H_H;
	con[0].pos.z = -10;
	con[0].angle = (15 * M_PI / 180);
	con[0].dir.x = 0;
	con[0].dir.y = 1;
	con[0].dir.z = 0;
	con[0].mat.diffuse.r = 0.5;
	con[0].mat.diffuse.g = 0.3;
	con[0].mat.diffuse.b = 0.6;
	con[0].mat.refl = 1;
	con[0].sina_sq = sin(con[0].angle) * sin(con[0].angle);
	con[0].cosa_sq = cos(con[0].angle) * cos(con[0].angle);
}
