/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 20:12:22 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/12 20:16:22 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_matrix44		*m_identity(void)
{
	t_matrix44	*matrix;
	int			i;
	int			j;

	if(!(matrix = (t_matrix44 *)malloc(sizeof(t_matrix44))))
		return (NULL);
	i = -1;
	while(++i < 4)
	{
		j = -1;
		while (++j < 4)
			matrix->x[i][j] = (i == j) ? 1 : 0;
	}
	return (matrix);
}

t_matrix44		*m_move(t_point move)
{
	t_matrix44 *mtx;

	mtx = m_identity();
	mtx->x[3][0] = move.x;
	mtx->x[3][1] = move.y;
	mtx->x[3][2] = move.z;
	return (mtx);
}

t_matrix44		*m_rotate_x(double degree)
{
	t_matrix44	*mtx;
	double		theta;

	theta = deg_to_rad(degree);
	mtx = m_identity();
	mtx->x[1][1] = cos(theta);
	mtx->x[1][2] = sin(theta);
	mtx->x[2][1] = -sin(theta);
	mtx->x[2][2] = cos(theta);
	return (mtx);
}

t_matrix44		*m_rotate_y(double degree)
{
	t_matrix44	*mtx;
	double		theta;

	theta = deg_to_rad(degree);
	mtx = m_identity();
	mtx->x[0][0] = cos(theta);
	mtx->x[0][2] = -sin(theta);
	mtx->x[2][0] = sin(theta);
	mtx->x[2][2] = cos(theta);
	return (mtx);
}

t_matrix44		*m_rotate_z(double degree)
{
	t_matrix44	*mtx;
	double		theta;

	theta = deg_to_rad(degree);
	mtx = m_identity();
	mtx->x[0][0] = cos(theta);
	mtx->x[0][1] = sin(theta);
	mtx->x[1][0] = -sin(theta);
	mtx->x[1][1] = cos(theta);
	return (mtx);
}

t_vec			m_mult_v(t_vec vec, double h, t_matrix44 *mtx)
{
	t_vec	new;

	if (mtx == NULL)
		return (vec);
	new.x = vec.x * mtx->x[0][0] + vec.y * mtx->x[1][0] + vec.z * mtx->x[2][0] + h * mtx->x[3][0];
	new.y = vec.x * mtx->x[0][1] + vec.y * mtx->x[1][1] + vec.z * mtx->x[2][1] + h * mtx->x[3][1];
	new.z = vec.x * mtx->x[0][2] + vec.y * mtx->x[1][2] + vec.z * mtx->x[2][2] + h * mtx->x[3][2];
	return (new);
}

void			m_mult_m(t_matrix44 *dst, t_matrix44 *src)
{
	t_matrix44	new;
	int			i;
	int			j;
	int			k;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			k = -1;
			new.x[i][j]  = 0;
			while (++k < 4)
				new.x[i][j] += dst->x[i][k] * src->x[k][j];
		}
	}
	*dst = new;
}

t_matrix44		*rotate(t_vec rotate)
{
	t_matrix44	*result;
	t_matrix44	*rotate_y;
	t_matrix44	*rotate_z;

	result = m_rotate_x(rotate.x);
	rotate_y = m_rotate_y(rotate.y);
	rotate_z = m_rotate_z(rotate.z);
	m_mult_m(result, rotate_y);
	m_mult_m(result, rotate_z);
	free(rotate_y);
	free(rotate_z);
	result->rotate_deg = rotate;
	return (result);
}

t_matrix44		transpose(t_matrix44 *orig)
{
	t_matrix44 	new;
	int			i;
	int			j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			new.x[i][j] = orig->x[j][i];
		}
	}
	return (new);
}

t_matrix44 *inverse(t_matrix44 a)
{
	t_matrix44 *inv;
	int	i;
	int	j;
	int	k;
	double ratio;

	inv = m_identity();

	// Applying Gauss Jordan Elimination
	i = -1;
	while (++i < 4)
	{
		if (a.x[i][i] == 0.0)
		{
			perror("Matrix Inverse error! transform matirx can't have inverse");
			exit (1);
		}
		j = -1;
		while (++j < 4)
		{
			if (i != j)
			{
				ratio = a.x[j][i] / a.x[i][i];
				k = -1;
				while (++k < 4)
				{
					a.x[j][k] = a.x[j][k] - ratio * a.x[i][k];
					inv->x[j][k] = inv->x[j][k] - ratio * inv->x[i][k];
				}
			}
		}
	}
	// Row Operation to Make Principal Diagonal to 1
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			inv->x[i][j] = inv->x[i][j] / a.x[i][i];
	}
	return (inv);
}

t_matrix44 *rotate_normal(t_matrix44 *rotate)
{
	t_matrix44 *rotate_normal;

	if (rotate == NULL)
		return (NULL);
	rotate_normal = inverse(*rotate);
	// transpose(rotate_normal);
	return (rotate_normal);
}