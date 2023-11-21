/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (41.77%)
 * Likes:    16332
 * Dislikes: 4298
 * Total Accepted:    2.8M
 * Total Submissions: 6.8M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 *
 * If there is no common prefix, return an empty string "".
 *
 *
 * Example 1:
 *
 *
 * Input: strs = ["flower","flow","flight"]
 * Output: "fl"
 *
 *
 * Example 2:
 *
 *
 * Input: strs = ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= strs.length <= 200
 * 0 <= strs[i].length <= 200
 * strs[i] consists of only lowercase English letters.
 *
 *
 */

// @lc code=start
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    if (strs.size() == 0)
      return "";

    if (strs.size() == 1)
      return strs.at(0);

    string res;
    string fist = strs.at(0);
    for (int i = 0; i < fist.size(); i++) {
      // 找到第一个字符
      char ch = fist.at(i);

      // 判断第一个字符是否是其他字符串相同位置的痣
      for (auto &str : strs) {
        if (str.size() < i + 1 || str.at(i) != ch)
          return res;
      }
      res.push_back(ch);
    }
    return res;
  }
};
// @lc code=end
