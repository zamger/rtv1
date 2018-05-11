/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_inters_fig.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 12:05:27 by akryvenk          #+#    #+#             */
/*   Updated: 2017/10/24 12:05:28 by akryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	inter_sph_fig(t_base *b, t_fig *f)
{
	b->i = 0;
	while (b->i < f->num_sph)
	{
		if (intersect_ray_sph(&b->r, &f->s[b->i], &b->t) == 1)
		{
			b->curr_fig = b->i;
			norm_sph(b, &f->s[b->i]);
			b->mat = f->s[b->i].mat;
		}
		b->i++;
	}
}

void	inter_cyl_fig(t_base *b, t_fig *f)
{
	b->i = 0;
	while (b->i < f->num_cyl)
	{
		if (intersect_ray_cylindr_inf(&b->r, &f->c[b->i], &b->t) == 1)
		{
			b->curr_fig = b->i;
			norm_cyl(b, &f->c[b->i]);
			b->mat = f->c[b->i].mat;
		}
		b->i++;
	}
}

void	inter_con_fig(t_base *b, t_fig *f)
{
	b->i = 0;
	while (b->i < f->num_con)
	{
		if (intersect_ray_con_inf(&b->r, &f->con[b->i], &b->t) == 1)
		{
			b->curr_fig = b->i;
			norm_cone(b, &f->con[b->i]);
			b->mat = f->con[b->i].mat;
		}
		b->i++;
	}
}

void	inter_plane_fig(t_base *b, t_fig *f)
{
	b->i = 0;
	while (b->i < f->num_plane)
	{
		if (intersect_ray_plane(&b->r, &f->p[b->i], &b->t) == 1)
		{
			b->curr_fig = b->i;
			norm_plane(b, &f->p[b->i]);
			b->mat = f->p[b->i].mat;
		}
		b->i++;
	}
}
