#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

int TextTimeConversion(string timeString)
{
    std::stringstream ss(timeString);
    int minutes = 0, seconds = 0;

    // 분 부분 추출
    if (std::getline(ss, timeString, ':')) {
        minutes = std::stoi(timeString);
    }

    // 초 부분 추출
    if (std::getline(ss, timeString, ':')) {
        seconds = std::stoi(timeString);
    }

    // 결과 출력
    return minutes * 60 + seconds;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    //int timeanswer = 0;
    int _video_len = TextTimeConversion(video_len);
    int _pos = TextTimeConversion(pos);
    int _op_start = TextTimeConversion(op_start);
    int _op_end = TextTimeConversion(op_end);
    int timeanswer = _pos;

    if (_op_start <= _pos && _pos <= _op_end)
    {
        timeanswer = _op_end;
        _pos = _op_end;
    }

    for (int i = 0; i < commands.size(); ++i)
    {
        int MoveTime = "prev" == commands[i] ? -10 : 10;

        _pos += MoveTime;
        if (_pos <= 0) 
        {
            _pos = 0;
        }
        if (_pos >= _video_len) 
        {
            _pos = _video_len;
        }
        //timeanswer += MoveTime;
        timeanswer += MoveTime;
        if (timeanswer <= 0)
        {
            timeanswer = 0;
        }
        if (timeanswer >= _video_len)
        {
            timeanswer = _video_len;
        }


        if (_op_start <= _pos && _pos <= _op_end) 
        {
            timeanswer = _op_end;
            _pos = _op_end;
            //i = commands.size();
        }
    }

    if (_op_start <= _pos && _pos <= _op_end)
    {
        timeanswer = _op_end;
        _pos = _op_end;
    }

    if (_video_len <= timeanswer)
    {
        timeanswer = _video_len;
    }

    string minutes = "", seconds = "", A_minutes = "", A_seconds = "", colon = ":", zero = "0";
    int min = 0, sec = 0;
    min = timeanswer / 60;
    sec = timeanswer % 60;

    minutes = to_string(timeanswer / 60);
    seconds = to_string(timeanswer % 60);
    if (10 > min) 
    {
        minutes = zero + minutes;
        
    }
    if (10 > sec) 
    {
        seconds = zero + seconds;
    }
    answer = minutes + colon + seconds;

    return answer;
}

int main()
{
    vector<string> command = { "next", "prev" };
    solution("10:00", "10:00", "01:00", "02:00", command);
    //"00:05"
}

