// main.c
#include "multiThread.h"

int main() 
{
    int temp_PlayerID;

    print("당신의 플레이어 아이디를 입력하세요. (1~4까지 선택)");
    scanf("%d", &temp_PlayerID);

    while(!(temp_PlayerID > 0 && temp_PlayerID < 5))
    {
        print("올바른 플레이어 아이디를 입력하세요. (1~4까지 선택)");
        scanf("%d", &temp_PlayerID);
    }

    // 위에서 입력받은 플레이어 id를 기반으로 플레이어 초기화
    Player player; // 4개짜리 플레이어 구조체 배열 생성
    player.id = temp_PlayerID;
    player_init(player);

    run_game(player);
    return 0;
}

void player_init(Player player)
{
    player.atk = 5;
    player.hp = 20;
    player.is_dead = false;
    player.is_myturn = false;
}