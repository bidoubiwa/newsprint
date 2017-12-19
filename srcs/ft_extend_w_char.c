/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extend_w_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 20:57:42 by cvermand          #+#    #+#             */
/*   Updated: 2017/12/19 21:00:44 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hprintf.h"

static int	ft_number_byte_for_carac(char *show, int y)
{
	int byte;

	byte = 0;
	while (show[y++] == '1')
		byte++;
	return (byte);
}

char		*ft_prec_on_w(t_chain *elem)
{
	size_t	i;
	int		carac;
	int		byte;

	i = 0;
	carac = 0;
	if (elem->prec > elem->nbr_byte)
		return (elem->show);	
	while ( i < elem->prec && elem->show[carac])
	{
		byte = 0;
		if (elem->show[carac] == '0')
			byte++;
		else if (elem->show[carac] == '1')
			byte = ft_number_byte_for_carac(elem->show, carac);
		i += byte;
		carac = i * 8;	
	}
	if (i > elem->prec)
		i -= byte;
	free(elem->show);
	elem->show = ft_strsub(elem->show, 0, i * 8);
	elem->nbr_carac = i;
	return (elem->show);
}
