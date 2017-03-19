/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pix_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <kshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 21:02:32 by kshcherb          #+#    #+#             */
/*   Updated: 2017/03/19 19:26:11 by kshcherb         ###   ########.fr       */
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

void	ft_draw_line(t_wf *wf, int x)
{
	while (wf->game.drawstart != wf->game.drawend)
	{
		ft_pix_put(wf, x, wf->game.drawstart, wf->game.color);
		wf->game.drawstart++;
	}
}
