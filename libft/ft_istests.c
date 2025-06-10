/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_istests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgribei <edgribei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:39:14 by edgribei          #+#    #+#             */
/*   Updated: 2025/04/15 16:30:52 by edgribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

int	ft_isalpha(int c)
{
	return (((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) << 10);
}

int	ft_isdigit(int c)
{
	return ((c >= '0' && c <= '9') << 11);
}

int	ft_isprint(int c)
{
	return ((c >= ' ' && c < 127) << 14);
}

int	ft_isalnum(int c)
{
	return ((ft_isalpha(c) || ft_isdigit(c)) << 3);
}
