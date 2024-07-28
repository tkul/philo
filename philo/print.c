/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkul <tkul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 22:50:32 by tkul              #+#    #+#             */
/*   Updated: 2024/07/20 16:51:29 by tkul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_status(t_philo *philo, char *msg)
{
	pthread_mutex_lock(philo->data->death_mutex);
	if (philo->data->is_someone_died == 0)
	{
		printf ("%ld %d %s\n", get_time() - philo->data->start_time,
			philo->id, msg);
		pthread_mutex_unlock(philo->data->death_mutex);
		return (0);
	}
	pthread_mutex_unlock(philo->data->death_mutex);
	return (1);
}
