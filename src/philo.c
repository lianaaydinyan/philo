#include "../philo.h"
#include <assert.h>


long long get_current_time2(void);

int	arg_error(void)
{
	printf("wrong count of arguments");
	return(0);
}

int _isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int have_to_be_num(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if(!(_isdigit(str[i])))
			return (0);
		i++;
	}
	return (1);
}

void fillTheData(t_data *data)
{
	int i;
	int tmp;

	i = 0;
	tmp = 0;
	while(i < (data)->num_of_philos)
	{
		if (i == 0)
		{
			data->philos[i].rigth_fork = (data)->num_of_philos - 1;
			data->philos[i].left_fork = i;
		}
		else 
		{
			data->philos[i].left_fork = tmp;
			data->philos[i].rigth_fork = tmp - 1;
		}
		i++;
		tmp++;
	}
}


void	philo_printf(t_data *data, char *str, int a)
{
	pthread_mutex_lock(&data->print);
	printf("Time[%lld] %d -> %s ",get_current_time(data), a, str);
	pthread_mutex_unlock(&data->print) ;
}


void	*thread_function(void *arg)
{
	t_philo *philo = (t_philo *)arg;
	t_data *data;

	data = philo->global_data;
	if(philo->id % 2 == 0)
		usleep(1000);
	while((philo->dead_flag) == 0)
	{
		pthread_mutex_lock(&data->forkk[philo->rigth_fork]);
		philo_printf(data,"Philos take the rigth fork\n",philo->id);
		pthread_mutex_lock(&data->forkk[philo->left_fork]);
		philo_printf(data,"Philos take the left fork\n",philo->id);
		philo_printf(data,"Is eating\n",philo->id);
		ft_usleep(data->philos->time_to_eat, data);
		pthread_mutex_unlock(&data->forkk[philo->rigth_fork]);
		pthread_mutex_unlock(&data->forkk[philo->left_fork]);
		pthread_mutex_lock(&philo->lock);
		// philo->eat_count +=1;
		philo->last_meal = get_current_time(data);
		pthread_mutex_unlock(&philo->lock);
		philo_printf(data,"Is sleeping\n",philo->id);
		ft_usleep(data->philos->time_to_sleep,data);
		philo_printf(data,"Is thinking\n",philo->id);
		usleep(200);
	}
	return (NULL);
}

void	destroy_and_detach(t_data *data)
{
	int	i;

	i = -1;
	while(++i < data->num_of_philos){
		pthread_mutex_destroy(&data->forkk[i]);
	}
	pthread_mutex_destroy(&data->print);
}

int	starving_check(t_data *data)
{
	int i;
	// t_data *data;

	i = 0;
	// data = philos->global_data;
	while (i < data->num_of_philos)
	{
		if((long)get_current_time(data) - data->philos[i].last_meal  > data->philos[i].time_to_die)
		{
			pthread_mutex_unlock(&data->philos[i].lock);
			philo_printf(data, "Is dead\n" , data->philos[i].id);
			data->philos[i].dead_flag = 1;
			pthread_mutex_unlock(&data->philos[i].lock);
			return (0);
		}
		i++;
	}
	return (1);
}


int	createThreads(t_data *data)
{
	int i;
	
	i = 0;
	while (i < data->num_of_philos)
	{
		if (pthread_create(&data->thread_id[i], NULL, thread_function, (&data->philos[i])) != 0)
			return (0);
		i++;
	}
	printf("cuteeeeeeeeeeeeeee\n");
	i = 0;
	while(1)
	{
		if(!starving_check(data))
			break;
	}
	while(i < data->num_of_philos)
	{
		pthread_join(data->thread_id[i], NULL);
		i++;
	}
		printf("niceeeeeeeeeeeeeeeeeeeeeeeeeee\n");

	return (1);
}

