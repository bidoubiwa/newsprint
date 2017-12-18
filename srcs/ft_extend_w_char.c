/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extend_w_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 20:57:42 by cvermand          #+#    #+#             */
/*   Updated: 2017/12/18 22:22:10 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hprintf.h"

char		*ft_prec_on_w(t_chain *elem)
{
	int		i;
	int		carac;
	int		byte;

	i = 0;
	byte = 0;
	carac = 0;
	if (!(elem->prec < elem->nbr_byte))
		return (elem->show);
	return (elem->show);
	while (i < elem->prec)
	{
		while (elem->show[carac++] == '1')
			byte++;
		if (i + byte <= elem->prec)
			i = i + byte;
		else
			break ;
		byte = 0;
		carac = i * 8;
	}
	//new = ft_strnew()
	return (elem->show);
}
