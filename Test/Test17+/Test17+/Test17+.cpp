#include <string>
#include <vector>
#include <algorithm> // <- sort 사용시 해당 헤더파일 필요
using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    // sort 함수는 배열의 요소를 정렬하는데 사용되는 함수다(요소를 오름차순 정렬한다)
    // ex) { 50,10 } -> sort함수 -> { 10,50 }
    sort(wallet.begin(), wallet.end());
    sort(bill.begin(), bill.end());
    while (wallet[0] < bill[0] || wallet[1] < bill[1])
    {
        bill[1] /= 2;
        if (bill[1] < bill[0])
        {
            int temp = bill[0];
            bill[0] = bill[1];
            bill[1] = temp;
        }
        answer++;
    }

    return answer;
}

int main()
{
    vector<int> _wallet = { 50,10 };
    vector<int> _bill = { 11,51 }; 
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
