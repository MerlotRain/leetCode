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
  /**
   *   d a b a b
   * b 0 0 1 0 1
   * a 0 1 0 2 0
   * b 0 0 2 0 3
   * a 0 1 0 3 0
   * d 1 0 0 0 0
   * i=1,j=1;
   */

  /// @brief babad dabab
  /// @param s
  /// @return
  string longestPalindrome(string s) {
    int n = s.size(); // 5
    if (n <= 1)
      return s;

    int max = 0, end = 0;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) { // b // d, a, b, d, b
      //       0  1  2  3  4
      for (int j = 0; j < n; j++) {
        if (s[i] == s[n - j - 1]) {
          if (i == 0 || j == 0)
            matrix[i][j] = 1;
          else
            matrix[i][j] = matrix[i - 1][j - 1] + 1;
        } else {
          matrix[i][j] = 0;
        }

        if (matrix[i][j] > max) {
          max = matrix[i][j];
          end = i;
        }
      }
    }
    return s.substr(end - max + 1, max);
  }
};
// @lc code=end
