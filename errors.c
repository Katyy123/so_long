/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:15:40 by cfiliber          #+#    #+#             */
/*   Updated: 2021/11/30 18:47:08 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int error(char *message)
{
    printf("Error:\n%s\n", message);
    return (0);
}

void    *null_error(char *message)
{
    printf("Error:\n%s\n", message);
    return (NULL);
}

void    print_warning(char *message)
{
    printf("Warning:\n%s\n", message);
}
