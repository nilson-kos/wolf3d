/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   download_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshcherb <kshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 20:12:29 by kshcherb          #+#    #+#             */
/*   Updated: 2017/03/25 15:39:01 by kshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_wf	*download_menu(t_wf *wf)
{
	wf->menu = (t_menu *)malloc(sizeof(t_menu) * 10);
	wf->menu[0].img = mlx_xpm_file_to_image(wf->mlx,
			"img/menu1/menu1_1.xpm", &wf->menu[0].x, &wf->menu[0].y);
	wf->menu[1].img = mlx_xpm_file_to_image(wf->mlx,
			"img/menu1/menu1_2.xpm", &wf->menu[1].x, &wf->menu[1].y);
	wf->menu[2].img = mlx_xpm_file_to_image(wf->mlx,
			"img/menu1/menu1_3.xpm", &wf->menu[2].x, &wf->menu[2].y);
	wf->menu[3].img = mlx_xpm_file_to_image(wf->mlx,
			"img/menu2/menu2-1.XPM", &wf->menu[3].x, &wf->menu[3].y);
	wf->menu[4].img = mlx_xpm_file_to_image(wf->mlx,
			"img/menu2/menu2-2.XPM", &wf->menu[4].x, &wf->menu[4].y);
	wf->menu[5].img = mlx_xpm_file_to_image(wf->mlx,
			"img/menu2/menu2-3.XPM", &wf->menu[5].x, &wf->menu[5].y);
	wf->menu[6].img = mlx_xpm_file_to_image(wf->mlx,
			"img/menu2/menu2-4.XPM", &wf->menu[6].x, &wf->menu[6].y);
	wf->menu[7].img = mlx_xpm_file_to_image(wf->mlx,
			"img/lvl/level1.XPM", &wf->menu[7].x, &wf->menu[7].y);
	wf->menu[8].img = mlx_xpm_file_to_image(wf->mlx,
			"img/lvl/level2.XPM", &wf->menu[8].x, &wf->menu[8].y);
	wf->menu[9].img = mlx_xpm_file_to_image(wf->mlx,
			"img/control.XPM", &wf->menu[9].x, &wf->menu[9].y);
	return (wf);
}

t_wf	*download_tex(t_wf *wf)
{
	wf->tex = (t_tex *)malloc(sizeof(t_tex) * 8);
	wf->tex[0].img = mlx_xpm_file_to_image(wf->mlx,
		"img/texture/basement.XPM", &wf->tex[0].x, &wf->tex[0].y);
	wf->tex[1].img = mlx_xpm_file_to_image(wf->mlx,
		"img/texture/wood.XPM", &wf->tex[1].x, &wf->tex[1].y);
	wf->tex[2].img = mlx_xpm_file_to_image(wf->mlx,
		"img/texture/floor.xpm", &wf->tex[2].x, &wf->tex[2].y);
	wf->tex[3].img = mlx_xpm_file_to_image(wf->mlx,
		"img/texture/finish.XPM", &wf->tex[3].x, &wf->tex[3].y);
	wf->tex[4].img = mlx_xpm_file_to_image(wf->mlx,
		"img/texture/door.XPM", &wf->tex[4].x, &wf->tex[4].y);
	wf->tex[5].img = mlx_xpm_file_to_image(wf->mlx,
		"img/texture/floor2.XPM", &wf->tex[5].x, &wf->tex[5].y);
	wf->tex[6].img = mlx_xpm_file_to_image(wf->mlx,
		"img/texture/magicblue.XPM", &wf->tex[6].x, &wf->tex[6].y);
	wf->tex[7].img = mlx_xpm_file_to_image(wf->mlx,
		"img/texture/rock.xpm", &wf->tex[7].x, &wf->tex[7].y);
	return (wf);
}

t_wf	*download_image(t_wf *wf)
{
	wf = download_menu(wf);
	wf = download_tex(wf);
	return (wf);
}
