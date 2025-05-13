// Test07.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

// 정수 홀수 구분문제
int main(void) 
{
    int n;
    cin >> n;

    cout << n << " is " << (n % 2 == 0 ? "even" : "odd");
    return 0;
}