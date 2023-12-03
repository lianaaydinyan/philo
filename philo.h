#ifndef PHILO_H
 #define PHILO_H


#include  <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"
#include <sys/time.h>

typedef struct s_philo t_philo;
typedef struct s_data t_data;


struct s_philo
{
	long			time_to_eat;
	long			time_to_sleep;
	long			time_to_die;
	int				rigth_fork;
	int				left_fork;
	int				eat_count;
	long			def_all_eat;
	long			last_meal;
	int				id;
	int				dead_flag;
	pthread_mutex_t	lock;

	t_data			*global_data;
};

struct s_data
{
	int				num_of_philos;
	t_philo			philos[200];
	pthread_mutex_t print;
	pthread_mutex_t	*forkk;
	pthread_mutex_t	died_mtx;//////
	pthread_t thread_id[200];
	long long		program_start;
	t_philo			*global_philos;
};




long long get_current_time(t_data *data);
int	ft_usleep(long long milliseconds,t_data *data);
void	createMutexs(t_data *data);

#endif
