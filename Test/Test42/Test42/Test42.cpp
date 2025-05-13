
#include <string>
#include <vector>
#include <cmath>

using namespace std;

/*

  원의 방정식
  원의 방정식은 원점 (0, 0)을 중심으로 하는 원에 대해 다음과 같이 나타낼 수 있습니다:
  x^2 + y^2 = r^2
 
  - x와 y는 원의 선, 한 점의 좌표입니다.
  - r은 원의 반지름입니다.
  - r^2는 반지름의 제곱입니다.

*/

// 나의 풀이
long long solution(int r1, int r2) {
    long long answer = 0;
    long long r1Squared = (long long)r1 * r1;
    long long r2Squared = (long long)r2 * r2;

    for (int x = 0; x <= r2; ++x) {
        double maxY = floor(sqrt(r2Squared - (long long)x * x)); // floor -> 실수의 "내림값"
        double minY = ceil(sqrt(r1Squared - (long long)x * x));  // ceil -> 실수의 "오름값"

        if (isnan(minY)) { minY = 0; }

        if (maxY == minY) { answer++; }
        else { answer += (maxY - minY + 1); }

        if (maxY <= 0 || minY <= 0) { answer -= 1; }
    }
    answer *= 4;
    return answer;
}

// 다른 풀이
long long solution2(int r1, int r2) {
    long long answer = 0;

    for (int t = 1; t <= r2; ++t)
    {
        int h2 = floor(sqrt(pow(r2, 2) - pow(t, 2))); // pow -> pow(base, exponent)는 base를 exponent만큼 거듭제곱한 결과를 반환
        int h1 = (t < r1) ? ceil(sqrt(pow(r1, 2) - pow(t, 2))) : 0;
        answer += h2 - h1 + 1;
    }
    return 4 * answer;
}

int main()
{
    long long a = solution(2, 3);
    long long b = solution2(2, 3);
}
