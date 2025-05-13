// Test08.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>


using namespace std;

// 내 정답
string solution(string my_string, string overwrite_string, int s)
{
    int len = my_string.size();
    int len2 = overwrite_string.size();
    int v = 0;
    for (int i = s; i <= len; i++)
    {
        if (len2 > v)
        {
            my_string[i] = overwrite_string[v];
            v++;
        }
    }

    string answer = my_string;
    return answer;
}

// 다른 정답
string solution2(string my_string, string overwrite_string, int s) 
{
    string answer = "";
    answer = my_string.replace(s, overwrite_string.size(), overwrite_string); 
    //replace 함수의 첫 번째 인자에는 바꿀 문자열의 시작 위치, 두 번째 인자에는 치환할 길이, 
    //마지막으로 세 번째 인자에는 치환할 문자열을 대입한다.
    return answer;
}

int main()
{
   

    solution("abc123", "222", 3);
    return 0;
}

