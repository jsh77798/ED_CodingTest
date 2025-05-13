#include <string>
#include <vector>
#include <unordered_map>
//#include <utility>

using namespace std;

//알고리즘은 문제없으나 시간복잡성이 높음
vector<string> solution(vector<string> players, vector<string> callings) 
{
    vector<string> answer;

    for (int i = 0; i < callings.size(); i++) {
        for (int j = 0; j < players.size(); j++) {
            if (callings[i] == players[j]) {
                players[j] = players[j - 1];
                players[j - 1] = callings[i];
            }
        }
    }

    answer = players;
    return answer;
}

//정답 풀이 +위쪽에 풀이보다 시간복잡성이 낮음
vector<string> solution2(vector<string> players, vector<string> callings)
{
    vector<string> answer;
    unordered_map<string, int> player_to_idx;
    //플레이어 순위
    for (int i = 0; i < players.size(); i++)
    {
        player_to_idx[players[i]] = i;
    }

    for (int j = 0; j < callings.size(); j++) 
    {
        int idx = player_to_idx[callings[j]];
        string tmp = players[idx - 1];
        players[idx - 1] = players[idx];
        players[idx] = tmp;

        player_to_idx[players[idx]] = idx;
        player_to_idx[players[idx - 1]] = idx - 1;
    }
    
    
    answer = players;
    return answer;
}

int main()
{
    vector<string> _players = { "mumu", "soe", "poe", "kai", "mine" };
    vector<string> _callings = { "kai", "kai", "mine", "mine" };

    solution(_players, _callings);
    solution2(_players, _callings);
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
