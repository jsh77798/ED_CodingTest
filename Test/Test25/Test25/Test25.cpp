
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    vector<vector<string>> ParkGrid(park.size());
    vector<vector<string>> RoutesGrid(routes.size());
    pair<int, int> now;
    // 공원 2차원 백터로 변경
    for (int i = 0; i < park.size(); i++) 
    {
        for (char c : park[i]) {
            ParkGrid[i].push_back(string(1, c));
        }
    }

    for (int i = 0; i < routes.size(); i++) 
    {
        for (char c : routes[i]) 
        {
            if (c != ' ') 
            { 
                RoutesGrid[i].push_back(string(1, c));
            }
        }
    }

    for (int i = 0; i < RoutesGrid.size(); i++) {
        int n = stoi(RoutesGrid[i][1]);
        pair<int, int> op;
        for (int j = 0; j < ParkGrid.size(); j++) 
        {
            for (int t = 0; t < ParkGrid[j].size(); t++)
            {
                if (ParkGrid[j][t] == "S") {
                    now = { j,t };
                }
            }
        }

        if (RoutesGrid[i][0] == "N") {
            op = { -1,0 };
        }
        else if(RoutesGrid[i][0] == "S") {
            op = { 1,0 };
        }
        else if (RoutesGrid[i][0] == "W") {
            op = { 0,-1 };
        }
        else if (RoutesGrid[i][0] == "E") {
            op = { 0,1 };
        }

        pair<int, int> SaveNow = now;
        vector<vector<string>> SaveParkGrid = ParkGrid;
        for (int i = 0; i < n; i++) {
            if (now.first + op.first >= 0 && now.first + op.first < ParkGrid[0].size() && now.second + op.second >= 0 && now.second + op.second < ParkGrid[0].size())
            {
                if (ParkGrid[now.first + op.first][now.second + op.second] != "X") {
                    ParkGrid[now.first + op.first][now.second + op.second] = ParkGrid[now.first][now.second];
                    ParkGrid[now.first][now.second] = "O";
                    now = { now.first + op.first, now.second + op.second };
                }
                else 
                {
                    now = SaveNow;
                    ParkGrid = SaveParkGrid;
                    i = n;
                }
            }
            else 
            {
                now = SaveNow;
                ParkGrid = SaveParkGrid;
                i = n;
            }
        }
        
    }
    answer.push_back(now.first);
    answer.push_back(now.second);
    return answer;
}

int main()
{
    vector<string> _park = { "OSO", "OOO", "OXO", "OOO" };
    vector<string> _routes = { "E 2", "S 3", "W 1" };
    solution(_park, _routes);
}



