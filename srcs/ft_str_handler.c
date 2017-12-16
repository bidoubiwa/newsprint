/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 17:07:26 by cvermand          #+#    #+#             */
/*   Updated: 2017/12/16 17:07:29 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hprintf.h"

int		ft_str_modifier(t_chain *elem, t_flag *flag)
{
	if (!elem->show)
		return (0);
	if (elem->give_p)
		elem->show = ft_precision(elem);
	if (elem->width > elem->nbr_carac)
		elem->show = ft_width(elem, flag);
	return (1);
}

int		ft_str_handler(t_chain *elem, va_list ap)
{
	char		c;

	if (elem->conv == 's' && elem->len != 'l')
	{
		elem->show = ft_strdup(va_arg(ap, char *));
		elem->nbr_carac = ft_strlen(elem->show);
	}
	else if (elem->conv == 'c' && elem->len != 'l')
	{
		c = va_arg(ap, int);
		elem->show = ft_strdup(&c);
		elem->nbr_carac = 1;
	}
	else
		elem->show = ft_strnew(0);
	return (ft_str_modifier(elem, elem->flag));
}
