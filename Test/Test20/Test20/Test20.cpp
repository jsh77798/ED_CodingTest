
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    int rows = attacks.size();
    int myhealth = health;
    bool AttackCheck = false;
    int CastingTime = 0;

    for (int t = 0; t <= attacks[rows - 1][0]; t++)
    {
        for (int i = 0; i < attacks.size(); i++) {
            if (t == attacks[i][0]) {
                myhealth -= attacks[i][1];
                AttackCheck = true;
                CastingTime = 0;
            }
        }

        if (myhealth <= 0) 
        {
            answer = -1;
            return answer;
        }

        if (AttackCheck == false && myhealth != health) {
            myhealth += bandage[1];
            CastingTime++;
            if (CastingTime == bandage[0]) {
                myhealth += bandage[2];
                CastingTime = 0;
            }
            if (myhealth >= health) {
                myhealth = health;
            }
        }

        AttackCheck = false;
    }

    answer = myhealth;
    return answer;
}

int main()
{
    vector<int> _bandage = { 5, 1, 5 }; //시전시간, 1초당 회복량, 추가 회복량
    int _health = 30; //최대체력
    vector<vector<int>> _attacks = { {2, 10},{9, 15},{10, 5},{11, 5} }; //공격시간, 피해량

    int an = solution(_bandage, _health, _attacks);
}

