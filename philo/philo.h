/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkul <tkul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 02:56:38 by tkul              #+#    #+#             */
/*   Updated: 2024/07/28 20:00:39 by tkul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>

# define INT_MAX 2147483647

typedef struct s_philo
{
	int				id;
	int				eat_count;
	int				am_i_full;
	long int		last_eat;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				philo_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_philo_must_eat;
	int				is_someone_died;
	pthread_mutex_t	*death_mutex;
	pthread_mutex_t	**forks;
	t_philo			**philo;
	long int		start_time;
}	t_data;

int			ft_atoi(const char *str);
int			ft_is_full_digit(char *str);
int			check_args(char **av);
int			init_philo(t_data *data);
int			init_forks(t_data *data);
int			init_data(t_data *data, char **av);
int			thread_create(t_data *data);
long int	get_time(void);
void		ft_usleep(long int time);
int			print_status(t_philo *philo, char *status);
int			ft_is_dead(t_data *philo);
int			ft_think(t_philo *philo);
int			ft_sleep(t_philo *philo);
int			ft_eat(t_philo *philo);
void		*routine(void *p);
int			is_all_ate(t_data *data);
void		t_print_status_eat(t_philo *philo, long t);
int			print_status(t_philo *philo, char *routine);
int			destroy_all(t_data *data);
int			left_fork(t_philo *philo);
int			right_fork(t_philo *philo);

#endif