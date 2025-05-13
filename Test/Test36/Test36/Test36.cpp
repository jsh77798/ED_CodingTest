
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 코드는 맞으나 시간초가로 보완필요
int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    int level = 1;
    while (true) {
        long long total_time = 0;
        for (int i = 0; i < diffs.size(); i++) {
            if (diffs[i] <= level) {
                total_time += times[i];
            }
            else {
                int wrong = diffs[i] - level;
                total_time += (times[i] + times[i - 1]) * wrong + times[i];
            }
        }
        if (total_time <= limit) {
            answer = level;
            break;
        }
        else {
            level++;
        }
    }
    return answer;
}

// 보완코드(이진탐색 이용)
int solution2(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    int left = 1;
    int right = *max_element(diffs.begin(), diffs.end());

    while (left <= right) {
        int level = (left + right) / 2;
        long long total_time = 0;
        for (int i = 0; i < diffs.size(); i++) {
            if (diffs[i] <= level) {
                total_time += times[i];
            }
            else {
                int wrong = diffs[i] - level;
                total_time += (times[i] + times[i - 1]) * wrong + times[i]; 
            }
            if (total_time > limit) break; //보완: 시간 초과 시 조기 종료
        }
        if (total_time <= limit) {
            answer = level;
            right = level - 1; 
        }
        else {
            left = level + 1;
        }
    }
    return answer;
}

int main()
{
    vector<int> _diffs = { 1, 4, 3 };
    vector<int> _times = { 2, 4, 7 };
    long long _limit = 30;
    solution(_diffs, _times, _limit);
    solution2(_diffs, _times, _limit);
}
