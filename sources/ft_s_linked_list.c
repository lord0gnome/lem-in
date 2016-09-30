/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_linked_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 13:01:49 by guiricha          #+#    #+#             */
/*   Updated: 2016/09/30 12:16:38 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
#include <stdlib.h>

void		det_line(int flag)
{
	if (flag == 0)
		ft_putstr("Comment : ");
	else if (flag == 2)
		ft_putstr("Room    : ");
	else if (flag == 3)
		ft_putstr("Link    : ");
	else if (flag == 4)
		ft_putstr("Command : ");
	else if (flag == 5)
		ft_putstr("Numants : ");
	else if (flag == -1)
		ft_putstr("ERROR   : ");
}

void		ft_print_members(t_s_list *list, t_l_data *d)
{
	while (list && (d->debug || list->flag != -1))
	{
		if (d->nocomment && list->flag == 0)
		{
			list = list->next;
			continue ;
		}
		if (d->debug)
			det_line(list->flag);
		ft_putendl(list->str);
		list = list->next;
	}
}

void		ft_swap_members(t_s_list **m1, t_s_list **m2)
{
	t_s_list	*bck;

	bck = (t_s_list *)malloc(sizeof(t_s_list));
	if (!(*m1) || !(*m2))
		return ;
	bck->str = ft_strdup((*m1)->str);
	bck->flag = (*m1)->flag;
	free((*m1)->str);
	(*m1)->str = ft_strdup((*m2)->str);
	free((*m2)->str);
	(*m2)->str = ft_strdup(bck->str);
	(*m1)->flag = (*m2)->flag;
	(*m2)->flag = bck->flag;
}

t_s_list	*ft_create_s_list(char *str, char flag)
{
	t_s_list	*new;

	if (!(new = (t_s_list *)malloc(sizeof(t_s_list))))
		return (NULL);
	new->str = ft_strdup(str);
	new->flag = flag;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_s_list	*ft_s_list(char *str, char flag, t_l_data *d)
{
	t_s_list	*travel;
	t_s_list	*new;

	if (d->first == 0 && is_random(str, d))
		return (NULL);
	d->first++;
	if (!d->lines)
		return (new = ft_create_s_list(str, flag));
	travel = d->lines;
	if (!(new = (t_s_list *)malloc(sizeof(t_s_list))))
		return (NULL);
	while (travel && travel->next)
		travel = travel->next;
	travel->next = new;
	new->str = ft_strdup(str);
	new->flag = flag;
	new->next = NULL;
	new->prev = travel;
	return (d->lines);
}
