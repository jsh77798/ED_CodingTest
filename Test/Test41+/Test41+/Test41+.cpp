//#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1];
}

int solution(vector<vector<int>> targets) {
    sort(targets.begin(), targets.end(), cmp);

    int ans = 0;
    int t = -1;
    for (auto& tar : targets) {
        if (tar[0] >= t) {
            t = tar[1];
            ans++;
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> targets = { {4, 5},{4, 8},{10, 14},{11, 13},{5, 12},{3, 7},{1, 4} };
    solution(targets);
}

    
