/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_inters_sh.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 11:50:03 by akryvenk          #+#    #+#             */
/*   Updated: 2017/10/24 11:50:03 by akryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	inter_sh_shadow(t_base *b, t_fig *f)
{
	b->k = 0;
	while (b->k < f->num_sph)
	{
		if (intersect_ray_sph(&b->light_ray, &f->s[b->k], &b->tt) == 1)
		{
			b->shadow++;
			b->k += 100;
		}
		b->k++;
	}
}

void	inter_cyl_shadow(t_base *b, t_fig *f)
{
	b->k = 0;
	while (b->k < f->num_cyl)
	{
		if (intersect_ray_cylindr_inf(&b->light_ray, &f->c[b->k], &b->tt) == 1)
		{
			b->shadow++;
			b->k += 100;
		}
		b->k++;
	}
}

void	inter_con_shadow(t_base *b, t_fig *f)
{
	b->k = 0;
	while (b->k < f->num_con)
	{
		if (intersect_ray_con_inf(&b->light_ray, &f->con[b->k], &b->tt) == 1)
		{
			b->shadow++;
			b->k += 100;
		}
		b->k++;
	}
}

void	inter_plane_shadow(t_base *b, t_fig *f)
{
	b->k = 0;
	while (b->k < f->num_plane)
	{
		if (intersect_ray_plane(&b->light_ray, &f->p[b->k], &b->tt) == 1)
		{
			b->shadow++;
			b->k += 100;
		}
		b->k++;
	}
}
