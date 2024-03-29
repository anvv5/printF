/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:06:41 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/18 12:16:42 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				ft_c_type(t_save *data, va_list ap)
{
	char		output;
	int			i;

	output = va_arg(ap, int);
	i = 1;
	if (data->width != 0)
	{
		if (data->flags == 2)
			ft_putchar_fd(output, 1);
		while (data->width > i)
		{
			if ((data->precision == 0) && (data->flags == 1))
				ft_putchar_fd('0', 1);
			else
				ft_putchar_fd(' ', 1);
			i++;
		}
		if (data->flags != 2)
			ft_putchar_fd(output, 1);
	}
	else
		ft_putchar_fd(output, 1);
	return (i);
}
