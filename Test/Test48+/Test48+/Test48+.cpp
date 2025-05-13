#include <string>
#include <vector>

using namespace std;

const int dy[] = { 0, 1, 1, 1 };
const int dx[] = { 1, 1, 0, -1 };
int oBingoCount = 0;
int xBingoCount = 0;

bool isVaild(int y, int x) {
    return y >= 0 && y < 3 && x >= 0 && x < 3;
}

void search(int y, int x, int d, int _bingoCount, vector<string> board) {
    int ny = y + dy[d];
    int nx = x + dx[d];
    int bingoCount = _bingoCount;
    if (isVaild(ny, nx) && board[ny][nx] == board[y][x]) {
        ++bingoCount;
        if (bingoCount == 2) {
            if (board[ny][nx] == 'O') { ++oBingoCount; }
            if (board[ny][nx] == 'X') { ++xBingoCount; }
            return;
        }
        search(ny, nx, d, bingoCount, board);
    }
}

int solution(vector<string> board) {
    int oCount = 0;
    int xCount = 0;

    for (int y = 0; y < board.size(); ++y) {
        for (int x = 0; x < board[0].length(); ++x) {
            if (board[y][x] != '.') {
                if (board[y][x] == 'O') { ++oCount; }
                if (board[y][x] == 'X') { ++xCount; }
                for (int d = 0; d < 4; ++d) {
                    search(y, x, d, 0, board);
                }
            }
        }
    }
    if (oCount - xCount < 0 || oCount - xCount > 1) { return 0; }
    if (oCount == xCount && oBingoCount - xBingoCount >= 1) { return 0; }
    if (oCount - xCount == 1 && oBingoCount < xBingoCount) { return 0; }
    if (oBingoCount + xBingoCount > 0 && oBingoCount == xBingoCount) { return 0; }
    return 1;
}

void main() {
    vector<string> board = { "O.X", ".O.", "..X" };
    int idx = solution(board);
}