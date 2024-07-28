/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkul <tkul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 23:46:14 by tkul              #+#    #+#             */
/*   Updated: 2024/07/22 02:24:21 by tkul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	right_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	if (print_status(philo, "has taken a right fork"))
		return (pthread_mutex_unlock(philo->right_fork), 1);
	if (philo->left_fork == philo->right_fork)
		return (pthread_mutex_unlock(philo->right_fork), 1);
	pthread_mutex_lock(philo->left_fork);
	if (print_status(philo, "has taken a left fork"))
		return (pthread_mutex_unlock(philo->right_fork),
			pthread_mutex_unlock (philo->left_fork), 1);
	return (0);
}

int	left_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	if (print_status(philo, "has taken a left fork"))
		return (pthread_mutex_unlock(philo->left_fork), 1);
	if (philo->left_fork == philo->right_fork)
		return (pthread_mutex_unlock(philo->left_fork), 1);
	pthread_mutex_lock(philo->right_fork);
	if (print_status(philo, "has taken a right fork"))
		return (pthread_mutex_unlock (philo->right_fork),
			pthread_mutex_unlock (philo->left_fork), 1);
	return (0);
}

int	ft_eat(t_philo *philo)
{
	if (philo->id % 2 != 0 && right_fork(philo))
		return (1);
	else if (philo->id % 2 == 0 && left_fork(philo))
		return (1);
	if (print_status(philo, "is eating"))
		return (pthread_mutex_unlock(philo->right_fork),
			pthread_mutex_unlock(philo->left_fork), 1);
	philo->last_eat = get_time();
	ft_usleep(philo->data->time_to_eat);
	philo->eat_count++;
	if (philo->eat_count == philo->data->nb_philo_must_eat)
		philo->am_i_full = 1;
	if (philo->data->nb_philo_must_eat != -1)
	{
		if (philo->am_i_full == 1)
			return (pthread_mutex_unlock(philo->right_fork),
				pthread_mutex_unlock(philo->left_fork), 1);
	}
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	return (0);
}

int	ft_think(t_philo *philo)
{
	if (print_status(philo, "is thinking"))
		return (1);
	return (0);
}

int	ft_sleep(t_philo *philo)
{
	if (print_status(philo, "is sleeping"))
		return (1);
	ft_usleep(philo->data->time_to_sleep);
	return (0);
}
