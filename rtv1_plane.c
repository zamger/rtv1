/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 16:19:14 by akryvenk          #+#    #+#             */
/*   Updated: 2017/10/23 16:19:21 by akryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		norm_plane(t_base *b, t_plane *p)
{
	b->n = p->dir;
	b->scale1 = vector_scale(b->t, &b->r.dir);
	b->new_start = vector_add(&b->r.start, &b->scale1);
}

int			intersect_ray_plane(t_ray *r, t_plane *p, double *t)
{
	t_discr	d;

	d.a = vector_dot(&p->dir, &r->dir);
	if (d.a == 0)
		return (0);
	d.b = -(vector_dot(&p->dir, &r->start) + p->d);
	d.t0 = d.b / d.a;
	if (d.t0 > 0.000001)
	{
		if ((d.t0 < *t))
		{
			*t = d.t0;
			return (1);
		}
	}
	return (0);
}

void		init_plane(t_plane *p)
{
	p[0].d = 200;
	p[0].dir.x = 0;
	p[0].dir.y = 0;
	p[0].dir.z = -1;
	p[0].mat.diffuse.r = 0.5;
	p[0].mat.diffuse.g = 0.3;
	p[0].mat.diffuse.b = 0.1;
	p[0].mat.refl = 1;
}
