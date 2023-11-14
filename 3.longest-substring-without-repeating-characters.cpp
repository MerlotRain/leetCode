/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (34.14%)
 * Likes:    37797
 * Dislikes: 1713
 * Total Accepted:    5.1M
 * Total Submissions: 15M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string s, find the length of the longest substring without repeating
 * characters.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * Notice that the answer must be a substring, "pwke" is a subsequence and not
 * a substring.
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= s.length <= 5 * 10^4
 * s consists of English letters, digits, symbols and spaces.
 *
 *
 */

#include <map>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    std::map<char, int> m;
    int lastRepeatPos = -1;
    int max = 0;
    for (int i = 0; i < s.size(); i++) {
      if (m.find(s[i]) != m.end() && lastRepeatPos < m[s[i]]) {
        lastRepeatPos = m[s[i]];
      }
      if (i - lastRepeatPos > max) {
        max = i - lastRepeatPos;
      }
      m[s[i]] = i;
    }
    return max;
  }
};
// @lc code=end
