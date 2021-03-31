#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
 
int				g_num;

typedef struct			s_philosopher
{
	char				*s;
	pthread_mutex_t		*fork;
}						t_philosopher;


// 쓰레드 함수
void *t_function(void *philosopher)
{
	pid_t			pid;// process id
	pthread_t		tid;// thread id
 
	pid = getpid();
	tid = pthread_self();
 
	char* thread_name = ((t_philosopher *)philosopher)->s;
	int i = 0;
 
	pthread_mutex_lock(((t_philosopher *)philosopher)->fork);

	while (i<3)   // 0,1,2 까지만 loop 돌립니다.
	{
		// 넘겨받은 쓰레드 이름과 
		// 현재 process id 와 thread id 를 함께 출력
		printf("[%s] pid:%u, tid:%x --- %d --- g_num : %d\n", 
			thread_name, (unsigned int)pid, (unsigned int)tid, i, g_num++);
		i++;
		usleep(100);
	}

	pthread_mutex_unlock(((t_philosopher *)philosopher)->fork);
}
 
int main()
{
	pthread_t		p_thread[2];
	pthread_mutex_t	mutex_lock;
	int				thr_id;
	int				status;
	char p1[] = "thread_1";   // 1번 쓰레드 이름
	char p2[] = "thread_2";   // 2번 쓰레드 이름
	char pM[] = "thread_m";   // 메인 쓰레드 이름
	g_num = 0;
	
	t_philosopher	philosopher1;
	t_philosopher	philosopher2;

	philosopher1.s = p1;
	philosopher1.fork = &mutex_lock;
	philosopher2.s = p2;
	philosopher2.fork = &mutex_lock;

	pthread_mutex_init(&mutex_lock, NULL);

	sleep(1);  // 2초 대기후 쓰레드 생성


	// ① 1번 쓰레드 생성
	// 쓰레드 생성시 함수는 t_function
	// t_function 의 매개변수로 p1 을 넘긴다.  
	pthread_create(&p_thread[0], NULL, t_function, (void *)&philosopher1);
	pthread_create(&p_thread[1], NULL, t_function, (void *)&philosopher2);
		// ③ main() 함수에서도 쓰레드에서 돌아가고 있는 동일한 함수 실행
	// t_function((void *)pM);

	// 쓰레드 종료를 기다린다. 
	pthread_join(p_thread[0], (void **)&status);
	pthread_join(p_thread[1], (void **)&status);
 
	printf("언제 종료 될까요?\n");
 
	return 0;
}
