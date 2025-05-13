
#include <iostream>
#include <vector>

using namespace std;

// 시계에서 초침이 시침 또는 분침과 겹치는지 확인하는 함수
int isOverlap(int h, int m, int s, vector<int> prev ) {
    int alarm = 0;
    // 시침, 분침, 초침의 각도 계산
    double hour_angle = (h % 12) * 30 + (m / 60.0) * 30 + (s / 3600.0) * 30;
    double minute_angle = m * 6 + (s / 60.0) * 6;
    double second_angle = s * 6;

    double Prev_hour_angle = (prev[0] % 12) * 30 + (prev[1] / 60.0) * 30 + (prev[2] / 3600.0) * 30;
    double Prev_minute_angle = prev[1] * 6 + (prev[2] / 60.0) * 6;
    double Prev_second_angle = prev[2] * 6;
   
    if (hour_angle < Prev_hour_angle) { hour_angle += Prev_hour_angle + (360 - Prev_hour_angle); }
    if (minute_angle < Prev_minute_angle) { minute_angle += Prev_minute_angle + (360 - Prev_minute_angle); }
    if (second_angle < Prev_second_angle) { second_angle += Prev_second_angle + (360 - Prev_second_angle); }

    // 12시 정각
    if(second_angle == hour_angle && second_angle == minute_angle)
        return ++alarm;

    // 초침과 시침이 겹치는 경우
    if (abs(second_angle >= hour_angle) && abs(Prev_second_angle < Prev_hour_angle))
        ++alarm;

    // 초침과 분침이 겹치는 경우
    if (abs(second_angle >= minute_angle) && abs(Prev_second_angle < Prev_minute_angle))
        ++alarm;

    return alarm;
}

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int count = 0;

    // 시작 시간 (초 단위로 변환)
    int start_time = h1 * 3600 + m1 * 60 + s1;
    int end_time = h2 * 3600 + m2 * 60 + s2;
    vector<int> prev = { h1,m1,s1 };
    for (int t = start_time; t <= end_time; ++t) {
        int h = (t / 3600) % 24; // 시
        int m = (t / 60) % 60;   // 분
        int s = t % 60;          // 초

        int alarm = isOverlap(h, m, s, prev);
        if (alarm != 0) {
            count += alarm;
        }
        prev = { h, m, s };
    }

    return count;
}

int main()
{
    solution(12, 0, 0, 12, 0, 30);
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
