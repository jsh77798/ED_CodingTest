
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int time(string str) { return (stoi(str) * 60) + ((str[3] - '0') * 10) + str[4] - '0'; }

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    int vl, p, ops, ope;
    vl = time(video_len);
    p = time(pos);
    ops = time(op_start);
    ope = time(op_end);

    for (int i = 0; i < commands.size(); i++)
    {
        if (ops <= p && p <= ope)
            p = ope;

        if (commands[i] == "prev")
        {
            p -= 10;
            if (p < 0)
                p = 0;
        }
        else
        {
            p += 10;
            if (p > vl)
                p = vl;
        }
    }
    if (ops <= p && p <= ope)
        p = ope;

    if (p < 600)
        answer += '0';
    answer += to_string(p / 60);
    answer += ':';
    if (p % 60 < 10)
        answer += '0';
    answer += to_string(p % 60);

    return answer;
}

int Test(string str)
{
    int a = stoi(str) *60;
    int b = ((str[3] - '0') * 10) + str[4] - '0';
    return b;
}

void main()
{
    Test("34:33");


    vector<string> command = { "next", "prev" };
    solution("34:33", "13:00", "00:55",	"02:55", command);

    
}