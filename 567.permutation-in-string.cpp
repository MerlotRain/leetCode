/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 *
 * https://leetcode.com/problems/permutation-in-string/description/
 *
 * algorithms
 * Medium (44.19%)
 * Likes:    10823
 * Dislikes: 359
 * Total Accepted:    755.3K
 * Total Submissions: 1.7M
 * Testcase Example:  '"ab"\n"eidbaooo"'
 *
 * Given two strings s1 and s2, return true if s2 contains a permutation of s1,
 * or false otherwise.
 *
 * In other words, return true if one of s1's permutations is the substring of
 * s2.
 *
 *
 * Example 1:
 *
 *
 * Input: s1 = "ab", s2 = "eidbaooo"
 * Output: true
 * Explanation: s2 contains one permutation of s1 ("ba").
 *
 *
 * Example 2:
 *
 *
 * Input: s1 = "ab", s2 = "eidboaoo"
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s1.length, s2.length <= 10^4
 * s1 and s2 consist of lowercase English letters.
 *
 *
 */
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
  std::vector<std::string> permutation(string str) {
    std::vector<std::string> res;
    if (str.empty())
      return res;

    process(str, 0, res);
    return res;
  }

  void process(string& str, int i, std::vector<string> &res) {
    if (i == str.length())
      res.push_back(str);

      for(int j = 0; j < str.length(); j++) {
        swap(str, i, j);
        process(str, i+1, res);
        swap(str, i, j);
      }
  }

  void swap(string& str, int i, int j) {
    char chi = str.at(i);
    char chj = str.at(j);
    str[i] = chj;
    str[j] = chi;
  }

  bool checkInclusion(string s1, string s2) {
    if (s1.empty() || s2.empty())
      return false;
  }
};
// @lc code=end
