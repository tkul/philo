/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tugcekul <tugcekul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 22:50:26 by tkul              #+#    #+#             */
/*   Updated: 2024/07/31 00:08:35 by tugcekul         ###   ########.fr       */
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
	if (data->death_mutex)
		pthread_mutex_destroy(data->death_mutex);
	if (data->death_mutex)
		free(data->death_mutex);
	if (data)
		free(data);
	return (0);
}
