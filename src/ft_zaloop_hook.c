/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zaloop_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <kshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 15:28:20 by kshcherb          #+#    #+#             */
/*   Updated: 2017/03/20 13:24:55 by kshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_check_flag(t_wf *wf)
{
	(wf->flag.fl_frw == 1) ? move_forward(wf) : 777;
	(wf->flag.fl_back == 1) ? move_back(wf) : 777;
	(wf->flag.fl_left == 1) ? move_left(wf) : 777;
	(wf->flag.fl_rght == 1) ? move_right(wf) : 777;

}

int		ft_zaloop_hook(t_wf *wf)
{
	if (wf->flmenu.menu == 0)
	{
		ft_menu(wf);
		mlx_hook(wf->win, 3, 2, button_release_menu, wf);
	}
	else
	{
		mlx_hook(wf->win, 2, 1, button_press_game, wf);
		mlx_hook(wf->win, 3, 2, button_release_game, wf);
		//wf = calculate_speed_fps(wf);
		ft_check_flag(wf);
		mlx_destroy_image(wf->mlx, wf->img);
		wf->img = mlx_new_image(wf->mlx, wf->w_size_x, wf->w_size_y);
		raycasting(wf);
		wf = calculate_speed_fps(wf);
	}
	return (0);
}
