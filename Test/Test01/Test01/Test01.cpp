// Test01.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 나의 풀이
bool solution(bool x1, bool x2, bool x3, bool x4)
{
    bool answer = true;
    bool A = false;
    bool B = false;
    //(x1 ∨ x2) ∧ (x3 ∨ x4)   { ∨논리합 == || }  { ∧논리곱 == && }
    if (x1 == true || x2 == true)
    {
        A = true;
    }
    if (x3 == true || x4 == true)
    {
        B = true;
    }

    if (A == true && B == true)
    {
        answer = true;
    }
    else 
    {
        answer = false;
    }
    
    return answer;
}

// 효율적인 풀이
bool solution2(bool x1, bool x2, bool x3, bool x4)
{
    bool answer = true;
    answer  = (x1 || x2) && (x3 || x4);
    return answer;
}

int main()
{
   bool result = true;
   result = solution(true, false, false, false);
   std::cout <<"정답은? "<< result;
   
}

