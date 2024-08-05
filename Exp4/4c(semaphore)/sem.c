#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>

int shared = 1; // shared variable
sem_t s;        // semaphore variable

void *fun1();
void *fun2();

int main() {
    sem_init(&s, 0, 1); // initialize semaphore variable

    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, fun1, NULL);
    pthread_create(&thread2, NULL, fun2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("\nFinal value of shared is %d\n", shared); // prints the last updated value of shared variable

    sem_destroy(&s); // destroy semaphore after use

    return 0;
}

void *fun1() {
    int x;
    printf("\nWe are in func1()\n");
    sem_wait(&s); // executes wait operation on semaphore s

    x = shared; // thread1 reads value of shared variable
    printf("\nThread1 reads the value as %d\n", x);

    x++; // thread1 increments its value
    printf("Local updation by Thread1: %d\n", x);
    sleep(1); // thread1 is preempted by thread 2

    shared = x; // thread one updates the value of shared variable
    printf("\nValue of shared variable updated by Thread1 is: %d\n", shared);

    sem_post(&s); // releases semaphore
}

void *fun2() {
    int y;
    printf("\nWe are in func2()\n");
    printf("\nfun2() is blocked until func1() executes\n");
    sem_wait(&s); // executes wait operation on semaphore s

    y = shared; // thread2 reads value of shared variable
    printf("\nFunc2() resumes its execution after func1()\n");
    printf("\nThread2 reads the value as %d\n", y);

    y--; // thread2 decrements its value
    printf("\nLocal updation by Thread2: %d\n", y);
    sleep(1); // thread2 is preempted by thread 1

    shared = y; // thread2 updates the value of shared variable
    printf("\nValue of shared variable updated by Thread2 is: %d\n", shared);

    sem_post(&s); // releases semaphore
}


/*
gcc sem.c -o sem -pthread -lrt
./sem
*/