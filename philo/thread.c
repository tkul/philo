/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkul <tkul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 22:50:37 by tkul              #+#    #+#             */
/*   Updated: 2024/07/28 23:20:18 by tkul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_is_dead(t_data *data)
{
	int			i;
	long int	t;

	i = 0;
	pthread_mutex_lock(data->death_mutex);
	while (i < data->philo_count)
	{
		t = get_time();
		if (!data->philo[i]->am_i_full
			&& t - data->philo[i]->last_eat > data->time_to_die)
		{
			data->is_someone_died = 1;
			printf ("%ld %d %s\n", t - data->philo[i]->last_eat,
				data->philo[i]->id, "is died");
			return (pthread_mutex_unlock(data->death_mutex), 1);
		}
		i++;
	}
	pthread_mutex_unlock(data->death_mutex);
	return (0);
}

void	*routine(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	while (1)
	{
		if (ft_eat(philo))
			break ;
		if (ft_sleep(philo))
			break ;
		if (ft_think(philo))
			break ;
	}
	return (NULL);
}

int	ft_is_everyone_full(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_lock(data->death_mutex);
	while (i < data->philo_count)
	{
		if (data->philo[i]->am_i_full == 0)
		{
			pthread_mutex_unlock(data->death_mutex);
			return (0);
		}
		i++;
	}
	pthread_mutex_unlock(data->death_mutex);
	return (1);
}

int	thread_create(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_count)
	{
		data->philo[i]->last_eat = data->start_time;
		pthread_create(&data->philo[i]->thread, NULL, routine, data->philo[i]);
	}
	while (1)
	{
		if (ft_is_dead(data) || ft_is_everyone_full(data))
			break ;
	}
	i = -1;
	while (++i < data->philo_count)
		pthread_join(data->philo[i]->thread, NULL);
	return (0);
}
