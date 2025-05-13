
#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;
vector<vector<int>> robot(vector<vector<int>> points, vector<int> this_routes) {
    vector<vector<int>> savepoints;
    vector<vector<int>> movepoints(this_routes.size());
    for (int i = 0; i < this_routes.size(); i++) {
        movepoints[i] = points[this_routes[i] - 1];
    }
    //move
    savepoints.push_back(movepoints[0]);
    for (int i = 0; i < movepoints.size(); i++) {
        vector<int> move;
        if (i + 1 < movepoints.size()) {
            move.push_back(movepoints[i + 1][0] - movepoints[i][0]);
            move.push_back(movepoints[i + 1][1] - movepoints[i][1]);
        }
        else {
            break;
        }
        int r = (move[0] != 0) ? move[0] / abs(move[0]) : 0;
        int c = (move[1] != 0) ? move[1] / abs(move[1]) : 0;
        int time = abs(move[0]) + abs(move[1]);
        int prev_0 = movepoints[i][0];
        int prev_1 = movepoints[i][1];
        for (int j = 0; j < time; j++) {
            vector<int> save;
            if (move[0] != 0) {
                save.push_back(prev_0 += r);
                save.push_back(prev_1);
                move[0] = move[0] * abs(abs(move[0]) - 1)/abs(move[0]);
            }
            else {
                save.push_back(prev_0);
                save.push_back(prev_1 += c);
                move[1] = move[1] * abs(abs(move[1]) - 1) / abs(move[1]);
            }
            savepoints.push_back(save);
        }
    }
    return savepoints;
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    map<vector<int>, map<int, int>> points_to_time;
    for (int i = 0; i < routes.size(); i++) {
        vector<vector<int>> robots_data = robot(points, routes[i]);
        for (int j = 0; j < robots_data.size(); j++) {
            points_to_time[robots_data[j]][j]++;
        }
    }
    
    for (const auto& pair : points_to_time) {
        const auto& key = pair.first;
        const auto& value = pair.second;
        for (const auto& V_pair : value) {
            const auto& V_key = V_pair.first;
            const auto& V_value = V_pair.second;
            if (V_value >= 2) {
                answer++;
            }
        }
    }
    return answer;
}

int main()
{
    //[[1, 1], [2, 2], [3, 3]], [[1, 2, 1], [3, 2, 1]]
    vector<vector<int>> _points = { {1, 1}, {2, 2}, {3, 3}};
    vector<vector<int>> _routes = { {1, 2, 1}, {3, 2, 1}};
    solution(_points, _routes);
}
