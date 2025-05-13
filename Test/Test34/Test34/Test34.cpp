
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(string s) {
    int answer = 0;
    queue<char> q_s;
    int same = 0, different = 0;
    for (char c : s) {
        q_s.push(c);
    }

    for (char c : s) {
        if (q_s.front() == c) {
            same++;
        }
        else {
            different++;
        }

        if (same == different) {
            int popidx = same + different;
            for (int i = 0; i < popidx; i++) {
                if (!q_s.empty()) {
                    q_s.pop();
                }
            }
            same = 0, different = 0;
            answer++;
        }
    }
    if (!q_s.empty()) {
        answer++;
    }
    return answer;
}

int main()
{
    solution("banana");
}

