#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    vector<string> _gifts;
    vector<vector<int>> grid(friends.size(), vector<int>(friends.size(), 0));
    vector<int> giftindex(friends.size());
    vector<int> nextgift(friends.size());

   for(int i = 0; i < gifts.size(); i++) {
        stringstream ss(gifts[i]);
        string word;

        while (ss >> word) {
            _gifts.push_back(word);
        }
   }

   //주고받은 선물(grid)
   for (int i = 0; i < friends.size(); i++) {
       
       for (int j = 0; j < _gifts.size()/2; j++) {
           int a = j * 2;
           
           if (_gifts[a] == friends[i]) {
               for (int g = 0; g < friends.size(); g++) {
                   if (_gifts[a + 1] == friends[g]) {
                       grid[i][g] += 1;
                   }
               }
           }
           
       }
   }

   //선물 지수(giftindex)
   for (int i = 0; i < grid.size(); i++) {
       for (int j = 0; j < grid[0].size(); j++){
           if (grid[i][j] > 0) 
           {
               giftindex[i] += grid[i][j];
           }
           giftindex[i] -= grid[j][i];
       }
       
   }

   //다음달 선물
   for (int i = 0; i < grid.size(); i++) {
       for (int j = 0; j < grid[0].size(); j++) {
           if (grid[i][j] > grid[j][i]) 
           {
               nextgift[i] += 1;
           }
           if (grid[i][j] == grid[j][i])
           {
               if (giftindex[i] > giftindex[j]) {
                   nextgift[i] += 1;
               }
           }
       }
   }

    sort(nextgift.begin(), nextgift.end(), std::greater<int>());
    answer = nextgift[0];
    return answer;
}

int main()
{
    vector<string> _friends = { "muzi", "ryan", "frodo", "neo" };
    vector<string> _gifts = { "muzi frodo", "muzi frodo", "ryan muzi", "ryan muzi", "ryan muzi", "frodo muzi", "frodo ryan", "neo muzi" };
    solution(_friends, _gifts);
}
