
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <tuple>

using namespace std;
// 문제풀이 포기(부분정답,복잡)
int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    //int total = (picks[0] + picks[1] + picks[2]) * 5;
    //total = minerals.size() / total;
    int total = std::min((picks[0] + picks[1] + picks[2]) * 5, static_cast<int>(minerals.size()));
    vector<int> mine_fatigue;
    map<string, vector<int>> mine_score;
    mine_score["diamond"] = { 25, 3 };
    mine_score["iron"] = { 5, 2 };
    mine_score["stone"] = { 1, 1 };
    int max = 0;
    int count = 0;
    for (int i = 0; i < minerals.size(); i++) {
        if (count == 5) {
            mine_fatigue.push_back(max);
            max = 0;
            count = 0;
        }
        max += mine_score[minerals[i]][1];
        count++;
        if (i + 1 == minerals.size()) {
            mine_fatigue.push_back(max);
        }
    }

    map<int, string> plan;
    vector<int> _mine_fatigue = mine_fatigue;
    sort(_mine_fatigue.begin(), _mine_fatigue.end(), greater<int>());
    for (int j = 0; j < _mine_fatigue.size(); j++) {
        if (picks[0] != 0) {
            plan[_mine_fatigue[j]] = "diamond";
            picks[0] -= 1;
        }
        else if (picks[1] != 0) {
            plan[_mine_fatigue[j]] = "iron";
            picks[1] -= 1;
        }
        else if (picks[2] != 0) {
            plan[_mine_fatigue[j]] = "stone";
            picks[2] -= 1;
        }
    }

    int mine_count = 0;
    int idx = 0;
    for (int i = 0; i < total; i++) {
        if (mine_count == 5) {
            idx++; 
            mine_count = 0;
        }

        int ans = mine_score[minerals[i]][0] / mine_score[plan[mine_fatigue[idx]]][0];
        ans <= 1 ? ans = 1 : ans = ans;
        answer += ans;
        mine_count++;
    }

    return answer;
}

// 문제풀이2
vector<int> mining(vector<string> maxMinerals) {
    vector<int> totalMining;
    map<string, int> fatigue_score;
    fatigue_score["diamond"] = 0;
    fatigue_score["iron"] = 1;
    fatigue_score["stone"] = 2;
    int diamond = 0;
    int iron = 0;
    int stone = 0;

    for (string s : maxMinerals) {
        diamond += pow(5, 0 - fatigue_score[s] < 0 ? 0 : 0 - fatigue_score[s]);
        iron += pow(5, 1 - fatigue_score[s] < 0 ? 0 : 1 - fatigue_score[s]);
        stone += pow(5, 2 - fatigue_score[s] < 0 ? 0 : 2 - fatigue_score[s]);
    }
    totalMining.push_back(diamond);
    totalMining.push_back(iron);
    totalMining.push_back(stone);
    return totalMining;
}

int solution2(vector<int> picks, vector<string> minerals) {
    int fatigue = 0;
    int maxPicks = (picks[0] + picks[1] + picks[2]) * 5;

    // 1. 벡터를 5개씩 나누기
    vector<vector<string>> groups;
    for (size_t i = 0; i < minerals.size(); i += 5) {
        if (i < maxPicks) {
            groups.push_back(vector<string>(minerals.begin() + i, (i + 5 < minerals.size()) ? minerals.begin() + i + 5 : minerals.end()));
        }
    }
    // 2. 각 그룹에서 target 값의 개수 카운트
    vector<tuple<pair<int, int>, vector<string>>> countedGroups; // {count, group}
    for (const auto& group : groups) {
        pair<int, int> count; 
        count.first = std::count(group.begin(), group.end(), "diamond");
        count.second = std::count(group.begin(), group.end(), "iron");
        countedGroups.emplace_back(count, group);
    }
    // 3. 카운트를 기준으로 그룹 정렬 (내림차순)
    sort(countedGroups.begin(), countedGroups.end(), [](const auto& a, const auto& b) {
        return get<0>(a) > get<0>(b); // count 기준 내림차순
    });

    for (int i = 0; i < countedGroups.size(); i++) {
        vector<int> _mining;
        auto& currentTuple = countedGroups[i];
        _mining = mining(get<1>(currentTuple));
        for (int a = 0; a < 3; a++) {
            if (picks[a] != 0) {
                fatigue += _mining[a];
                picks[a] -= 1;
                break;
            }
        }
    }

    return fatigue;
}


// 그리디 알고리즘 풀이
int solution3(vector<int> picks, vector<string> minerals) {

    // 그리디 알고리즘 예시 //
    int n= 1410;                            //광물의 총 점수 ㅇ
    int coin[4] = { 500, 100, 50, 10 };     //광물의 종류    ㅇ
    int ans = 0; //거스름돈의 개수          //각 광물의 갯수 ㅇ
    for (int i = 0; i < 4; i++) {           
        ans += (n / coin[i]);
        n %= coin[i];
    }
    return ans;
    //////////////////////////
}

int main()
{
    vector<int> _picks = { 1, 0, 1 };
    vector<string> _minerals = { "iron", "iron", "iron", "iron", "iron", "diamond" };
    // 26      

    vector<int> __picks = { 1, 3, 2 };
    vector<string> __minerals = { "diamond", "diamond", "diamond", "iron", "iron", "diamond", "iron", "stone" };
    // 12     d,d,d,d,i,i,i,s    1,1,1,1,1,1,1,1

    vector<int> ___picks = { 0, 5, 5 };
    vector<string> ___minerals = { "diamond", "diamond", "diamond", "diamond", "diamond", 
    "diamond", "diamond", "diamond", "diamond", "diamond", 
    "diamond", "diamond", "diamond", "diamond", "diamond", 
    "diamond", "diamond", "diamond", "diamond", "diamond", 
    "diamond", "diamond", "diamond", "diamond", "diamond", 
    "diamond", "diamond", "diamond", "diamond", "diamond", 
    "diamond", "diamond", "diamond", "diamond", "diamond", 
    "diamond", "diamond", "diamond", "diamond", "diamond", 
    "diamond", "diamond", "diamond", "diamond", "diamond", 
    "diamond", "diamond", "diamond", "diamond", "diamond", };
    // 750

    vector<int> ____picks = { 1, 0, 1 };
    vector<string> ____minerals = { "diamond", "iron", "iron", "stone", "iron", "diamond", "iron", "iron", "iron", "iron" };
    //      d,i,i,i,s,s  1,1,1,1,1,1  

    vector<int> _____picks = { 2,1,0 };
    vector<string> _____minerals = { "diamond", "diamond", "diamond", "diamond", "diamond", "iron", "iron", "iron", "iron", "iron", "diamond", "diamond", "diamond", "diamond", "diamond" };
    // 15     

    solution(_picks, _minerals);
    solution2(____picks, ____minerals);
}