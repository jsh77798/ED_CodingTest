#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef pair<int, int> Point;

// 두 점 사이의 거리의 제곱을 구하는 함수
int getDistanceSquared(Point a, Point b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;

    for (const auto& ball : balls) {
        int targetX = ball[0];
        int targetY = ball[1];
        int minDist = INT_MAX;

        // 원래의 위치
        Point original(startX, startY);
        Point target(targetX, targetY);

        // 4개의 반사된 좌표를 고려
        vector<Point> reflections = {
            {-startX, startY},             // 좌벽 반사
            {2 * m - startX, startY},      // 우벽 반사
            {startX, -startY},             // 하벽 반사
            {startX, 2 * n - startY}       // 상벽 반사
        };

        for (const auto& reflection : reflections) {
            // 공의 진행 경로상에 목표 공이 방해하지 않는 경우만 고려
            if (targetX >= min(startX, reflection.first) && targetX <= max(startX, reflection.first) &&
                targetY >= min(startY, reflection.second) && targetY <= max(startY, reflection.second)) {
                continue;
            }
            else {
                minDist = min(minDist, getDistanceSquared(reflection, target));
            }
        }

        answer.push_back(minDist);
    }

    return answer;
}

int main() {
    int m = 10, n = 10;
    int startX = 3, startY = 7;
    vector<vector<int>> balls = { {7, 7}, {2, 7}, {7, 3}};

    vector<int> result = solution(m, n, startX, startY, balls);

    for (int dist : result) {
        cout << dist << " ";
    }
    cout << endl;

    return 0;
}
