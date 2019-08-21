/*
 * Implement int sqrt(int x).
 * Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
 * Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.
 */

class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) {
            return x;
        }

        int left = 1;
        int right = x-1;
        long mid;

        int answer;

        while (left <= right) {
            mid = left + (right - left) / 2;
            long square = mid*mid;
            if (square == x) {
                // Perfect square found
                return mid;
            } else if (square < x) {
                left = mid + 1;
                answer = mid;
            } else {
                right = mid - 1;
            }
        }

        return answer;
    }
};
