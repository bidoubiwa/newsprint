/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 13:41:46 by cvermand          #+#    #+#             */
/*   Updated: 2017/12/16 16:29:54 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hprintf.h"

int		ft_percent_handler(t_chain *elem, va_list ap)
{
	(void)ap;
	if (!(elem->show = ft_strnew(1)))
		return (-1);
	elem->show[0] = '%';
	return (ft_str_modifier(elem, elem->flag));
}

int		ft_error_handler(t_chain *elem, va_list ap)
{
	(void)elem;
	(void)ap;
	return (-1);
}
