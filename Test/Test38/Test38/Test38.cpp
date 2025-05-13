
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4);
     
    // 생성한 정점
    {
        map<int, int> idx_to_count;
        map<int, bool> idx_to_check;
        for (int i = 0; i < edges.size(); i++) {
            idx_to_count[edges[i][0]]++;
            idx_to_check[edges[i][1]] = false;
        }
        int value = 0;
        int key = 0;
        for (const auto& pair : idx_to_count) {
            if (value < pair.second) {
                if (idx_to_check.find(pair.first) == idx_to_check.end()) {
                    key = pair.first;
                    value = pair.second;
                }
            }
        }
        answer[0] = key;
    }

    // 도넛 모양
    {
        int doughnut_count = 0;
        for (int i = 0; i < edges.size(); i++) {
            if (edges[i][0] == edges[i][1]) {
                doughnut_count++;
            }
        }
        answer[1] = doughnut_count;
    }

    // 막대 모양 
    {
        int stick_count = 0;
        map<int, bool> idx_to_check;
        for (int i = 0; i < edges.size(); i++) {
            for (int j = 0; j < edges.size(); j++) {
                if (edges[i][1] == edges[j][0]) {
                    idx_to_check[edges[i][1]] = false;
                    break;
                }
                else {
                    idx_to_check[edges[i][1]] = true;
                }
            }
        }
        for (const auto& pair : idx_to_check) {
            if (pair.second == true) {
                stick_count++;
            }
        }
        answer[2] = stick_count;
    }

    // 8자 모양
    {
        int eight_count = 0;
        map<int, vector<int>> idx_to_count_p;
        for (int i = 0; i < edges.size(); i++) {
            if (idx_to_count_p[edges[i][0]].size() == 0)
            {
                idx_to_count_p[edges[i][0]].push_back(0);
            }
            idx_to_count_p[edges[i][0]][0]++;
            idx_to_count_p[edges[i][0]].push_back(i);
        }
        for (const auto& pair : idx_to_count_p) {
            if (pair.second[0]==2) {
                int a = pair.second[1];
                int b = pair.second[1];
                int starting_a = a;
                int starting_b = b;
                int a_count = 0;
                int b_count = 0;
                bool a_check = false;
                bool b_check = false;
                while (true)
                {
                    if (idx_to_count_p.find(edges[a][1]) != idx_to_count_p.end() &&
                        !idx_to_count_p[edges[a][1]].empty() &&
                        idx_to_count_p[edges[a][1]][0] == 1) {
                        a = idx_to_count_p[edges[a][1]][1];
                        a_count++;
                    }
                    //if (idx_to_count_p[edges[a][1]][0] == 1) {
                    //    a = idx_to_count_p[edges[a][1]][1];
                    //    a_count++;
                    //}
                    else
                    {
                        break;
                    }
                    if (edges[starting_a][0] == edges[a][1]) {
                        a_check = true;
                        break;
                    }
                }
                while (true)
                {
                    if (idx_to_count_p.find(edges[b][1]) != idx_to_count_p.end() &&
                        !idx_to_count_p[edges[b][1]].empty() &&
                        idx_to_count_p[edges[b][1]][0] == 1) {
                        b = idx_to_count_p[edges[b][1]][1];
                        b_count++;
                    }
                    //if (idx_to_count_p[edges[b][1]][0] == 1) {
                    //    b = idx_to_count_p[edges[b][1]][1];
                    //    b_count++;
                    //}
                    else
                    {
                        break;
                    }
                    if (edges[starting_b][0] == edges[b][1]) {
                        b_check = true;
                        break;
                    }
                }
                if (a_check == true && b_check == true && a_count == b_count) {
                    eight_count++;
                }
            }
        }
        answer[3] = eight_count;
    }

    return answer;
}

int main()
{
    //[[1, 1], [2, 1], [2, 3], [3, 4], [5, 3]]
    //    기댓값 〉[2, 1, 1, 0]
    vector<vector<int>> _edges = { { 1, 1 }, { 2, 1 }, { 2, 3 }, { 3, 4 }, { 5, 3 } };
    //vector<vector<int>> _edges = { { 2, 3 }, { 4, 3 }, { 1, 1 }, { 2, 1 } };
    //vector<vector<int>> _edges = { {4, 11} ,{1, 12},{8, 3},{12, 7},{4, 2},{7, 11},{4, 8},{9, 6},{10, 11},{6, 10},{3, 5},{11, 1},{5, 3},{11, 9},{3, 8} };
    solution(_edges);
}
