/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 11:48:40 by guiricha          #+#    #+#             */
/*   Updated: 2016/09/30 13:39:56 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	print_error_ext(int e)
{
	if (e == 10)
		ft_printf("More than one end room");
	else if (e == 11)
		ft_printf("More than one start room");
	else if (e == 12)
		ft_printf("More than one of start AND end rooms");
	else if (e == 18)
		ft_printf("Start room not connected to end room");
	else if (e == 23)
		ft_printf("You broke my %S", L"💔 ");
	else if (e == 25)
		ft_printf("No %Ss", L"🏠 ");
	else if (e == 24)
		ft_printf("No %s%S%ss to end from start", "\e[7m", L"⇝ ", "\e[27m");
	else if (e == 100)
		ft_printf("%sMALLOC ERROR%s", RED, RESET);
	else if (e == 138)
		ft_printf("%s%S%s not at top of file", "\e[7m", L"🐜 ", "\e[27m");
}

void	print_error(int e)
{
	ft_printf("ERRNUM = %s%d%s : ", GREEN, e, RESET);
	if (e == 3)
		ft_printf("No file specified");
	else if (e == 4)
		ft_printf("Invalid file specified");
	else if (e == 5)
		ft_printf("Multiple values of %s%S%s", "\e[7m", L"🐜 ", "\e[27m");
	else if (e == 6)
		ft_printf("Invalid arguments specified");
	else if (e == 7)
		ft_printf("No start or end rooms");
	else if (e == 8)
		ft_printf("No end room");
	else if (e == 9)
		ft_printf("No start room");
	print_error_ext(e);
	ft_putchar('\n');
}
