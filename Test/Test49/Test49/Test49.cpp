#include <string>
#include <vector>
#include <queue>

using namespace std;

pair<int, int > startPos;
// 뱡향: 우 하 좌 상
const int dy[] = { 0,1,0,-1 };
const int dx[] = { 1,0,-1,0 };

// 그리드를 넘어가는지 체크
bool isVaild(int y, int x, int maxY, int maxX) {
    return y >= 0 && y < maxY && x >= 0 && x < maxX;
}

int findMaze(vector<string> maps, pair<int, int > start, char target) {
    queue< pair<pair<int, int>, int>> Q;
    int maxY = maps.size();
    int maxX = maps[0].length();
    vector<vector<bool>> visitCheck(maxY, vector<bool>(maxX, false)); //방문 확인

    Q.push({ start, 0 });
    visitCheck[start.first][start.second] = true;
    //bfs 너비우선탐색
    while (!Q.empty()) {
        pair<pair<int, int>, int> temp = Q.front(); // 큐의 맨 앞 요소 가져오기
        Q.pop(); // 큐에서 제거
        int y = temp.first.first;
        int x = temp.first.second;

        // 우 하 좌 상 탐색
        for (int d = 0; d < 4; ++d) {
            int ny = y + dy[d];
            int nx = x + dx[d];
            if (isVaild(ny, nx, maxY, maxX) && maps[ny][nx] != 'X' && !visitCheck[ny][nx]) {
                if (maps[ny][nx] == target) {
                    if (maps[ny][nx] == 'L') { startPos = { ny, nx }; }
                    return temp.second + 1;
                }
                Q.push(make_pair(make_pair(ny, nx), temp.second + 1));
                visitCheck[ny][nx] = true;
            }
        }
    }

    return -1;
}

int solution(vector<string> maps) {
    for (int y = 0; y < maps.size(); ++y) {
        for (int x = 0; x < maps[0].length(); ++x) {
            if (maps[y][x] == 'S') { 
                startPos = { y, x }; 
                break; 
            }
        }
    }

    int result_L = findMaze(maps, startPos, 'L');
    if (result_L == -1) { return -1; }

    int result_E = findMaze(maps, startPos, 'E');
    if (result_E == -1) { return -1; }

    return result_L + result_E;
}

void main() {
    vector<string> maps0 = { "SOOOL", "XXXXO", "OOOOO", "OXXXX", "OOOOE" }; // 16
    vector<string> maps1 = { "LOOXS","OOOOX","OOOOO","OOOOO","EOOOO" }; // -1
    vector<string> maps2 = { "S0LO0", "E0000", "O0OO0", "OOOOO", "OOOOO" }; 
    vector<string> maps3 = { "SOOOL", "XXOXX", "XXOOE" }; //10
    int ans = solution(maps3);
}