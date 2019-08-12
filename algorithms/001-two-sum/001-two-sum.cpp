#include <unordered_map>
#include <utility>
#include <vector>

using std::unordered_map;
using std::vector;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> nums_map;
        for (vector<int>::const_iterator it = nums.begin();
                it != nums.end(); it++) {
            nums_map.insert(std::make_pair(*it, it - nums.begin()));
        }

        for (vector<int>::const_iterator it = nums.begin();
                it != nums.end(); it++) {
            std::unordered_map<int, int>::iterator match = nums_map.find(
                target - *it);
            if (match != nums_map.end()) {
                int i = it - nums.begin();
                int j = std::get<1>(*match);

                vector<int> solution;
                solution.push_back(i);
                solution.push_back(j);

                return solution;
            }
        }
    }
};
