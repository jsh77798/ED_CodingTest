
//문제
/*
연산 ⊕는 두 정수에 대한 연산으로 두 정수를 붙여서 쓴 값을 반환합니다.예를 들면 다음과 같습니다.

12 ⊕ 3 = 123
3 ⊕ 12 = 312
양의 정수 a와 b가 주어졌을 때, a ⊕ b와 2 * a * b 중 더 큰 값을 return하는 solution 함수를 완성해 주세요.

단, a ⊕ b와 2 * a * b가 같으면 a ⊕ b를 return 합니다.
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//나의 풀이
int solution01(int a, int b)
{
    int answer = 0;
    string SA, SB;
    SA = to_string(a);
    SB = to_string(b);

    SA += SB;
    int ans1 = stoi(SA);
    int ans2 = 2 * a * b;

    if (ans1 >= ans2)
    {
        answer = ans1;
    }
    else
    {
        answer = ans2;
    }
    return answer;
}

//다른풀이
int solution02(int a, int b)
{
    int answer = 0;
    string s = to_string(a) + to_string(b);
    answer = max(stoi(s), 2 * a * b);
    return answer;
}

int main() 
{
    solution01(91, 2);
    solution01(2, 91);

    solution02(91, 2);
    solution02(2, 91);
}