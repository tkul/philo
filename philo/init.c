/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkul <tkul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 22:51:48 by tkul              #+#    #+#             */
/*   Updated: 2024/07/21 17:03:44 by tkul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo(t_data *data)
{
	int	i;

	i = 0;
	data->philo = malloc(sizeof(t_philo *) * data->philo_count);
	if (!data->philo)
		return (1);
	while (i < data->philo_count)
	{
		data->philo[i] = malloc(sizeof(t_philo));
		if (!data->philo[i])
			return (1);
		data->philo[i]->id = i + 1;
		data->philo[i]->eat_count = 0;
		data->philo[i]->am_i_full = 0;
		data->philo[i]->last_eat = 0;
		data->philo[i]->data = data;
		data->philo[i]->left_fork = data->forks[i];
		data->philo[i]->right_fork = data->forks[(i + 1) % data->philo_count];
		i++;
	}
	return (0);
}

int	init_forks(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t *) * data->philo_count);
	if (!data->forks)
		return (1);
	while (i < data->philo_count)
	{
		data->forks[i] = malloc(sizeof(pthread_mutex_t));
		if (!data->forks[i])
			return (1);
		pthread_mutex_init(data->forks[i], NULL);
		i++;
	}
	data->death_mutex = malloc(sizeof(pthread_mutex_t));
	if (!data->death_mutex)
		return (1);
	pthread_mutex_init(data->death_mutex, NULL);
	return (0);
}

int	init_data(t_data *data, char **av)
{
	data->philo_count = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		data->nb_philo_must_eat = ft_atoi(av[5]);
	else
		data->nb_philo_must_eat = -1;
	data->is_someone_died = 0;
	data->start_time = get_time();
	return (0);
}
