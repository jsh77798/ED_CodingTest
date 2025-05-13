// Test03.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <string>
#include <iostream>

using namespace std; // 

string NewF()
{
    string Nstr = "ABC";
    //cin >> Nstr;
    for (int i = 0; i < Nstr.size(); i++)
    {
        if ('A' <= Nstr[i] && Nstr[i] <= 'Z')  //" " -> const char[상수char],  ' ' -> char[변수char] //상수는 처음 선언할 때만 값을 할당할 수 있고, 그 다음부터는 값을 바꿀 수 없다.    
        {
            Nstr[i] += 32;
        }
        else
        {
            Nstr[i] -= 32;
        }
    }

    return Nstr;
}


int main()
{
    
    //std::string str = "ABC";  <- main함수 위에 네임스페이스std를 쓰면 아래처럼 std::를 생략하고 코드를 칠 수 있다
    string str = "ABC";

   cout << "Origin " << str << endl;
    for (int i = 0; i < str.size(); i++) 
    {
        if ('a' <= str[i] && str[i] <= 'Z') {
            str[i] += 32;
        }
    }

   cout << "Change " << str << endl;


   string Newstr = NewF();
   cout << "NewChange " << Newstr << endl;
   cout << "NewChange1 ";
   return 0;
}


