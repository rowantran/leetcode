/**
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 * You are given a target value to search. If found in the array return its index, otherwise return -1.
 * You may assume no duplicate exists in the array.
 * Your algorithm's runtime complexity must be in the order of O(log n).
 */


typedef vector<int>::size_type vec_size;
typedef vector<int>::difference_type vec_diff;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }
        if (nums.size() == 1) {
            if (nums[0] == target) {
                return 0;
            } else {
                return -1;
            }
        }

        int pivot = pivot_point(nums); 

        int left, right;
        int mid;
        if (target >= nums[0]) {
            left = 0;
            if (pivot > 0) {
                right = pivot - 1;
            } else {
                right = nums.size() - 1;
            }
        } else {
            left = pivot;
            right = nums.size() - 1;
        }

        while (left <= right) {
            mid = left + (right - left) / 2;
            if (target == nums[mid]) {
                return mid;
            } else if (target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return -1;
    }

private:
    int pivot_point(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2; 
            if (mid < right && nums[mid] > nums[mid+1]) {
                return mid+1;
            } else if (mid > left && nums[mid] < nums[mid-1]) {
                return mid-1;
            } else if (nums[mid] > nums[left]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return 0;
    }
};
