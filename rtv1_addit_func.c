/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_addit_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 16:07:10 by akryvenk          #+#    #+#             */
/*   Updated: 2017/10/22 16:07:11 by akryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
// #include <stdio.h>

void		ft_error(int a)
{
	if (a == 1)
		ft_putendl("write in arg 1, 2 or 3");
	if (a == 2)
		ft_putendl("write in arg 1, 2 or 3");
	exit(0);
}

t_color		init_color(double r, double g, double b)
{
	t_color	col;

	col.r = r;
	col.g = g;
	col.b = b;
	return (col);
}

int			discr(t_discr d, double *t)
{
	if (d.discr < 0)
		return (0);
	d.discr = sqrt(d.discr);
	d.t0 = (-d.b + d.discr) / (2 * d.a);
	d.t1 = (-d.b - d.discr) / (2 * d.a);
	d.t0 > d.t1 ? d.t0 = d.t1 : 0;
	if ((d.t0 > 0.00000001) && (d.t0 < *t))
	{
		*t = d.t0;
		return (1);
	}
	return (0);
}

t_vec		vector_norm(t_vec *vec)
{
	t_vec	result;
	double	sum;

	sum = sqrt(vector_dot(vec, vec));
	result.x = vec->x / sum;
	result.y = vec->y / sum;
	result.z = vec->z / sum;
	return (result);
}

void		ft_return_tan(t_base *b)
{
	double	teta;
	double	coef;

	coef = (double)W/(double)H;
	// printf("coef %f\n",coef);
	teta = atan(b->z_zoom / (W+H));
	b->tan_y = tan(-teta);

	b->tan_x = tan(-teta);
	// teta *= W;
	// teta /= H;
}
