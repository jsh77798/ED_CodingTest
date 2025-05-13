#include <string>
#include <vector>

using namespace std;

//하나만 있는 경우 O만 있어야한다.
//O,X 중 둘중 한개가 더많을 경우 O가 더많아야 한다.
//O,X 중 둘중 두개이상 많을 수 없다.
//O,X 중 한개만 승리할 수 있다.

const int dx[] = { 0, -1, -1, -1 };
const int dy[] = { -1, -1, 0, 1 };
int oBingoCount = 0;
int xBingoCount = 0;

//그리드를 넘어가는지 체크
bool isValid(int x, int y) {
    return x >= 0 && x < 3 && y >= 0 && y < 3;
}

//DFS 재귀함수
void search(int x, int y, int d, int _bingoCount, vector<vector<string>> _boardGrid) {
    int bingoCount = _bingoCount;
    int nx = x + dx[d];
    int ny = y + dy[d];

    if (isValid(nx, ny) && _boardGrid[nx][ny] != ".") {
        if (_boardGrid[nx][ny] == _boardGrid[x][y]) {
            bingoCount++;
            if (bingoCount == 2) {
                if (_boardGrid[nx][ny] == "O") { oBingoCount++; }
                if (_boardGrid[nx][ny] == "X") { xBingoCount++; }
                return;
            }
            search(nx, ny, d, bingoCount, _boardGrid);
        }
    }
}

int solution(vector<string> board) {
    int answer = -1;
    vector<vector<string>> boardGrid(3);  //위치 그리드
    int oCount = 0;
    int xCount = 0;

    for (int i = 0; i < board.size(); i++) {
        for (char c : board[i]) {
            if (c == 'O') { boardGrid[i].push_back("O"); oCount++; }
            if (c == 'X') { boardGrid[i].push_back("X"); xCount++; }
            if (c == '.') { boardGrid[i].push_back("."); }
        }
    }
    if (oCount < xCount) { return 0; }
    if (oCount - xCount > 1) { return 0; }
    
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            // 탐색
            if (boardGrid[x][y] != ".") {
                for (int d = 0; d < 4; ++d) {
                    search(x, y, d, 0, boardGrid);
                }
            }
        }
    }
    if (oCount == xCount) {
        if(oBingoCount - xBingoCount >= 1){ return 0; }
    }
    if (oCount - xCount == 1) {
        if(oBingoCount < xBingoCount){ return 0; }
    }
    if (oBingoCount + xBingoCount > 0) {
        if (oBingoCount == xBingoCount) { return 0; }
    }
    return 1;
}

int main()
{
    vector<string> board_0 = { "O.X", ".O.", "..X" }; // 1
    vector<string> board_1 = { "OOO", "...", "XXX" }; // 0
    vector<string> board_2 = { "...", ".X.", "..." }; // 0
    vector<string> board_3 = { "...", "...", "..." }; // 1

    vector<string> board_4 = { "OOO", "XOX", "XXO" }; // 1
    vector<string> board_5 = { "OOO", "OXX", "OXX" }; // 1
    vector<string> board_6 = { "OOO", "O..", "XXX" }; // 0
    vector<string> board_7 = { "XOO", ".XO", ".OX" }; // 0
    vector<string> board_8 = { "XOO", "XOO", "XXX" }; // 0

    vector<string> board_11 = { "XXO", ".OX", "O.." }; // 0
    vector<string> board_12 = { "OOO", "OOO", "XXX" }; // 0
    vector<string> board_13 = { "XOX", "OOO", "XOX" }; // 1
    int idx = solution(board_13);
}
