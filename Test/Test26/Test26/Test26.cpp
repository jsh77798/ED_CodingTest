
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    vector<vector<string>> WallpaperGrid(wallpaper.size());
    vector<int> i_Grid;
    vector<int> j_Grid;
    for (int i = 0; i < wallpaper.size(); i++)
    {
        for (char c : wallpaper[i]) {
            WallpaperGrid[i].push_back(string(1, c));
        }
    }

    for (int i = 0; i < WallpaperGrid.size(); i++)
    {
        for (int j = 0; j < WallpaperGrid[i].size(); j++)
        {
            if (WallpaperGrid[i][j] == "#") {
                i_Grid.push_back(i);
                j_Grid.push_back(j);
            }
        }
    }

    sort(i_Grid.begin(), i_Grid.end());
    sort(j_Grid.begin(), j_Grid.end());
    answer.push_back(i_Grid[0]);
    answer.push_back(j_Grid[0]);

    sort(i_Grid.begin(), i_Grid.end(), greater<int>());
    sort(j_Grid.begin(), j_Grid.end(), greater<int>());
    answer.push_back(i_Grid[0]+1);
    answer.push_back(j_Grid[0]+1);
    //A[i중 제일 작은 수][j중 제일 작은 수], B[i중 제일 큰 수 +1][j중 제일 큰 수 +1]

    return answer;
}

int main()
{
    // 01   12   23  ->        01      23
    vector<string> _wallpaper = { ".#...", "..#..", "...#." };
    solution(_wallpaper);
}


