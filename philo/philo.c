/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkul <tkul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 02:57:39 by tkul              #+#    #+#             */
/*   Updated: 2024/07/28 20:04:19 by tkul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (ft_is_full_digit(av[i]) == 1)
			return (write(2, "Error: Invalid argument\n", 24), 1);
		i++;
	}
	if (av[5] != NULL)
	{
		if (ft_atoi(av[5]) < 1)
			return (write(2, "Error: Invalid argument\n", 24), 1);
		if (ft_atoi(av[5]) == -1)
			return (write(2, "Error: Invalid argument\n", 24), 1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (ac < 5 || ac > 6)
		return (write(2, "Error: Invalid count argumans\n", 30), 1);
	if (check_args(av) == 1)
		return (free(data), 1);
	if (init_data(data, av))
		return (destroy_all(data), 1);
	if (init_forks(data))
		return (destroy_all(data), 1);
	if (init_philo(data))
		return (destroy_all(data), 1);
	if (thread_create(data))
		return (destroy_all(data), 1);
	if (destroy_all(data))
		return (1);
	return (0);
}
