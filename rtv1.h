/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:57:39 by akryvenk          #+#    #+#             */
/*   Updated: 2017/05/15 16:57:40 by akryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "mlx.h"
# include <math.h>
// # include <stdio.h>
# define W 1200
# define H 800
# define H_W W / 2
# define H_H H / 2

typedef struct	s_vec
{
	double	x;
	double	y;
	double	z;
}				t_vec;

typedef struct	s_ray
{
	t_vec	start;
	t_vec	dir;
}				t_ray;

typedef struct	s_color
{
	double	r;
	double	g;
	double	b;
}				t_color;

typedef	struct	s_light
{
	t_vec	pos;
	t_color	intens;
}				t_light;

typedef struct	s_material
{
	t_color	diffuse;
	double	refl;
}				t_material;

typedef struct	s_sphere
{
	t_vec		pos;
	double		rad;
	t_material	mat;
}				t_sphere;

typedef struct	s_cyl
{
	t_vec		pos;
	t_vec		dir;
	double		rad;
	t_material	mat;
}				t_cyl;

typedef struct	s_con
{
	t_vec		pos;
	t_vec		dir;
	double		angle;
	t_material	mat;
	double		sina_sq;
	double		cosa_sq;	
}				t_con;

typedef struct	s_plane
{
	double		d;
	t_vec		dir;
	t_material	mat;

}				t_plane;

// typedef struct s_use_fig
// {
// 	t_vec		pos;
// 	t_material	mat;
// }				t_use_fig;


typedef struct	s_fig
{
	int		num_sph;
	int		num_light;
	int 	num_cyl;
	int 	num_con;
	int		num_plane;
	t_sphere s[2];
	t_light l[3];
	t_cyl	c[1];
	t_con	con[1];
	t_plane	p[1];
	// t_use_fig u_f;


}				t_fig;




typedef struct	s_base
{
	t_ray		r;
	t_color		col;
	int			x;
	int			y;
	int			i;
	int			j;
	int			k;
	int			level;
	int			level_max;
	int			shadow;
	double		coef;
	double		lamb;
	double		t;
	int			curr_fig;
	t_ray		light_ray;
	t_material	mat;
	t_vec		scale;
	t_vec		scale1;
	t_vec		new_start;
	t_vec		n;
	t_vec		dist;
	t_vec		temm;
	double		tem;
	double		tt;
	t_light		light;
	double		angle_a;
	double		angle_b;
	double		angle_g;
	double		z_zoom;
	double		tan_x;
	double		tan_y;
}				t_base;

typedef struct	s_img
{
	void		*mlx;
	void		*win;
	char		*p;
	void		*image;
	char		*scen;
	t_base		b;
	int			flag;
}				t_img;

typedef struct	s_discr
{
	double	a;
	double	b;
	double	c;
	double	discr;
	double	t0;
	double	t1;
	double	vva;
	double	dpva;
	t_vec	temp1;
	t_vec	temp2;
	t_vec	dist;

}				t_discr;

typedef struct	s_rot
{
	double		angl_x;
	double		angl_y;
	double		angl_z;
	double		cy_cz;
	double		sy_sx;
	double		cy_sz_cx;
	double		sum1;
	double		cy_sz_sx;
	double		sy_cx;
	double		sum2;
	double		sz;
	double		cz_cx;
	double		cz_sx;
	double		sy_cz;
	double		sy_sz_cx;
	double		cy_cx;
	double		sx_cy;
	double		sx_sy_sz;
	double		sum3;
	double		sum4;
}				t_rot;

int				ft_mouse_exit(void);
int				my_key_funct(int keycode, t_img *im);
int				ft_draw(t_img *im);
t_vec			vector_sub(t_vec *v1, t_vec *v2);
double			vector_dot(t_vec *v1, t_vec *v2);
t_vec			vector_scale(double c, t_vec *v);
t_vec			vector_add(t_vec *v1, t_vec *v2);
t_vec			vector_multpl(t_vec *v1, t_vec *v2);
void			put_pixl(t_img *im, int x, int y, t_color col);
void			calc_func(t_img *im, t_base *b);
int				intersect_ray_sph(t_ray *r, t_sphere *sph, double *t);
void			norm_sph(t_base *b, t_sphere *s);
void			init_sphere(t_sphere *spheres);
int				intersect_ray_cylindr_inf(t_ray *r, t_cyl *s, double *t);
void			norm_cyl(t_base *b, t_cyl *c);
void			init_cylindr_inf(t_cyl *cyl);
int				intersect_ray_con_inf(t_ray *r, t_con *con, double *t);
void			norm_cone(t_base *b, t_con *c);
void			init_con_inf(t_con *con);
void			norm_plane(t_base *b, t_plane *p);
int				intersect_ray_plane (t_ray *r, t_plane *p, double *t);
void			init_plane(t_plane *p);
int				intersect_ray_plane (t_ray *r, t_plane *p, double *t);
int				discr(t_discr d, double *t);
// t_vec			init_ray(t_base *b, int x, int y);
void			init_base_in_arr(t_base *b);
void			init_spot_light(t_light *light);
void			calc_pix_arr(t_img *im, t_base *b, t_fig *f);
void			init_base_in_arr(t_base *b);
t_color			init_color(double r, double g, double b);
int				discr(t_discr d, double *t);
void			ft_error(int a);
t_vec 			vector_norm(t_vec *vec);
t_vec			pix_x_y(t_base *b, t_vec vec);
void			inter_sh_shadow(t_base *b, t_fig *f);
void			inter_cyl_shadow(t_base *b, t_fig *f);
void			inter_con_shadow(t_base *b, t_fig *f);
void			inter_plane_shadow(t_base *b, t_fig *f);
void			inter_sph_fig(t_base *b, t_fig *f);	
void			inter_cyl_fig(t_base *b, t_fig *f);
void			inter_con_fig(t_base *b, t_fig *f);
void			inter_plane_fig(t_base *b, t_fig *f);
void			ft_return_tan(t_base *b);

#endif
