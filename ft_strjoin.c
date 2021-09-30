/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:33:53 by wgerdur           #+#    #+#             */
/*   Updated: 2020/11/09 16:40:25 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	cnter_1;
	size_t	cnter_2;

	cnter_1 = 0;
	cnter_2 = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	s3 = (char *)malloc(sizeof(char ) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (0);
	while (s1[cnter_1])
	{
		s3[cnter_1] = s1[cnter_1];
		cnter_1++;
	}
	while (s2[cnter_2])
	{
		s3[cnter_2 + cnter_1] = s2[cnter_2];
		cnter_2++;
	}
	s3[cnter_2 + cnter_1] = '\0';
	free((char *)s1);
	return (s3);
}
