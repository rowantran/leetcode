// You are given a sorted array consisting of only integers where every element appears exactly
// twice, except for one element which appears exactly once. Find this single element that
// appears only once.
//
// Follow up: Your solution should run in O(log n) time and O(1) space.

class Solution {
public:
    typedef vector<int>::size_type size_v;

    int singleNonDuplicateHelper(const vector<int>& nums, size_v low, size_v high) {
        size_v mid = ((low + high) / 4) * 2;

        if (low == high) return nums[low];

        // Since every integer appears twice in the array, if we examine any integer at index n,
        // that integer is either the first member of its pair, in which case the same integer
        // will be found at index n+1, or it is the second member of its pair, in which case
        // the same integer will be found at index n-1. Or, if neither of those conditions are
        // true, the integer at index n is the lone integer.
        //
        // Furthermore, if the middle index of the initial array is the first member of its pair,
        // the lone integer must be at an index to the left. Conversely, if the middle index is the
        // second member of its pair, the lone integer must be at an index to the right.
        if (nums[mid] == nums[mid+1]) {
            return singleNonDuplicateHelper(nums, low, mid-1);
        } else if (nums[mid] == nums[mid-1]) {
            return singleNonDuplicateHelper(nums, mid+1, high);
        } else {
            return nums[mid];
        }  
    }

    int singleNonDuplicate(vector<int>& nums) {
        return singleNonDuplicateHelper(nums, 0, nums.size() - 1);
    }
};
