// Test09.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 내 해결법
string solution(string str1, string str2)
{
    int s1 = 0;
    int s2 = 0;
    string _answer = "";
    int length = str1.size();
    int length2 = str2.size();
    length += length2;

    _answer.append(length, 'a');
   
    

    for (int i = 0; i < length; i++)
    {
        if (i % 2 == 0)
        {
            _answer[i] = str1[s1];
            s1++;
        }
        else
        {
            _answer[i] = str2[s2];
            s2++;
        }
    }

    string answer = _answer;
    return answer;
}

// 다른 해결법
string solution2(string str1, string str2) 
{
    string answer = "";

    for (int i = 0; i < str1.length(); i++)
    {
        answer.push_back(str1[i]);
        answer.push_back(str2[i]);
    }
    return answer;
}

string solution22(vector<string> arr)
{
    string answer = "";
    for (int i = 0; i < arr.size(); i++)
    {
        answer += arr[i];
    }
    return answer;
}

int main()
{
    vector<string> Myarr;
    Myarr.push_back("a");
    Myarr.push_back("b");
    Myarr.push_back("c");

    //string answer = solution("aaaaa", "bbbbb");
    string answer2 = solution22(Myarr);
   // std::cout << "Hello World!\n" << answer;
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
