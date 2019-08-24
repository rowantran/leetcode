/**
 * Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * If the target is not found in the array, return [-1, -1].
 */

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        bool left_bound_found = false, right_bound_found = false;
        int left_bound, right_bound;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                if (nums[mid-1] != target && nums[mid+1] != target) {
                    vector<int> range = {mid, mid};
                    return range;
                } else if (nums[mid] == target && nums[mid-1] != target && nums[mid+1] == target) {
                    left_bound = mid;
                    left_bound_found = true;
                    left = mid;
                } else {
                    right_bound = mid;
                    right_bound_found = true;
                    right = mid;
                }
            } else if (nums[mid] < target) {
                left = mid;
            } else {
                right = mid;
            }
        }

        if (left_bound_found) {
            right_bound = left;
        } else if (right_bound_found) {
            left_bound = right;
        }

        if (left_bound_found || right_bound_found) {
            vector<int> range = {left_bound, right_bound};
            return range;
        }

        vector<int> not_found_range = {-1, 1};
        return not_found_range;
    }
};
