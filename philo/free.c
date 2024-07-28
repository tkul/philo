/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkul <tkul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 22:50:26 by tkul              #+#    #+#             */
/*   Updated: 2024/07/19 23:36:39 by tkul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	destroy_all(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
	{
		pthread_mutex_destroy(data->forks[i]);
		free(data->forks[i]);
		free(data->philo[i]);
		i++;
	}
	if (data->forks)
		free(data->forks);
	if (data->philo)
		free(data->philo);
	pthread_mutex_destroy(data->death_mutex);
	if (data->death_mutex)
		free(data->death_mutex);
	if (data)
		free(data);
	return (0);
}
