/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 20:12:32 by ecelsa            #+#    #+#             */
/*   Updated: 2020/05/02 02:21:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>

void	ft_putendl(char const *s)
{
	char *str;

	if (s != NULL)
	{
		str = (char*)s;
		while (*str)
			write(1, str++, 1);
		write(1, "\n", 1);
	}
}
