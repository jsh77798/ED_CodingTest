
#include <string>
#include <vector>
#include <map>
#include <stack>

using namespace std;

// 분으로 변환
int conversion(string s) {
    int hour;
    int minute;
    if (s.find(":") != string::npos) {
        hour = stoi(s.substr(0,2));
        minute = stoi(s.substr(3));
        return hour * 60 + minute;
    }
    return stoi(s);
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    map <int, string> timeline;
    map <string, int> catalog;
    stack <string>  task;
    stack <int>  tasktime;
    int totalTime = 0;

    for (int i = 0; i < plans.size(); i++) {
        totalTime += conversion(plans[i][2]);
        timeline[conversion(plans[i][1])] = plans[i][0];
        catalog[plans[i][0]] = conversion(plans[i][2]);
    }

    auto start = timeline.begin();
    auto end = prev(timeline.end());
    if (totalTime + start->first <= end->first) { totalTime = end->first + catalog[timeline[end->first]]; }
    else { totalTime += start->first; }
    for (int t = start->first; t < totalTime; t++) {
        if (timeline.find(t) != timeline.end()) {
            task.push(timeline[t]);
            tasktime.push(catalog[timeline[t]]);
        }
    
        if (!task.empty()) {
            tasktime.top() -= 1;
            if (tasktime.top() <= 0) {
                answer.push_back(task.top());
                task.pop();
                tasktime.pop();
            }
        }
    }

    return answer;
}

int main()
{
    vector<vector<string>> _plans = { {"korean", "11:40", "30"} ,{"english", "12:10", "20"},{"math", "12:30", "40"} };
    vector<vector<string>> _plans2 = { {"science", "12:40", "50"} ,{"music", "12:20", "40"},{"history", "14:00", "30"},{"computer", "12:30", "100"} };
    vector<vector<string>> _plans3 = { {"a", "09:00", "30"} ,{"b", "09:10", "20"},{"c", "09:15", "20"},{"d", "09:55", "10"},{"e", "10:50", "5"} };
    vector<vector<string>> _plans4 = { {"UmmLang", "11:00", "10"},{"MSA", "11:08", "1"},{"Redis", "11:10", "1"},{"Kafka", "11:12", "1"} };
    vector<vector<string>> _plans5 = { {"aaa", "11:40", "20"},{"bbb", "11:45", "5"},{"ccc", "11:50", "5"},{"ddd", "11:55", "5"},{"eee", "12:05", "5"} };
    vector<vector<string>> _plans6 = { {"a", "09:00", "10"},{"b", "09:10", "10"},{"c", "09:15", "10"},{"d", "09:30", "10"}, {"e", "09:35", "10"} };
    vector<vector<string>> _plans7 = { {"science", "12:40", "50"} ,{"music", "12:20", "40"},{"history", "15:00", "30"},{"computer", "12:30", "100"} };
    vector<vector<string>> _plans8 = { {"aaa", "12:00", "30"} ,{"bbb", "12:10", "30"},{"ccc", "14:00", "30"} };
    solution(_plans8);
}
