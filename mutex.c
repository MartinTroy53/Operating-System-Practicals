#include <stdio.h>
#include <pthread.h>

int counter = 0;
pthread_mutex_t mutex;

void *increment(void *arg)
{
     pthread_mutex_lock(&mutex);
     counter++;
     pthread_mutex_unlock(&mutex);
     return NULL;
}

int main()
{
     pthread_t t1, t2, t3, t4;
     pthread_mutex_init(&mutex, NULL);
     pthread_create(&t1, NULL, increment, NULL);
     pthread_create(&t2, NULL, increment, NULL);
     pthread_create(&t3, NULL, increment, NULL);
     pthread_create(&t4, NULL, increment, NULL);

     pthread_join(t1, NULL);
     pthread_join(t2, NULL);
     pthread_join(t3, NULL);
     pthread_join(t4, NULL);

     printf("final counter = %d\n", counter);
     pthread_mutex_destroy(&mutex);
     return 0;
}
