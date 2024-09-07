/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiguel <jmiguel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:06:22 by jmiguel           #+#    #+#             */
/*   Updated: 2024/05/22 15:07:34 by jmiguel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include <stdlib.h>
# include <unistd.h>

void	ft_char(char c, int *tamanho);
void	ft_hex_lower(unsigned int num, int *tamanho);
void	ft_hex_upper(unsigned int num, int *tamanho);
void	ft_int(int n, int *tamanho);
void	ft_pointer(void *ptr, int *tamanho);
void	ft_string(char *str, int *tamanho);
void	ft_unsigned(unsigned int num, int *tamanho);

#endif
