#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//오름차순 정렬
vector<vector<int>> f_by(int i, vector<vector<int>> data)
{
    vector<vector<int>> N_data = data;
    sort(N_data.begin(), N_data.end(), [i](const vector<int>& a, const vector<int>& b){
        return a[i] < b[i];
    });

    return N_data;
}

//데이터 추출
vector<vector<int>> f_ext(int i ,int val_ext, vector<vector<int>> data)
{
    vector<vector<int>> N_data;

    for (int j = 0; j < data.size(); j++) {
        if (data[j][i] < val_ext) {
            N_data.push_back({ data[j] });
        }
    }
    return N_data;
}


vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    vector<string> data_name = { "code","date","maximum","remain" };
    int _ext = 0;
    int _sort_by = 0;

    for (int i = 0; i < data_name.size(); i++) {
        if (data_name[i] == ext) {
            _ext = i;
        }
        if (data_name[i] == sort_by) {
            _sort_by = i;
        }
    }

    answer = f_by(_sort_by, f_ext(_ext, val_ext, data));

    return answer;
}

int main()
{
    vector<vector<int>> _data = { {1, 20300104, 100, 80},{2, 20300804, 847, 37},{3, 20300401, 10, 8} };

    solution(_data,"date",20300501,"remain");
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
