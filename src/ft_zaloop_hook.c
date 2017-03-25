/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zaloop_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <kshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 15:28:20 by kshcherb          #+#    #+#             */
/*   Updated: 2017/03/25 16:43:38 by kshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_check_flag(t_wf *wf)
{
	(wf->flag.fl_frw == 1) ? move_forward(wf) : 777;
	(wf->flag.fl_back == 1) ? move_back(wf) : 777;
	(wf->flag.fl_left == 1) ? move_left(wf) : 777;
	(wf->flag.fl_rght == 1) ? move_right(wf) : 777;
	(wf->flag.shift == 1) ? wf->game.shift = 2 : 777;
	(wf->flag.shift == 0) ? wf->game.shift = 1 : 777;
}

void	game(t_wf *wf)
{
	mlx_hook(wf->win, 2, 1, button_press_suka, wf);
	mlx_hook(wf->win, 3, 2, button_release_game, wf);
	ft_check_flag(wf);
	mlx_destroy_image(wf->mlx, wf->img);
	wf->img = mlx_new_image(wf->mlx, wf->w_size_x, wf->w_size_y);
	raycasting(wf);
	wf = calculate_speed_fps(wf);
}

int		exit_f4(int kcode, t_wf *wf)
{
	(void)wf;
	if (kcode == 105)
		exit(1337);
	return (0);
}

int		ft_zaloop_hook(t_wf *wf)
{
	mlx_hook(wf->win, 2, 1, exit_f4, wf);
	mlx_hook(wf->win, 17, 1L << 17, exit_x, wf);
	if (wf->flmenu.menu == 0)
	{
		ft_menu(wf);
		mlx_hook(wf->win, 3, 2, button_release_menu, wf);
	}
	else if (wf->flmenu.menu == 2)
	{
		ft_menu2(wf);
		mlx_hook(wf->win, 3, 2, button_release_menu2, wf);
	}
	else if (wf->flmenu.menu == 1)
		game(wf);
	else if (wf->flmenu.menu == 3)
	{
		ft_menu_lvl(wf);
		mlx_hook(wf->win, 3, 2, button_release_level, wf);
	}
	else if (wf->flmenu.menu == 4)
	{
		mlx_put_image_to_window(wf->mlx, wf->win, wf->menu[9].img, 0, 0);
		mlx_hook(wf->win, 3, 2, button_release_control, wf);
	}
	return (0);
}
