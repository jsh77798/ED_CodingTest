
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>

using namespace std;

const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

bool isValid(int x, int y, int n, int m) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

int solution(vector<vector<int>> land) 
{
	int n = land.size();
	int m = land[0].size();
	queue<pair<int, int>> Q;
	vector<vector<bool>> visit_check(n, vector<bool>(m, false)); //방문 확인
	int idx = 0; //석유 덩어리 이름(표시)
	vector<vector<int>> idx_grid(n, vector<int>(m, 0)); //석유 덩어리 그리드
	map<int, int> idx_to_total; //석유 덩어리별 양

	//BFS
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (land[i][j] == 1 && !visit_check[i][j]) {
				Q.push({ i, j });
				idx_grid[i][j] = ++idx;
				int count = 0;

				while (!Q.empty()) {
					pair<int, int> xy = Q.front();
					visit_check[i][j] = true;
					Q.pop();
					count++;

					// 상하좌우 탐색
					for (int d = 0; d < 4; ++d) {
						int nx = xy.first + dx[d];
						int ny = xy.second + dy[d];
						if (isValid(nx, ny, n, m) && land[nx][ny] == 1 && !visit_check[nx][ny] ) {
							Q.push({ nx, ny });
							visit_check[nx][ny] = true;
							idx_grid[nx][ny] = idx;
						}
					}
				}
				idx_to_total[idx] = count;
			}
		}
	}

	//비교(찾기)
	int maxOil = 0;
	for (int i = 0; i < land[0].size(); i++) {
		vector<int> idx_list;
		int total = 0;
		for (int j = 0; j < land.size(); j++) {
			if (land[j][i] == 1) {
				idx_list.push_back(idx_grid[j][i]);
			}
		}
		set<int> s(idx_list.begin(), idx_list.end());
		for (auto a : s) {

			total += idx_to_total[a];
		}
		maxOil = max(maxOil, total);
	}

	return maxOil;
}

int main()
{  
	//   0 1 2 3 4 5 6 7
	//0 {0,0,0,1,1,1,0,0}
	//1 {0,0,0,0,1,1,0,0}
	//2 {1,1,0,0,0,1,1,0}
	//3 {1,1,1,0,0,0,0,0}
	//4 {1,1,1,0,0,0,1,1}
	vector<vector<int>> _land = { {0,0,0,1,1,1,0,0},{0,0,0,0,1,1,0,0},{1,1,0,0,0,1,1,0},{1,1,1,0,0,0,0,0},{1,1,1,0,0,0,1,1} };
	solution(_land);
}

