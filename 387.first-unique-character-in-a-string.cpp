/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 *
 * https://leetcode.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (60.28%)
 * Likes:    8316
 * Dislikes: 267
 * Total Accepted:    1.5M
 * Total Submissions: 2.5M
 * Testcase Example:  '"leetcode"'
 *
 * Given a string s, find the first non-repeating character in it and return
 * its index. If it does not exist, return -1.
 *
 *
 * Example 1:
 * Input: s = "leetcode"
 * Output: 0
 * Example 2:
 * Input: s = "loveleetcode"
 * Output: 2
 * Example 3:
 * Input: s = "aabb"
 * Output: -1
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^5
 * s consists of only lowercase English letters.
 *
 *
 */
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
  int firstUniqChar(string s) {
    std::unordered_map<char, int> chmap;
    if (s.empty())
      return -1;

    for (int i = 0; i < s.size(); i++) {
      // 说明之前已经有过这个字符了，
      if (chmap.find(s.at(i)) == chmap.end()) {
        // 记录一下一个字符串出现了
        chmap.insert({s.at(i), -1});
      } else {
        // 说明这个字符出现了多次
        chmap[s.at(i)] = -2;
      }
    }

    int pos = s.size() + 1;
    for (auto it = chmap.begin(); it != chmap.end(); ++it) {
      // 如果这个字母只出现了一次
      if (it->second == -1) {
        pos = std::min(pos, (int)(s.find_first_of(it->first)));
      }
    }
    return pos == s.size() + 1 ? -1 : pos;
  }
};
// @lc code=end
