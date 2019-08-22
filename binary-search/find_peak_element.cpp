/**
 * A peak element is an element that is greater than its neighbors.
 * Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.
 * The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
 * You may imagine that nums[-1] = nums[n] = -∞.
 */

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }

        int left = 0;
        int right = nums.size();
        int mid;

        while (left < right) {
            mid = left + (right - left) / 2;

            if (mid == 0) {
                if (nums[mid] > nums[mid+1]) {
                    return mid;
                } else {
                    return mid+1;
                }
            }

            if (nums[mid] > nums[mid-1]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left-1;
    }
};
