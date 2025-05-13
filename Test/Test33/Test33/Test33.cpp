
#include <string>
#include <vector>
#include <map>

using namespace std;

// 나의 풀이
vector<int> solution(string s) {
    vector<int> answer(s.size());
    for (int i = 1; i <= s.size(); i++) {   // 먼저 시작하고 끌난뒤에 i에 값을 올린다
        int nowidx = s.size() - i;
        int count = 0;

        for (int j = 1; j <= nowidx; j++) {
            if (s[nowidx] == s[nowidx - j]) {
                count += 1;
                answer[nowidx] = count;
                break;
            }
            else {
                count += 1;
            }
        }
        if (answer[nowidx] == NULL) {
            answer[nowidx] = -1;
        }
    }
    return answer;
}

// 다른 풀이
vector<int> solution2(string s)
{
    map<char, int> mp;
    vector<int> answer;
    for (int i = 0; i < s.size(); ++i) // i에 값을 먼저 올리고 시작한다
    {
        if (mp.find(s[i]) != mp.end()) 
            answer.push_back(i - mp[s[i]]);
        else answer.push_back(-1);
        mp[s[i]] = i;
    }
    return answer;
}

int main()
{
    solution("banana");
    solution2("banana");
}
