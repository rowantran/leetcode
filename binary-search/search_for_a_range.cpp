/**
 * Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * If the target is not found in the array, return [-1, -1].
 */

#include <algorithm>

using std::max;
using std::min;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) {
            vector<int> range = {-1, -1};
            return range;
        } else if (nums.size() == 1 && nums[0] == target) {
            vector<int> range = {0, 0};
            return range;
        }

        int left = 0, right = nums.size() - 1;
        int left_bound = -1, right_bound = -1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                if (nums[mid-1] != target && nums[mid+1] != target) {
                    vector<int> range = {mid, mid};
                    return range;
                } else if (nums[mid] == target && nums[mid-1] == target && nums[mid+1] != target) {
                    right_bound = mid;
                    right = mid;
                } else if (nums[mid] == target && nums[mid-1] != target && nums[mid+1] == target) {
                    left_bound = mid;
                    left = mid;
                } else {
                    right_bound = mid+1;
                    right = mid;
                }
            } else if (nums[mid] < target) {
                left = mid;
            } else {
                right = mid;
            }
        }

        vector<int> indices_to_check = {left, right};
        for (int i : indices_to_check) {
            if (nums[i] == target) {
                if (left_bound != -1) {
                    left_bound = min(left_bound, i);
                } else {
                    left_bound = i;
                }
                right_bound = max(right_bound, i);
            }
        }

        vector<int> range = {left_bound, right_bound};
        return range;
    }
};
