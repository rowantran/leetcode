#include <unordered_map>
#include <utility>
#include <vector>

using std::unordered_map;
using std::vector;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> nums_map;
        vector<int> solution;

        for (int i = 0; i < nums.size(); i++) {
            std::unordered_map<int, int>::value_type pair(nums[i], i);
            nums_map.insert(pair);
        }

        for (vector<int>::const_iterator it = nums.begin();
                it != nums.end(); it++) {
            std::unordered_map<int, int>::iterator match = nums_map.find(
                target - *it);
            if (match != nums_map.end()) {
                int i = it - nums.begin();
                int j = std::get<1>(*match);

                if (i != j) {
                    solution.push_back(i);
                    solution.push_back(j);

                    return solution;
                }
            }
        }

        return solution;
    }
};
