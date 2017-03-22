/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <kshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:18:13 by kshcherb          #+#    #+#             */
/*   Updated: 2017/03/22 20:14:05 by kshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_pix_put(t_wf *wf, int x, int y, int rgb)
{
	int				bpp;
	int				sl;
	int				en;
	char			*imag;
	unsigned int	tmp;

	imag = mlx_get_data_addr(wf->img, &bpp, &sl, &en);
	tmp = (mlx_get_color_value(wf->mlx, rgb));
	if (x > 0 && x < wf->w_size_x && y > 0 && y < wf->w_size_y)
		ft_memcpy((void *)((imag + y * wf->w_size_x *
						(bpp / 8) + x * (bpp / 8))), (void *)&tmp, 4);
}

int		ft_pix_get(t_wf *wf, int x, int y, int numtex)
{
	int				bpp;
	int				sl;
	int				en;
	char			*imag;
	unsigned int	tmp;

	tmp = 0;
	imag = mlx_get_data_addr(wf->tex[numtex].img, &bpp, &sl, &en);
	if (x >= 0 && x < wf->tex[numtex].x && y >= 0 && y < wf->tex[numtex].y)
		ft_memcpy((void *)&tmp, (void *)((imag + y * wf->tex[numtex].x *
						(bpp / 8) + x * (bpp / 8))), 4);
	return (tmp);
}

char	ft_chmo(t_wf *wf, int y, int x)
{
	if ((y < 0 || x < 0) || x >= wf->read.w - 1 || y >= wf->count - 1)
		return (127);
	return (wf->lvl1[y][x]);
}

int		exit_x(void *par)
{
	par = NULL;
	exit(1);
	return (0);
}
