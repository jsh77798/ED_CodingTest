
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer(targets.size());
    map<string, int> num_to_idx;
    for (int i = 0; i < keymap.size(); i++) {
        int j = 1;
        for (char c : keymap[i]) {
            num_to_idx.insert({ string(1, c),j });
            if (num_to_idx[string(1, c)] > j) {
                num_to_idx[string(1, c)] = j;
            }
            j++;
        }
    }

    for (int i = 0; i < targets.size(); i++) {
        for (char c : targets[i]) {
            auto it = num_to_idx.find(string(1, c));
            if (it != num_to_idx.end()) {
                answer[i] += num_to_idx[string(1, c)];
            }
            else 
            {
                answer[i] = -1;
                break;
            }
        }
    }

    return answer;
}

int main()
{
    vector<string> _keymap = { "ABACD", "BCEFD" };
    vector<string> _targets = { "ABCD","AABB" };
    solution(_keymap, _targets);

}

