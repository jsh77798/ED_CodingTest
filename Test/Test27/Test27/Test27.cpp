
#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int distance = 0;
    
    for (int i = 0; i < section.size(); i++) {
        if (section[i] <= distance) continue;

        distance = section[i] + m - 1;
        answer++;
    }

    return answer;
}

int solution2(int n, int m, vector<int> section) {
    int answer = 1;

    int pivot = section[0];
    for (const auto v : section)
    {
        if (v < pivot + m)
        {
            continue;
        }
        else
        {
            pivot = v;
            answer++;
        }
    }

    return answer;
}
int main()
{
    vector<int> _section = { 1, 4, 5};
    solution(5, 2, _section);
    solution2(5, 2, _section);
}
