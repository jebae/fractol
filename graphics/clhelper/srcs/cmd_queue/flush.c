/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flush.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:29:10 by jebae             #+#    #+#             */
/*   Updated: 2019/06/17 14:29:10 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clhelper.h"

int			clh_flush(cl_command_queue cmd_queue)
{
	cl_int		ret;

	ret = clFlush(cmd_queue);
	return (clh_check_flush(ret));
}
