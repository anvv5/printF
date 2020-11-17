/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudding <sbudding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 13:12:30 by sbudding          #+#    #+#             */
/*   Updated: 2020/11/17 10:21:45 by sbudding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				ft_di_type(t_save *data, va_list ap)
{
	char		*output;		//2 - '-'
	int			num;			//1 - '0'
	int			sign;			//0 - NULL
	int			len;
	int	i;
	
	i = 0;
	num = va_arg(ap, int);
	sign = 0;
	if (num < 0)
		sign++;
	output = ft_itoa(num);
	len = ft_strlen(output);
	if ((data->width > len) && ((data->flags == 1) || (data->flags == 0)))
	{
		if (!data->precision)
			while (data->width > len)
			{
				ft_putchar_fd('0', 1);
				len++;
			}
		else
		{
			while (data->width > (i + data->precision))
			{
				ft_putchar_fd(' ', 1);
				len++;
				i++;
			}
			while (data->width > len)
			{
				ft_putchar_fd('0', 1);
				len++;
			}
		}
	}
	if ((data->precision > len) && ((data->flags == 1) || (data->flags == 0)))
	{
		if (!data->width)
			while (data->precision > len)
			{
				ft_putchar_fd('0', 1);
				len++;
			}
		else
		{
			// while (data->precision > (i + data->width))
			// {
			// 	ft_putchar_fd(' ', 1);
			// 	len++;
			// 	i++;
			// }
			while (data->precision > len)
			{
				ft_putchar_fd('0', 1);
				len++;
			}
		}
	}
	ft_putstr_fd(output, 1);
	return (len);
}