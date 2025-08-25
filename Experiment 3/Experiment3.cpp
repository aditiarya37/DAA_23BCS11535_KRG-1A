#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
  public:
    vector<vector<int>> countFreq(vector<int>& arr) {
        unordered_map<int, int> freqMap;
        for (int num : arr) {
            freqMap[num]++;
        }
        vector<vector<int>> result;
        for (auto& entry : freqMap) {
            result.push_back({entry.first, entry.second});
        }
        return result;
    }
};
int main() {
    Solution sol;
    vector<int> arr = {1, 2, 2, 3, 1, 4, 2, 3, 5};
    vector<vector<int>> ans = sol.countFreq(arr);
    cout << "Frequency of elements:" << endl;
    for (auto& v : ans) {
        cout << v[0] << " -> " << v[1] << endl;
    }
    return 0;
}
