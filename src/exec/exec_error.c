/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 07:42:36 by lboulatr          #+#    #+#             */
/*   Updated: 2023/09/09 12:42:40 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	display_error(char *str)
{
	ft_putstr_fd("\033[41m", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd("\033[0m", STDERR_FILENO);
}
