#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int counter = 0;
sem_t sem;

void *increment(void *arg)
{
    sem_wait(&sem);

    counter++;

    sem_post(&sem);

    return NULL;
}

int main()
{
    pthread_t t1,t2,t3,t4;

    sem_init(&sem,0,1);

    pthread_create(&t1,NULL,increment,NULL);
    pthread_create(&t2,NULL,increment,NULL);
    pthread_create(&t3,NULL,increment,NULL);
    pthread_create(&t4,NULL,increment,NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);
    pthread_join(t4,NULL);

    printf("Counter = %d\n",counter);

    sem_destroy(&sem);

    return 0;
}
