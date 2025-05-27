#include "multiThread.h"
#include <stdio.h>

Player players[4];

// 실제 구현되는 스레드 작업
void* print_message(void* arg) 
{
    printf("%s\n", (char*)arg);
    return NULL;
}

void* player_IO(void* arg) // 플레이어 입출력을 관리하는 스레드
{
    Player *player = (Player *)arg; // 다시 player 타입 구조체로 캐스팅
    int temp_act;

    if(player->is_myturn == true)
    {
        printf("행동을 선택해주세요.\n");
        printf("공격: 1, 회복: 2, 방어: 3.\n");
        scanf("%d", &temp_act);

        while(!(temp_act > 0, temp_act < 4))
        {
            printf("행동을 선택해주세요.\n");
            printf("공격: 1, 회복: 2, 방어: 3.\n");
            scanf("%d", &temp_act);
        }

        
    }
}

void* calculate(void* arg) // 플레이어 입력을 전달받아 게임 관련 계산을 진행하는 스레드
{

}

void cool_time(time_t last, Player player)
{
    time_t last = time(NULL);

    while(1)
    {
        time_t now = time(NULL); // 현재 시각 얻기
         if (difftime(now, last) >= 3.0) 
         {
            player.is_myturn = true;
         }
    }
}

void run_game(Player player) 
{
    pthread_t player_thread, calculate_thread;

    const char* msg1 = "스레드 1: 안녕하세요!";
    const char* msg2 = "스레드 2: 반갑습니다!";

    pthread_create(&player_thread, NULL, player_IO, (void*)&player);
    pthread_create(&calculate_thread, NULL, print_message, (void*)msg2);

    pthread_join(player_thread, NULL);
    pthread_join(calculate_thread, NULL);
}