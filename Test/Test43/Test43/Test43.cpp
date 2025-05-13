
#include <string>
#include <vector>
#include <map>

using namespace std;

// 나의 풀이
vector<int> solution(vector<int> sequence, int k) {
    //vector<int> answer;
    vector<vector<int>> S;
    int start = 0, end = 0, sum = 0;

    while (end < sequence.size()) {
        // 부분합 계산
        sum += sequence[end];

        // 합이 k보다 크다면, start를 조정하여 줄임
        while (sum > k && start <= end) {
            sum -= sequence[start];
            start++;
        }

        // 합이 k라면, 결과를 반환
        if (sum == k) {
            S.push_back({ start, end });
        }

        // 다음 요소로 진행
        end++;
    }
    int S_idx = S[0][1] - S[0][0];
    pair<int, int> i_idx = { S[0][0], S[0][1] };
    for (int i = 0; i < S.size(); i++) {
        int idx = S[i][1] - S[i][0];
        if (S_idx >= idx) {
            if (S_idx != idx) {
                i_idx = { S[i][0], S[i][1] };
            }
            S_idx = idx;
        }
    }
    return { i_idx.first,i_idx.second };
}

// 다른풀이 (#슬라이딩 윈도우 #투 포인터) (배열이나 리스트의 요소의 일정 범위의 값을 비교할 때 사용하면 매우 유용)
vector<int> solution2(vector<int> sequence, int k)
{
    vector<int> answer;

    int srt = 0, end = 0, sum = 0;

    for (int i = 0; i < sequence.size(); i++)
    {
        end = i;
        sum += sequence[end];

        while (sum > k)
            sum -= sequence[srt++];

        if (sum == k)
            if (answer.empty() || end - srt < answer[1] - answer[0])
                answer = { srt, end };
    }

    return answer;
}

int main()
{
    vector<int> _sequence = { 2, 2, 2, 2, 2 };
    solution(_sequence, 6);
    solution2(_sequence, 6);
}
