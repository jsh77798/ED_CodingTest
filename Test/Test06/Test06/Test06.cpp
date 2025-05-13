

#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str; // 입력
    int length = str.size();
    for (size_t i = 0; i < str.size(); i++)
    {
        cout << str[i] << endl; // 출력
    }
    return 0;
}
