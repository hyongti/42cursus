/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 14:40:24 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/12/06 19:05:44 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HITTABLE_H
# define HITTABLE_H

#include "vec.h"
#include "ray.h"
#include "color.h"
#include "random.h"

# define TRUE 1
# define FALSE 0

# define LAMBERTIAN 1
# define METAL 2

# define SP 1

typedef struct	s_hittable_list
{
	int			type;
	void		*object;
	void		*next;
}				t_hittable_list;

typedef struct	s_material
{
	int			mat_kind;
	t_color		albedo;
}				t_material;

typedef struct	s_hit_record
{
	t_point		p;
	t_vec		normal;
	int			front_face;
	double		t;
	double		t_min;
	double		t_max;
	t_material	material;
}				t_hit_record;

typedef struct	s_sphere
{
	t_point		center;
	double		radius;
	t_material	material;
}				t_sphere;

t_sphere	*sphere(t_point center, double radius, t_material material);

void		set_face_normal(t_ray r, t_hit_record *rec);
double		hit_sphere(t_ray r, t_sphere *sphere, t_hit_record *rec);
int			hit(t_ray r, t_hittable_list *world, t_hit_record *rec);
int			hit_list(t_ray r, t_hittable_list *world, t_hit_record *rec);
t_color		ray_color(t_ray r, t_hittable_list *world, int depth);

t_material	make_material(int mat_kind, t_color albedo);
int			by_lambertian(t_ray r_in, t_hit_record *rec, t_color *attenutaion, t_ray *scattered);
int			by_metal(t_ray r_in, t_hit_record *rec, t_color *attenutaion, t_ray *scattered);
int			scatter(t_ray r_in, t_hit_record *rec, t_color *attenuation, t_ray *scattered);

t_hittable_list		*h_lstnew(int obj_type, void *object);
t_hittable_list		*h_lstlast(t_hittable_list *lst);
void				h_lstadd_back(t_hittable_list **lst, t_hittable_list *new);

#endif