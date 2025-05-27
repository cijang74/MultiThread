#ifndef MULTITHREAD_H
#define MULTITHREAD_H

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

// 함수 선언
void run_threads(void);

#endif // MULTITHREAD_H