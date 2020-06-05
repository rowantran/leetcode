// #540: Single Element in a Sorted Array
//
// Rowan Tran
//
// You are given a sorted array consisting of only integers where every element appears exactly
// twice, except for one element which appears exactly once. Find this single element that
// appears only once.
//
// Follow up: Your solution should run in O(log n) time and O(1) space.

class Solution {
public:
    typedef vector<int>::size_type size_v;

    // This function calculates an appropriate "middle" value to use when searching the array.
    // The logic behind subtracting 1 is explained in singleNonDuplicateHelper.
    size_v find_mid(size_v low, size_v high) {
        size_v mid = (low + high) / 2;
        if ((mid % 2) != 0) {
            return mid;
        } else {
            return mid - 1;
        }
    }

    // This function recursively searches the array from [low, high] for the lone integer.
    // The logic behind the search is explained in the function.
    int singleNonDuplicateHelper(const vector<int>& nums, size_v low, size_v high) {
        // This base condition works because [low, high] has an odd number of elements
        // at all times.
        if (low == high) return nums[low];

        size_v mid = find_mid(low, high);

        // We want to find either the exact middle element if [0, mid] is an even number of elements,
        // or middle-1 if [0, mid] is an odd number. This ensures that [0, n] where n is either middle
        // or middle-1 has an even number of elements. Then, if there are *only* pairs
        // before the middle element, the middle element will always be the second element of its pair.
        // If the middle element is not the second element of its pair, we know that order has been
        // disturbed *before* the middle element.

        // If the middle element is the first member of its pair, the lone integer must be at an index
        // to the left. Conversely, if the middle element is the second member of its pair, the lone
        // integer must be at an index to the right. And if the middle element is not a member of a
        // pair, then we have found the desired element.
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
