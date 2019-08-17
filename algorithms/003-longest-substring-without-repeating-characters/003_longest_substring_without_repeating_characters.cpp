/*
 * Given a string, find the length of the longest substring without repeating characters.
 */

#include <algorithm>

using std::count;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string::size_type max_length = 0;
        for (string::size_type i = 0; i < s.size(); i++) {
            for (string::size_type j = i + max_length + 1; j <= s.size(); j++) {
                string substring = s.substr(i, j-i);
                if (!has_repeating_characters(substring)) {
                    max_length = substring.size();
                }
            }
        }

        return max_length;
    }

private:
    bool has_repeating_characters(string s) {
        for (char c : s) {
            if (count(s.begin(), s.end(), c) > 1) {
                return true;
            }
        }

        return false;
    }
};
