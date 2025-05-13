
//#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// 1# 
unordered_map<string, int> dic[3] = {
    { { "diamond", 1 }, { "iron", 1 }, { "stone", 1 } },
    { { "diamond", 5 }, { "iron", 1 }, { "stone", 1 } },
    { { "diamond", 25 }, { "iron", 5 }, { "stone", 1 } }
};

int solution(vector<int> picks, vector<string> minerals) {
    auto calc = [&](int idx, int tool) -> int {
        int ret = 0;
        for (int i = 0; i < 5 && idx + i < minerals.size(); ++i) ret += dic[tool][minerals[idx + i]];

        return ret;
        };

    auto go = [&](auto& self, int a, int b, int c, int idx = 0) -> int {
        if (a + b + c == 0 || idx >= minerals.size()) return 0;

        int ret = 0x3f3f3f3f;
        if (a) ret = min(ret, calc(idx, 0) + self(self, a - 1, b, c, idx + 5));
        if (b) ret = min(ret, calc(idx, 1) + self(self, a, b - 1, c, idx + 5));
        if (c) ret = min(ret, calc(idx, 2) + self(self, a, b, c - 1, idx + 5));

        return ret;
        };

    return go(go, picks[0], picks[1], picks[2]);
}

// 2# DFS
vector<vector<int>> consume = { {1, 1, 1}, {5, 1, 1}, {25, 5, 1} };
int DFS(int depth, int count, vector<int>& picks, vector<int>& minerals)
{
    if (depth >= minerals.size()
        ||
        (picks[0] == 0 && picks[1] == 0 && picks[2] == 0))
        return count;

    int minCount = INT32_MAX;
    int temp, j;

    for (int i = 0; i < 3; i++)
    {
        if (picks[i])
        {
            picks[i]--;
            temp = 0;
            j = depth;

            while (j < depth + 5 && j < minerals.size())
                temp += consume[i][minerals[j++]];

            minCount = min(minCount, DFS(j, count + temp, picks, minerals));
            picks[i]++;
        }
    }

    return minCount;
}

int solution1(vector<int> picks, vector<string> minerals)
{
    vector<int> _minerals;

    for (string& mineral : minerals)
    {
        if (mineral == "diamond")
            _minerals.push_back(0);
        else if (mineral == "iron")
            _minerals.push_back(1);
        else
            _minerals.push_back(2);
    }

    return DFS(0, 0, picks, _minerals);
}

int main()
{
    vector<int> _picks = { 1, 0, 1 };
    vector<string> _minerals = { "iron", "iron", "iron", "iron", "iron", "diamond" };
    // 26      

    vector<int> __picks = { 1, 3, 2 };
    vector<string> __minerals = { "diamond", "diamond", "diamond", "iron", "iron", "diamond", "iron", "stone" };
    // 12    
     
    int a = solution(_picks, _minerals);
    int b = solution1(_picks, _minerals);
}