void	allocation_error(void)
{
	printf("Allocation went wrong !\n");
	return ;
}
void	createMutexs(t_data *data)
{
	int i;

	i = 0;
	data->forkk = (pthread_mutex_t *)malloc(sizeof (pthread_mutex_t) * data->num_of_philos);
	while(i < data->num_of_philos)
	{
		if(pthread_mutex_init(&data->forkk[i], NULL) != 0)
			perror("error\n");
		if(pthread_mutex_init(&data->philos[i].lock, NULL) != 0)
			perror("error\n");
		i++;
	}
	// data->forkk = (pthread_mutex_t *)malloc(sizeof (pthread_mutex_t) * data->num_of_philos);
	if (pthread_mutex_init(&(data)->print, NULL) != 0)
		perror("error\n");
	if (pthread_mutex_init(&(data)->died_mtx, NULL) != 0)
		perror("error\n");
}

long long	diff(long long num1, long long num2)
{
	return(num1 - num2);
}

// int	get_died_flag(t_data *data)
// {
// 	int	gh;

// 	pthread_mutex_lock(&(data->died_mtx));
// 	gh = data->global_philos->dead_flag;
// 	pthread_mutex_unlock(&(data->died_mtx));
// 	return (gh);
// }

int	ft_usleep(long long milliseconds,t_data *data)
{
	long long	start;

	start = get_current_time2();
	//printf("\n[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[ %lld\n",start);
	while (data->global_philos->dead_flag)
	{
		if (diff(get_current_time2(), start) >= milliseconds)
			break;
		usleep(10);
	}
	return (0);
}


long long get_current_time2(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		perror("gettimeofday() error\n");
	return (time.tv_usec * 1000 + time.tv_sec / 1000);
}

long long get_current_time(t_data *data)
{
	struct timeval	time;
	(void)data;
	static int count;
	static long long start;

	gettimeofday(&time, NULL);
	if (count == 0)
	{
		start = time.tv_sec * 1000 + time.tv_usec / 1000;
		count++;
	}
	return (((time.tv_sec * 1000 + time.tv_usec / 1000) - start));
}


int	GiveTheArgs(int ac,char  **av, t_data *data)
{
	int i;

	i = 0;
	while(i < ac)
	{
		if(i == 1)
			(data)->num_of_philos = ft_atoi(av[i]);
		else if (i == 2)
			(data)->philos[i].time_to_die = ft_atoi(av[i]);
		else if (i == 3)
			(data)->philos[i].time_to_eat = ft_atoi(av[i]);
		else if(i == 4)
			(data)->philos[i].time_to_sleep = ft_atoi(av[i]);
		else if(i == 5)
			(data)->philos[i].def_all_eat = ft_atoi(av[i]);
		i++;
	}
	for (int i = 0; i < (data)->num_of_philos; i++) 
	{
		(data)->philos[i].eat_count = 0;
		(data)->philos[i].left_fork = 0;
		(data)->philos[i].rigth_fork = 0;
		(data)->philos[i].global_data = data;
		(data)->philos[i].id = i;
		(data)->philos[i].dead_flag = 0;
		(data)->philos[i].last_meal = 0;
	}
	data->program_start = get_current_time2();
	fillTheData(data);
	printf("dasdsadasdsadasd\n");
	createMutexs(data);
	printf("Awwwwwwwwwwwwwwwwwwwww\n");
	if (createThreads(data) == -1)
		return (-1);
	else
		return (1);
}

void	errorCase(void)
{
	perror("Can't be more than 200 philos\n");
	exit(0);
}

int parsing(int ac, char **av)
{
	int i;
	int k;

	i = 1;
	k = 1;
	if(ac < 5 || ac > 6)
		return(arg_error());
	while(av[i])
	{
		if(!have_to_be_num(av[i]))
			return(0);
		i++;
	}
	if (ft_atoi(av[1]) > 200) 
		errorCase();
	while(av[k])
	{
		if((ft_atoi(av[k])) <= 0)
			return (0);
		k++;
	}
	return (1);
}

int main(int ac, char **av)
{
	t_data data;
	(void)ac;
	(void)av;
	get_current_time(&data);
	if(parsing(ac, av))
	{
		if(!(GiveTheArgs(ac, av, &data)))
			exit(-1);
	}
	else
		printf("Thread has finished.\n");
	return 0;
}
