
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    int start = 0, end = 0;
    sort(targets.begin(), targets.end());

    for (int i = 0; i < targets.size(); ++i) {
        if (targets[i][0] < end) {
            if (targets[i][1] < end) {
                end = targets[i][1];
            }

        }
        else {
            ++answer;
            start = targets[i][0];
            end = targets[i][1];
        }
    }
    return answer;
}

int main()
{
    // 10040000000000
    // 00300070000000
    // 00045000000000
    // 00040008000000
    // 0000500000012
    vector<vector<int>> targets = { {4, 5} ,{4, 8},{10, 14},{11, 13},{5, 12},{3, 7},{1, 4}};

    solution(targets);
}

