#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int maxhealth = health, time = 0;
    for (int i = 0; i < attacks.size(); i++) {
        int dTime = attacks[i][0];
        int damage = attacks[i][1];
        int diff = dTime - time - 1;
        health += diff * bandage[1] + diff / bandage[0] * bandage[2];
        if (health > maxhealth) health = maxhealth;
        health -= damage;
        time = dTime;
        if (health <= 0) break;
    }
    return health <= 0 ? -1 : health;
}

int main()
{
    vector<int> _bandage = { 5, 1, 5 }; //시전시간, 1초당 회복량, 추가 회복량
    int _health = 30; //최대체력
    vector<vector<int>> _attacks = { {2, 10},{9, 15},{10, 5},{11, 5} }; //공격시간, 피해량

    int an = solution(_bandage, _health, _attacks);
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
