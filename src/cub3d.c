/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:57:54 by croy              #+#    #+#             */
/*   Updated: 2023/09/09 13:53:00 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	(void) ac;
	(void) av;
	
	printf("We're in boys\n");
	
	char		*map =  "1111111111111\n1000000000111\n10000S0000011\n1000111000011\n1000000000001\n1111111111111";
	
	if (exec_manager(map) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
