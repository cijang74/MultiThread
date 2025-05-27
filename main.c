#ifdef __linux__
#include <pthread.h>
#else
// 더미 타입 선언
typedef int pthread_t;
typedef int pthread_attr_t;
typedef int pthread_mutex_t;
typedef int pthread_mutexattr_t;

// 더미 함수 선언
static inline int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                                void *(*start_routine)(void*), void *arg) { return 0; }
static inline int pthread_join(pthread_t thread, void **retval) { return 0; }
static inline int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr) { return 0; }
static inline int pthread_mutex_lock(pthread_mutex_t *mutex) { return 0; }
static inline int pthread_mutex_unlock(pthread_mutex_t *mutex) { return 0; }
static inline int pthread_mutex_destroy(pthread_mutex_t *mutex) { return 0; }
#endif

#include <stdio.h>
#include <stdlib.h>

// 스레드에서 실행할 함수
void* print_message(void* message) {
    printf("%s\n", (char*)message);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    const char* message1 = "스레드 1: 안녕하세요!";
    const char* message2 = "스레드 2: 반갑습니다!";

    // 스레드 생성
    pthread_create(&thread1, NULL, print_message, (void*)message1);
    pthread_create(&thread2, NULL, print_message, (void*)message2);

    // 스레드 종료 대기
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("메인 스레드 종료\n");
    return 0;
}