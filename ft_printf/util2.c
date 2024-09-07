/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiguel <jmiguel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:02:00 by jmiguel           #+#    #+#             */
/*   Updated: 2024/05/22 14:51:32 by jmiguel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_unsigned(unsigned int num, int *tamanho)
{
	if (num >= 10)
		ft_unsigned(num / 10, tamanho);
	ft_char((num % 10) + '0', tamanho);
}

void	ft_hex_lower(unsigned int num, int *tamanho)
{
	if (num >= 16)
		ft_hex_lower((num / 16), tamanho);
	ft_char("0123456789abcdef"[num % 16], tamanho);
}

void	ft_hex_upper(unsigned int num, int *tamanho)
{
	if (num >= 16)
		ft_hex_upper((num / 16), tamanho);
	ft_char("0123456789ABCDEF"[num % 16], tamanho);
}
