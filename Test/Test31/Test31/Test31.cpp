
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<int> C_date(string date) {
    vector<int> an;
    stringstream ss(date);
    string s;
    while (getline(ss, s, '.')) {
        an.push_back(stoi(s));
    }
    return an;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    vector<int> today_V;
    map<string, int> term_to_idx;
    vector<vector<string>> privacies_grid(privacies.size());

    for (int i = 0; i < terms.size(); i++) {
        stringstream ss(terms[i]);
        string key;
        int value;

        if (ss >> key >> value) {
            term_to_idx[key] = value;
        }
    }
    for (int i = 0; i < privacies.size(); i++) {
        stringstream ss(privacies[i]);
        string s;
        while (ss >> s) {
            privacies_grid[i].push_back(s);
        }
    }
    today_V = C_date(today);

    //today_V[1] += today_V[0] * 12;
    //today_V[2] += today_V[1] * 28;
    today_V[2] += (today_V[1] + today_V[0] * 12) * 28;

    for (int i = 0; i < privacies.size(); i++) {
        vector<int> date = C_date(privacies_grid[i][0]);
        date[1] += term_to_idx[privacies_grid[i][1]];
        /*
        //년월일 분류
        if (date[1] > 12) {
            date[0] += date[1] / 12;
            date[1] = date[1] % 12;
        }
        */


        //date[1] += date[0] * 12;
        //date[2] += date[1] * 28;
        date[2] += (date[1] + date[0] * 12) * 28;

        if (today_V[2] >= date[2]) {
            answer.push_back(i+1);
        }
    }
    return answer;
}

int main()
{
    string today = "2022.05.19";
    vector<string> terms = { "A 6", "B 12", "C 3" };
    vector<string> privacies = { "2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C" };
    solution(today, terms, privacies);
}

