// Test12.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
using namespace std;

// 나의해설
int solution(int a, int b)
{
    int answer = 0;
    string A = to_string(a);
    string B = to_string(b);
    string _Ans1 = A;
    string _Ans2 = B;

    int an = 2 * a * b;

    _Ans1 += B;
    _Ans2 += A;
    a = stoi(_Ans1);
    b = stoi(_Ans2);
    if (a == b)
    {
        answer += a;
    }
    else
    {
        if (a < b)
        {
            answer += b;
        }
        else
        {
            answer += a;
        }
    }

    return answer;
}

// 다른해설
int solution2(int a, int b) 
{
    return max(stoi(to_string(a) + to_string(b)), stoi(to_string(b) + to_string(a)));
}

// 다른해설
int solution3(int a, int b) 
{
    int answer = 0;
    string str1, str2;
    str1 += to_string(a);
    str1 += to_string(b);
    str2 += to_string(b);
    str2 += to_string(a);
    
    if (str1.compare(str2) > 0) 
    { 
        answer = stoi(str1); 
    }
    else 
    {
        answer = stoi(str2);
    }
    return answer;
}

int main()
{
    solution(2, 3);
    solution2(2, 3);
    solution3(2, 3);

    std::cout << "Hello World!\n";
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
