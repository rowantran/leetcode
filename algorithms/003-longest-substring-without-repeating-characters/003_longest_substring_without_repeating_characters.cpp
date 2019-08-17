/*
 * Given a string, find the length of the longest substring without repeating characters.
 */

#include <algorithm>
#include <unordered_set>

using std::unordered_set;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string::size_type max_length = 0;
        for (string::size_type i = 0; i < s.size(); i++) {
            unordered_set<char> chars;
            string::size_type j = i;
            while (j < s.size() && !chars.count(s[j])) {
                chars.insert(s[j]);
                ++j;
            }

            max_length = std::max(max_length, j - i);
        }

        return max_length;
    }
};
