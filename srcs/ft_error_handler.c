/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 13:41:46 by cvermand          #+#    #+#             */
/*   Updated: 2017/12/21 00:14:45 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hprintf.h"

/*static t_chain	*ft_lstlast_chain(t_chain *begin_list)
{
	t_chain		*buff;

	if (begin_list == 0)
		return (0);
	buff = begin_list;
	while (buff->next)
	{
		buff = buff->next;
	}
	return (buff);
}*/

t_chain	*ft_lstfree(t_chain *current)
{
	t_chain *tmp;
	t_chain	*next;

	tmp = current;
	while (tmp)
	{
		next = tmp->next;	
		if (tmp->flag)
			free(tmp->flag);
		if (tmp->show)
			free(tmp->show);
		
		tmp->next = NULL;
		free(tmp);
		tmp = next;
	}
	return (NULL);
}

int		ft_percent_handler(t_chain *elem, va_list ap)
{
	(void)ap;
	if (!(elem->show = ft_strnew(1)))
		return (-1);
	elem->show[0] = '%';
	return (ft_str_modifier(elem, elem->flag));
}

int		ft_show_error(t_chain *elem, t_chain *begin)
{
	t_chain		*current;
	t_chain		*previous;

	previous = NULL;
	if (ft_is_w_char(elem))
	{
		current = begin;
		while (current)
		{
			if (current == elem || current->next == elem)
			{
				dprintf(2,"AVANT ABORD\n");
				if (current->just_show == 1 || current == elem)
				{
					if (previous)
						previous->next = ft_lstfree(current);
					else
						current = ft_lstfree(current);
				}
				else
				{
					current->next = ft_lstfree(current->next);
				}
			}
			if (current)
			{
				previous = current;
				current = current->next;
			}
		}
		
		dprintf(2,"APRES ABORD\n");
		if (begin)
			ft_show_all(begin);
		dprintf(2,"APRES ABORD\n");
	}	
	dprintf(2,"AVT RETURN\n");
	return (-1);
}

int		ft_error_handler(t_chain *elem, va_list ap)
{
	(void)ap;
	if (!(elem->show = ft_strnew(1)))
		return (-1);
	elem->show[0] = elem->conv;
	return (ft_str_modifier(elem, elem->flag));
}
