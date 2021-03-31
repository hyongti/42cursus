**세 가지 다른 프로그램을 작성해야 한다.** 기본 규칙은 다음과 같다.
- C로 작성(Norm에 따라). 누수나 충돌, 정의되지 않은 행동이 있으면 0점
- 테이블에 둘러앉은 철학자는 다음 세 가지 행동 중 한가지를 함:
	먹기, 생각하기, 잠자기
- 먹는 동안에는 생각하거나 잠을 자지 않는다. 생각하는 동안, 잠자는 동안에도 다른 두 가지 일을 하지 않는다.
- 테이블 중앙에는 스파게티가 담긴 커다란 그릇이 있다.
- 테이블 위에는 포크도 몇개 있다.
- 스파게티는 포크 하나로 덜거나 먹기 힘들기 때문에 철학자는 양손에 포크 하나씩, 총 두개의 포크로 스파게티를 먹어야 한다.
- 철학자는 배가 고프면 안 된다.
- 그래서 모든 철학자는 먹어야 한다.
- 철학자는 서로 이야기하지 않는다.
- 철학자는 다른 철학자가 죽어가는 것을 모른다.
- 철학자는 먹을 때마다 포크를 내려놓고 잠에 든다.
- 철학자 한명이 죽으면 상황은 종료된다.
- 각각의 프로그램은 같은 옵션들을 갖게 된다 : number_of_philosohpers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
 	
    - number_of_philosohpers 는 철학자의 숫자이자 포크의 개수
    - time_to_die는 밀리초(0.001초 단위)로, 만약 철학자가 먹고 있지 않다면 철학자는 식사를 하지 않게 된 시점부터 'time_to_die'밀리초 후에 죽는다.
    - time_to_eat 역시 밀리초 단위로, 철학자가 먹는 데에 소요된 시간. 이 시간동안 철학자는 두 개의 포크를 가지고 있게 된다.
    - time_to_sleep 역시 밀리초 단위. 철학자가 잠들어있는 시간.
    - number_of_times_each_philosopher_must_eat은 선택사항으로, 모든 철학자가 최소한 'number_of_times_each_philosopher_must_eat'번만큼 먹으면 상황이 종료된다. 이 옵션이 없다면 철학자가 죽어야 상황이 종료된다.
- 철학자는 1번부터 'number_of_philosohpers'만큼의 번호를 부여받는다.
- 1번 철학자 옆에는 'number_of_philosohpers'번 철학자가 앉아있다. N번 철학자는 N-1번과 N+1번 사이에 앉아있다.
- 철학자의 상태가 변하면 다음과 같이 출력돼야 한다.
    - timestamp_in_ms X has taken a fork
    - timestamp_in_ms X is eating
    - timestamp_in_ms X is sleeping
    - timestamp_in_ms X is thinking
    - timestamp_in_ms X died
    (X는 철학자 번호, timestamp_in_ms는 밀리초 단위로 나타낸 시간)
- 철학자 상태가 출력될 때 문장들이 서로 섞이면 안 된다.
- 철학자의 죽음과 그 죽음을 출력하는 사이는 10밀리초가 넘어가면 안 된다.
- 다시 한 번, 철학자는 죽으면 안 된다!

 | Program name	 | philo_one |
 | :----- | ----- |
 | Turn in files | philo_one/ |
 | Arguments | number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat] |
 | External functs. | memset, printf, malloc, free, write, usleep, gettimeofday, pthread_create, pthread_detach, pthread_join, pthread_mutex_init, pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock |
 | libft authorized | No |
 | Description | philosopher with threads and mutex |
 
 이 버전에서의 규칙은 다음과 같다.
 - 철학자들 사이에 하나씩 포크가 있다, 다시 말해 모든 철학자의 왼쪽과 오른쪽에 포크가 한 개씩 있다.
 - 철학자가 동시에 같은 포크를 사용하지 않게 하기 위해, 뮤텍스로 포크를 보호해야 한다.
 - 각각의 철학자가 하나의 쓰레드이다.
 
 
 |  Program name | philo_two |
 | :----- | ----- |
 | Turn in files | philo_two/ |
 | Arguments | number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat] |
 | External functs. | memset, printf, malloc, free, write, fork, kill, exit, pthread_create, pthread_detach, pthread_join, usleep, gettimeofday, waitpid, sem_open, sem_close, sem_post, sem_wait, sem_unlink |
 | libft authorized | No |
 | Description | philosopher with processes and semaphore |
 이 버전에서의 규칙은 다음과 같다.
- 모든 포크는 테이블 중앙에 있다.
- 포크의 수는 세마포어로 표시된다(They have no states in memory but the number of available forks is represented by a semaphore).
- 각각의 철학자가 하나의 쓰레드이다.

 | Program name | philo_three |
 | :----- | ----- |
 | Turn in files | philo_three/ |
 | Arguments | number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat] |
 | External functs. | memset, printf, malloc, free, write, fork, kill, exit, pthread_create, pthread_detach, pthread_join, usleep, gettimeofday, waitpid, sem_open, sem_close, sem_post, sem_wait, sem_unlink |
 | libft authorized | No |
 | Description | philosopher with processes and semaphore |
 이 버전에서의 규칙은 다음과 같다.
 - 모든 포크는 테이블 중앙에 있다.
 - 포크의 수는 세마포어로 표시된다(They have no states in memory but the number of available forks is represented by a semaphore).
 - 각각의 철학자가 하나의 프로세스이고, 메인 프로세스는 철학자가 아니다.