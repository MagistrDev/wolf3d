/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 20:11:59 by ecelsa            #+#    #+#             */
/*   Updated: 2020/05/02 02:22:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>

void	ft_putstr_fd(char const *s, int fd)
{
	char	*str;

	if (s != NULL)
	{
		str = (char*)s;
		while (*str)
		{
			write(fd, str, 1);
			str++;
		}
	}
}
