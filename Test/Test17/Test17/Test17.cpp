#include <string>
#include <vector>

using namespace std;

vector<int> fold(vector<int> _bill)
{
    if (_bill[0] > _bill[1])
    {
        _bill[0] /= 2;
        return _bill;
    }
    else
    {
        _bill[1] /= 2;
        return _bill;
    }
}

int solution(vector<int> wallet, vector<int> bill)
{
    int answer = 0;

    for (int i = 0; i < 100; i++)
    {
        if (wallet[0] < bill[0] && wallet[0] < bill[1])
        {
            bill = fold(bill);
            answer += 1;
        }
        if (wallet[1] < bill[0] && wallet[1] < bill[1])
        {
            bill = fold(bill);
            answer += 1;
        }
        if (bill[0] > wallet[0] && bill[0] > wallet[1])
        {
            bill = fold(bill);
            answer += 1;
        }
        if (bill[1] > wallet[0] && bill[1] > wallet[1])
        {
            bill = fold(bill);
            answer += 1;
        }

        //else
        //{
        //     return answer;
        //}
    }

    return answer;
}

int main()
{
    vector<int> _wallet = { 50,10 };
    vector<int> _bill = { 11,51 }; //11 25  11 12
    // 50,10  11,51
    int an = solution(_wallet, _bill);
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
