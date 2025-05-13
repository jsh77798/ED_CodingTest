#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) 
{
    int rows = park.size(); //세로
    int cols = park[0].size(); //가로
    vector<vector<int>> grid(rows, vector<int>(cols, 0)); //cols: 벡터의 크기를 지정합니다. 즉, 벡터에 들어갈 요소의 개수를 의미합니다. 0: 벡터의 각 요소를 초기화할 값을 지정합니다.
                                                          //즉 { 0,0,0,0,0,0,0,0 }

    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            if (park[i][j] == "-1") 
            {
                grid[i][j] = 0;  // free
            }
            else 
            {
                grid[i][j] = 1;  // blocked
            }
        }
    }

    sort(mats.begin(), mats.end(), greater<int>()); //내림차순 정렬

    // 람다함수(캡쳐부분에 & -> 전체 참조 캡처: 외부의 모든 변수를 참조로 캡처합니다. 모든변수에 대한 참조를 캡처하므로, 
    // 람다 내부에서 변수를 변경하면 외부의 변수에도 영향을 미칩니다.)
    auto canPlaceMat = [&](int s, int i, int j) 
    {
        if (i + s > rows || j + s > cols) return false;  
        for (int r = i; r < i + s; ++r) 
        {
            for (int c = j; c < j + s; ++c) 
            {
                if (grid[r][c] == 1) return false;  
            }
        }
        return true;
    };

    //범위 기반 for 루프(mats의 모든요소를 처음부터 끝까지 순회한다,int s에 요소를 for문이 돌때마다 하나씩 대입한다)
    for (int s : mats) 
    {
        for (int i = 0; i <= rows - s; ++i) 
        {
            for (int j = 0; j <= cols - s; ++j) 
            {
                if (canPlaceMat(s, i, j)) 
                {
                    return s;  
                }
            }
        }
    }

    return -1;  
}

int main()
{
    vector<int> mats = { 5, 3, 2 };
    vector<vector<string>> park = {
        {"A", "A", "-1", "B", "B", "B", "B", "-1"},
        {"A", "A", "-1", "B", "B", "B", "B", "-1"},
        {"-1", "-1", "-1", "-1", "-1", "-1", "-1", "-1"},
        {"D", "D", "-1", "-1", "-1", "-1", "E", "-1"},
        {"D", "D", "-1", "-1", "-1", "-1", "-1", "F"},
        {"D", "D", "-1", "-1", "-1", "-1", "E", "-1"}
    };
    int an = solution(mats, park);
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
