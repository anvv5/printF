/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 12:02:57 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/18 11:26:01 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				ft_type_parse(char *line, int *type)
{
	if ((*line == 'd') || (*line == 'i'))
		*type = 1;
	else if (*line == 'u')
		*type = 2;
	else if (*line == 'x')
		*type = 3;
	else if (*line == 'X')
		*type = 4;
	else if (*line == 'c')
		*type = 5;
	else if (*line == 's')
		*type = 6;
	else if (*line == 'p')
		*type = 7;
	else if (*line == '%')
		*type = 8;
	return (1);
}
