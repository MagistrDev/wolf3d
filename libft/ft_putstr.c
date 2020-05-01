/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 19:59:23 by ecelsa            #+#    #+#             */
/*   Updated: 2020/05/02 02:20:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>

void	ft_putstr(char const *s)
{
	char	*str;

	if (s != NULL)
	{
		str = (char*)s;
		while (*str)
		{
			write(1, str, 1);
			str++;
		}
	}
}
