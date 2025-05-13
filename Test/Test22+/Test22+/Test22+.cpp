#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) 
{
    vector<vector<int>> answer;
    unordered_map<string, int> name_to_idx;
    name_to_idx["code"] = 0;
    name_to_idx["date"] = 1;
    name_to_idx["maximum"] = 2;
    name_to_idx["remain"] = 3;

    auto it = remove_if(data.begin(), data.end(), [idx = name_to_idx[ext], val_ext](const auto& row) {
        return !(row[idx] < val_ext);
        });
    data.erase(it, data.end());

    sort(data.begin(), data.end(), [idx = name_to_idx[sort_by]](const auto& row1, const auto& row2) {
        return row1[idx] < row2[idx];
        });
    return data;
}

int main()
{
    vector<vector<int>> _data = { {1, 20300104, 100, 80},{2, 20300804, 847, 37},{3, 20300401, 10, 8} };

    solution(_data, "date", 20300501, "remain");
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
