
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int toMinutes(const std::string& time) {
    int hours = stoi(time.substr(0, 2));
    int minutes = stoi(time.substr(3, 2));
    minutes += hours * 60;

    if (minutes >= 1440) { minutes -= 1440; } 
    return minutes;
}

int solution(vector<vector<string>> book_time) {
    // 정렬: 입실기준으로 오름차순
    sort(book_time.begin(), book_time.end(), [](const vector<string>& a, const vector<string>& b) {
        return toMinutes(a[0]) < toMinutes(b[0]);
    });

    priority_queue<int, vector<int>, greater<int>> rooms;

    for (const auto& booking : book_time) {
        int start = toMinutes(booking[0]);
        int end = toMinutes(booking[1]) + 10; // 청소 시간 포함

        // 3. 현재 방 중 사용할 수 있는 방 제거
        if (!rooms.empty() && rooms.top() <= start) {
            rooms.pop();
        }

        // 4. 새 방 사용 (또는 재사용)
        rooms.push(end);
    }

    return rooms.size(); // 필요한 최소 객실 수
}

void main()
{
    //                                             1                                                                            1
    vector<vector<string>> book_time0 = { {"15:00", "17:00"},{"16:40", "18:20"},{"14:20", "15:20"},{"14:10", "19:20"},{"18:20", "21:20"} }; // 3
    vector<vector<string>> book_time1 = { {"09:10", "10:10"},{"10:20", "12:20"} }; // 1
    vector<vector<string>> book_time2 = { {"10:20", "12:30"},{"10:20", "12:30"},{"10:20", "12:30"} }; // 3
    vector<vector<string>> book_time3 = { {"09:00", "10:00"},{"09:00", "11:00"},{"13:30", "20:00"},{"10:30", "14:00"},{"11:30", "13:00"},{"16:30", "19:30"} }; // 2
    vector<vector<string>> book_time4 = { {"00:00", "00:07"},{"00:01", "00:08"},{"00:02", "00:09"},{"10:26", "10:41"} }; // 3
    vector<vector<string>> book_time5 = { {"1:00", "2:01"},{"2:10", "3:00"},{"3:10", "4:00"} }; // 2
    vector<vector<string>> book_time6 = { {"5:00", "15:00"},{"10:00", "20:00"},{"20:30", "23:00"},{"15:30", "23:30"} };
    //                                           1                    2                 3                     2
    vector<vector<string>> book_time7 = { {"09:00", "16:00"},{"10:00", "11:00"},{"10:00", "13:00"},{"15:10", "15:50"} }; // 3
    int answer = solution(book_time0);
}
