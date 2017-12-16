/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chainfct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 13:43:46 by cvermand          #+#    #+#             */
/*   Updated: 2017/12/16 16:28:24 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hprintf.h"

void			ft_setup_chain_info(t_chain *elem, t_flag *flag)
{
	flag->left = 0;
	flag->blank = 0;
	flag->plus = 0;
	flag->zero = 0;
	flag->apos = 0;
	flag->hash = 0;
	flag->star = 0;
	flag->wdol = 0;
	elem->just_show = 0;
	elem->nbr_carac = 0;
	elem->width = 0;
	elem->give_p = 0;
	elem->prec = 0;
	elem->len = 0;
	elem->maj = 0;
	elem->pdol = 0;
	elem->conv = 0;
	elem->show = NULL;
	elem->next = NULL;
}

void			ft_lstadd_after(t_chain *elem, t_chain **chain)
{
	t_chain	*tmp;

	tmp = *chain;
	if (tmp == NULL)
		*chain = elem;
	else
	{
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = elem;
	}
}

int				ft_show_only_parser(const char *format, size_t len, t_chain **c)
{
	char		*new;
	t_chain		*elem;

	if (!(new = ft_strsub(format, 0, len)))
		return (0);
	if (!(elem = ft_create_elem()))
		return (0);
	elem->just_show = 1;
	elem->nbr_carac = len;
	elem->show = new;
	ft_lstadd_after(elem, c);
	return (1);
}

/*t_chain		*ft_get_dollar_order(t_chain *chain)
{
	t_chain		*current;
	t_chain		*previous;
	t_chain		*tmp;
	int			change;

	change = 1;
	current = chain;
	previous = NULL;
	while (change)
	{
		change = 0;
		while (current && current->next)
		{
			tmp = current->next;
			if (current->dollar > tmp->dollar)
			{
				if (begin == current)
					begin = tmp;
				if (previous)
					previous->next = tmp;
				current->next = tmp->next;
				tmp->next = current;
				change = 1;
			}
			else
				current = current->next;
		}
	}
	return (begin);
}*/

t_chain			*ft_create_elem(void)
{
	t_chain	*new;
	t_flag	*flag;

	if (!(new = malloc(sizeof(t_chain))))
		return (NULL);
	if (!(flag = malloc(sizeof(t_flag))))
	{
		free(new);
		return (NULL);
	}
	new->flag = flag;
	ft_setup_chain_info(new, flag);
	return (new);
}