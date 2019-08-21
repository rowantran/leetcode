class Solution {
public:
    int search(vector<int>& nums, int target) {
        vector<int>::difference_type left = 0;
        vector<int>::difference_type right = nums.size() - 1;
        vector<int>::size_type mid;

        while (left <= right) {
            mid = (left + right) / 2;

            if (target > nums[mid]) {
                left = mid + 1;
            } else if (target < nums[mid]) {
                right = mid - 1;
            } else {
                return mid;
            }
        }

        return -1;
    }
};
