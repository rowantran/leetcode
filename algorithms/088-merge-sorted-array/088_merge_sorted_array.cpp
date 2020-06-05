// #88: Merge Sorted Array
//
// Rowan Tran
//
// Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
//
// Note:
//     The number of elements initialized in nums1 and nums2 are m and n respectively.
//     You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold
//       additional elements from nums2.

class Solution {
public:
    // Shifts all elements in the vector starting at index n, 1 index forward. Used to make room
    // for the element to be inserted.
    void shift(vector<int>& vec, int n) {
        for (size_t i = vec.size() - 1; i > n; --i) {
            vec[i] = vec[i-1];
        }
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        size_t total_size = m;
        size_t i_dest = 0;
        size_t i_source = 0;

        while (i_source < n) {
            // Search for the appropriate index to insert the current element from nums2.
            while ((i_dest < total_size) && (nums1[i_dest] < nums2[i_source])) {
                ++i_dest;
            }

            // i_dest is now either the first element that is >= the desired element, or the index
            // past the end of the current array, so we can insert here.
            shift(nums1, i_dest);
            nums1[i_dest] = nums2[i_source];
            ++total_size;
            ++i_source;
        }
    }
};
