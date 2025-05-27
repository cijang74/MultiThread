// multiThread.h
#ifndef MULTITHREAD_H
#define MULTITHREAD_H

#ifdef __linux__
#include <pthread.h>
#include <unistd.h>
#else
typedef int pthread_t;
typedef int pthread_mutex_t;
typedef int pthread_cond_t;
typedef int pthread_attr_t;
static inline int pthread_create(pthread_t *t,const pthread_attr_t*a,void*(*f)(void*),void*arg){return 0;}
static inline int pthread_join(pthread_t t,void**r){return 0;}
static inline int pthread_mutex_init(pthread_mutex_t*m,const void*a){return 0;}
static inline int pthread_mutex_lock(pthread_mutex_t*m){return 0;}
static inline int pthread_mutex_unlock(pthread_mutex_t*m){return 0;}
static inline int pthread_mutex_destroy(pthread_mutex_t*m){return 0;}
static inline int pthread_cond_init(pthread_cond_t*c,const void*a){return 0;}
static inline int pthread_cond_signal(pthread_cond_t*c){return 0;}
static inline int pthread_cond_wait(pthread_cond_t*c,pthread_mutex_t*m){return 0;}
static inline int pthread_cond_destroy(pthread_cond_t*c){return 0;}
#endif

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

// #define MAX_PLAYERS 4 // 최대 플레이어 수 일단 4명
// #define ACTION_QUEUE_SIZE 20 // 액션 큐 개수
// #define THREAD_POOL_SIZE 4 // 스레드풀 사이즈

// typedef enum { ATTACK, ITEM, DEFFENSE, BOSS_ATTACK } ActionType;
// typedef enum { HEAL, UPATK } ItemType;

// typedef struct Action // 액션 구조체
// {
//     bool is_player; // 현재 액션을 취하는 객체가 플레이어 or 보스
//     ActionType type; // 어떤 액션을 취할것인지 정보를 담은 구조체
//     int player_id; // 어떤 플레이어가 액션을 취하는지에 대한 정보가 담긴 변수
// } Action;

// typedef struct ActionQueue
// {
//     Action actions[ACTION_QUEUE_SIZE]; // 액션 큐 개수만큼의 배열 생성
//     int front, rear, count;
//     pthread_mutex_t mutex;
//     pthread_cond_t  not_empty;
// } ActionQueue;

// typedef struct Player
// {
//     int id;
//     int hp;
//     int atk;
//     bool is_myturn;
//     bool is_dead;
// } Player;

// typedef struct Item
// {
//     ItemType type;
//     int howMany_Item;
// } Item;

// typedef struct Boss
// {
//     int hp;
//     int atk;
//     int is_dead;
// } Boss;

// typedef struct GameState // 게임 상태를 체크하기위한 구조체
// {
//     Player players[MAX_PLAYERS];
//     Boss boss;
//     pthread_mutex_t state_mutex;
// } GameState;

// typedef struct ThreadCtx // 큐와 게임상태 구조체를 함께 보내기위해 만든 구조체
// {
//     ActionQueue *queue;
//     GameState   *state;
// } ThreadCtx;

// void init_queue(ActionQueue *q); // 큐 초기화
// void enqueue(ActionQueue *q, Action act); // 큐에 액션 삽입
// Action dequeue(ActionQueue *q); // 
// void* player_thread(void *arg);
// void* boss_thread(void *arg);
// void* calc_thread(void *arg);

// 함수 선언
void run_threads(void);

#endif // MULTITHREAD_H