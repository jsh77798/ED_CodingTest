
#include <string>
#include <vector>
#include <map>

using namespace std;

//나의 풀이
string solution(string s, string skip, int index) {
    string answer = "";
    map<string, int> T_to_idx;
    for (char c : skip) {
        T_to_idx[string(1, c)] = int(c);
    }

    for (char c : s) {
        for (int i = 0; i < index; i++) {
            if (c != T_to_idx[string(1, c)]) {
                c += 1;
            }
            if (c == 123) {
                c = 97;
            }
            while (c == T_to_idx[string(1, c)])
            {
                c += 1;
                if (c == 123) {
                    c = 97;
                }
            }
        }
        answer.push_back(c);
    }

    return answer;
}

int main()
{
    //아스키 코드
    //97~122
    char a = 97;
    char b = 'b';
    char c = 'c';
    // ...
    char y = 'y';
    char z = 122;


    solution("y", "baz", 1);
}
