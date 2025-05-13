
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    priority_queue<int, std::vector<int>, std::greater<int>> hall_of_fame;
    for (int i = 0; i < score.size(); i++) {
        if (k == hall_of_fame.size()) {
            hall_of_fame.push(score[i]);
            hall_of_fame.pop();
        }
        else {
            hall_of_fame.push(score[i]);
        }
        answer.push_back(hall_of_fame.top());
    }
    return answer;
}

int main()
{
    vector<int> _score = { 10, 100, 20, 150, 1, 100, 200 };
    solution(3, _score);
}