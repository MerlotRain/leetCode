/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (33.26%)
 * Likes:    27993
 * Dislikes: 1659
 * Total Accepted:    2.7M
 * Total Submissions: 8.2M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, return the longest palindromic substring in s.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "babad"
 * Output: "bab"
 * Explanation: "aba" is also a valid answer.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "cbbd"
 * Output: "bb"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 1000
 * s consist of only digits and English letters.
 *
 *
 */

#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  // abc
  // #a#b#c#
  string manacherString(string s) {
    string str = "#";
    for (int i = 0; i < s.size(); i++) {
      str.push_back(s.at(i));
      str.push_back('#');
    }
    return str;
  }

  string longestPalindrome(string s) {
    if (s.length() == 0)
      return string();

    string str = manacherString(s);
    std::vector<int> pArray(str.size());
    int c = -1; // 回文中心点
    int r = -1; // 回文右边界+1，实际的边界是r-1
    int max = INT_MIN;
    for (int i = 0; i < str.length(); i++) {
      pArray[i] = r > i ? std::min(pArray[2 * c - r], r - i) : 1;
      // 如果r <= i，说明要往外扩，不需要验证的范围就是1
      // 如果r > i，说明不用往外扩展，不需要验证的范围 std::min(pArray[2 * c -
      // r], r - i)

      while (i + pArray[i] < str.length() && i - pArray[i] > -1) {
        if (str[i - pArray[i]] == str[i + pArray[i]]) {
          pArray[i]++;
        } else {
          break;
        }
      }
      if (pArray[i] + i > r) {
        r = i + pArray[i];
        c = i;
      }
      max = std::max(max, pArray[i]);
    }
    return s.substr(c - r, max);
  }
};
// @lc code=end
