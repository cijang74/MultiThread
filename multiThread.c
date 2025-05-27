#include "multiThread.h"
#include <stdio.h>

void* print_message(void* arg) {
    printf("%s\n", (char*)arg);
    return NULL;
}

void run_threads(void) {
    pthread_t t1, t2;
    const char* msg1 = "스레드 1: 안녕하세요!";
    const char* msg2 = "스레드 2: 반갑습니다!";

    pthread_create(&t1, NULL, print_message, (void*)msg1);
    pthread_create(&t2, NULL, print_message, (void*)msg2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
}