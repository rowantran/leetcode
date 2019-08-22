/**
 * You are a product manager and currently leading a team to develop a new product.
 * Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.
 * Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.
 * You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.
 */

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if (n == 1) {
            return n;
        }

        int left = 1;
        long right = (long) n + 1;
        int mid;

        while (left < right) {
            mid = left + (right - left) / 2;
            if (isBadVersion(mid) && !isBadVersion(mid-1)) {
                return mid;
            } else if (isBadVersion(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        // Post-processing: left/right denotes the final element
        return left; 
    }
};
