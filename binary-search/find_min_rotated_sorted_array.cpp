/**
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 * (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
 * Find the minimum element.
 * You may assume no duplicate exists in the array.
 */

class Solution {
public:
    int findMin(vector<int>& nums) {
        return nums[find_pivot(nums)];     
    }

private:
    int find_pivot(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }

        int left = 0;
        int right = nums.size();

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[left]) {
                right = mid;
            } else {
                // nums[mid] < nums[left] as no duplicate exists in array
                left = mid + 1;
            }
        }

        return left-1;
    }
};
