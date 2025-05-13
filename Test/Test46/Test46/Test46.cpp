
#include <string>
#include <vector>
#include <queue>

using namespace std;

// BFS

const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

//그리드를 넘어가는지 체크
bool isValid(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int solution(vector<string> board) {
    int answer = 0;
    queue<pair<int, int>> Q;
    queue<pair<int, int>> SaveQ;
    pair<int, int> start;  //시작위치
    vector<vector<string>> board_grid(board.size());  //위치 그리드

    for (int i = 0; i < board.size(); i++) {
        int j = 0;
        for (char c : board[i]) {
            if (c == 'R'){ start = { i, j }; }
            board_grid[i].push_back(string(1, c));
            j++;
        }
    }

    Q.push(start);
    int n = board_grid.size();
    int m = board_grid[0].size();
    vector<vector<bool>> visit_check(n, vector<bool>(m, false)); //방문 확인
    pair<int, int> current = Q.front(); // 큐의 맨 앞 노드

    while (!Q.empty() || !SaveQ.empty()) {
        visit_check[current.first][current.second] = true;
        if (Q.empty()) {
            answer++;
            Q = SaveQ;
            queue<pair<int, int>> empty;
            swap(SaveQ, empty);
        }
        else {
            current = Q.front();
            Q.pop();
        }
        // 상하좌우 탐색
        for (int d = 0; d < 4; ++d) {
            int nx = current.first + dx[d];
            int ny = current.second + dy[d];
            
            while (isValid(nx, ny, n, m) && board_grid[nx][ny] != "D"  )  //( 그리드를 넘어가는지 체크, "D" 인지 체크 )
            {
                nx += dx[d];
                ny += dy[d];
                if (!isValid(nx, ny, n, m) || board_grid[nx][ny] == "D" )  //( 그리드를 넘어가는지 체크, "D" 인지 체크 )
                {
                    nx -= dx[d];
                    ny -= dy[d];
                    if (!visit_check[nx][ny]) {                            //( 방문확인 체크 )
                        visit_check[nx][ny] = true;
                        SaveQ.push({ nx, ny });
                        break;
                    }
                    else {
                        break;
                    }
                }
            }
            if (isValid(nx, ny, n, m)) {
                if (board_grid[nx][ny] == "G") {
                    answer++;
                    return answer;
                }
            }
        }
    }

    answer = -1;
    return answer;
}

int main()
{
//  . . . D . . R
//  . D . G . . .
//  . . . . D . D
//  D . . . . D .
//  . . D . . . .
    vector<string> board = { "...D..R", ".D.G...", "....D.D", "D....D.", "..D...." };
    vector<string> _board = { "DGR", "...", "..." };
    vector<string> __board = { "..R", "...", "...", "..D", "DG."};
    solution(__board);
}


