/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chartable_linecount.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:49:48 by cfiliber          #+#    #+#             */
/*   Updated: 2021/11/25 18:50:07 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Returns the number of lines a 2D string table that ends in NULL
-> *chars*\0
-> *chars*\0
-> NULL 
Retunr value: 2 */
int	ft_chartable_linecount(char **table)
{
	int	count;

	count = 0;
	while (table[count])
		count++;
	return (count);
}

