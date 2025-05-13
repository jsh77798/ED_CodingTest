
#include <string>
#include <vector>

using namespace std;

struct Point { double x, y; };  //좌표를 구조체로 관리

double dotProduct(Point a, Point b) {  // 벡터의 내적 계산
    return a.x * b.x + a.y * b.y;
}

//double Distance(const Point& p1, const Point& p2) {  //두 좌표의 거리를 계산한다.
//    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
//} 

double Distance(Point p) {  //두 좌표의 거리를 계산한다.
    return sqrt(p.x * p.x + p.y * p.y);
}

vector<Point> WallPoints(int m, int n) {  //
    Point gridSize;
    gridSize.x = m;
    gridSize.y = n;
    vector<Point> wallPoints;

    // 왼쪽 벽 (x = 0)
    for (double y = 1; y <= gridSize.y - 1; y += 0.1)
        wallPoints.push_back({ 0, y });

    // 오른쪽 벽 (x = gridSize)
    for (double y = 1; y <= gridSize.y - 1; y += 0.1)
        wallPoints.push_back({ gridSize.y, y });

    // 아래쪽 벽 (y = 0)
    for (double x = 1; x <= gridSize.x - 1; x += 0.1)
        wallPoints.push_back({ x, 0 });

    // 위쪽 벽 (y = gridSize)
    for (double x = 1; x <= gridSize.x - 1; x += 0.1)
        wallPoints.push_back({ x, gridSize.x });

    return wallPoints;
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    Point P_startBall;
    P_startBall.x = startX;
    P_startBall.y = startY;
    vector<Point> wallPoints = WallPoints(m, n);

    double minSum = INT_MAX;
    for (const auto& ball : balls)
    {
        Point P_ball;
        P_ball.x = ball[0];
        P_ball.y = ball[1];
        for (const auto& wallPoint : wallPoints) {
            Point ab = { P_startBall.x - wallPoint.x, P_startBall.y - wallPoint.y };
            Point cb = { P_ball.x - wallPoint.x, P_ball.y - wallPoint.y };
            //double distance1 = Distance(P_startBall, wallPoint);
            //double distance2 = Distance(P_ball, wallPoint);
            double dot = dotProduct(ab, cb);
            double distance1 = Distance(ab);
            double distance2 = Distance(cb);
            minSum = min(minSum, distance1 + distance2);
        }
        answer.push_back(round(pow(minSum, 2)));
    }
    return answer;
}

int main()
{
    solution(10, 10, 3, 7, { {7, 7} ,{2, 7},{7, 3} });
}
