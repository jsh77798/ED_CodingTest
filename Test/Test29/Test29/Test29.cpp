
#include <string>
#include <vector>
#include <queue>

using namespace std;

//내 풀이(큐를 이용해 풀음)
string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    queue<string> card1;
    queue<string> card2;
    for (string c : cards1) {
        card1.push(c);
    }
    for (string c : cards2) {
        card2.push(c);
    }

    for (int i = 0; i < goal.size(); i++) {
        if (goal[i] == card1.front()) {
            card1.pop();
            answer = "Yes";
        }
        else if(goal[i] == card2.front()) {
            card2.pop();
            answer = "Yes";
        }
        else {
            answer = "No";
            break;
        }
    }

    return answer;
}

//다른 풀이
string solution2(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int l = 0;
    int r = 0;

    for (string& g : goal) {
        if (g == cards1[l]) {
            l++;
        }
        else if (g == cards2[r]) {
            r++;
        }
        else {
            return "No";
        }
    }

    return "Yes";
}

int main()
{
    vector<string> _cards1 = { "i", "drink", "water" };
    vector<string> _cards2 = { "want", "to" };
    vector<string> _goal = { "i", "want", "to", "drink", "water" };
    
    solution(_cards1, _cards2, _goal);
    solution2(_cards1, _cards2, _goal);
}
