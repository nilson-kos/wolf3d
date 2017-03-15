/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <kshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 16:05:51 by kshcherb          #+#    #+#             */
/*   Updated: 2017/03/15 21:43:29 by kshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		button_press_game(int kcode, t_wf *wf)
{
	(kcode == 53) ? wf->flmenu.menu = 0 : 777;


	(kcode == 126) ? wf->flag.fl_frw = 1 : 999;
	(kcode == 125) ? wf->flag.fl_back = 1 : 888;
	(kcode == 123) ? wf->flag.fl_left = 1 : 888;
	(kcode == 124) ? wf->flag.fl_rght = 1 : 888;

	return (0);
}

int		button_release_game(int kcode, t_wf *wf)
{
	(kcode == 126) ? wf->flag.fl_frw = 0 : 999;
	(kcode == 125) ? wf->flag.fl_back = 0 : 888;
	(kcode == 123) ? wf->flag.fl_left = 0 : 888;
	(kcode == 124) ? wf->flag.fl_rght = 0 : 888;
	return (0);
}

int		button_release_menu(int kcode, t_wf *wf)
{
	if (kcode == 36 && wf->flmenu.pos == 1)
		exit(0);
	if (kcode == 36 && wf->flmenu.pos == 0)
		wf->flmenu.menu = 1;
	(kcode == 125) ? wf->flmenu.pos += 1 : 666;
	(kcode == 126) ? wf->flmenu.pos -= 1 : 666;
	(wf->flmenu.pos == -1) ? wf->flmenu.pos = 1 : 666;
	(wf->flmenu.pos == 2) ? wf->flmenu.pos = 0 : 666;
	return (0);
}
