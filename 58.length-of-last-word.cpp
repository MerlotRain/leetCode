/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 *
 * https://leetcode.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (47.00%)
 * Likes:    4280
 * Dislikes: 219
 * Total Accepted:    1.5M
 * Total Submissions: 3.1M
 * Testcase Example:  '"Hello World"'
 *
 * Given a string s consisting of words and spaces, return the length of the
 * last word in the string.
 *
 * A word is a maximal substring consisting of non-space characters only.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "Hello World"
 * Output: 5
 * Explanation: The last word is "World" with length 5.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "   fly me   to   the moon  "
 * Output: 4
 * Explanation: The last word is "moon" with length 4.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "luffy is still joyboy"
 * Output: 6
 * Explanation: The last word is "joyboy" with length 6.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^4
 * s consists of only English letters and spaces ' '.
 * There will be at least one word in s.
 *
 *
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
  int lengthOfLastWord(string str) {

    const char *s = str.c_str();
    if (!s || !*s)
      return 0;

    int wordLen = 0;
    int cnt = 0;

    for (; *s != '\0'; s++) {
      if (isalpha(*s)) {
        cnt++;
      }
      if (!isalpha(*s)) {
        if (cnt > 0) {
          wordLen = cnt;
        }
        cnt = 0;
      }
    }

    return cnt > 0 ? cnt : wordLen;
  }
};
// @lc code=end
