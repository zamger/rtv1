/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 15:35:39 by akryvenk          #+#    #+#             */
/*   Updated: 2016/09/05 18:40:58 by akryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	int value;
	int flag;
	int i;

	value = 0;
	i = 0;
	flag = 1;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\f' ||
				str[i] == '\r' || str[i] == '\n' || str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		flag *= -1;
		i++;
	}
	while (str[i] != '\0' && str[i] > 47 && str[i] < 58)
	{
		value = value * 10 + str[i] - '0';
		i++;
	}
	return (flag * value);
}
