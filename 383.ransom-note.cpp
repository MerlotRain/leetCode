/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 *
 * https://leetcode.com/problems/ransom-note/description/
 *
 * algorithms
 * Easy (59.88%)
 * Likes:    4628
 * Dislikes: 470
 * Total Accepted:    952K
 * Total Submissions: 1.6M
 * Testcase Example:  '"a"\n"b"'
 *
 * Given two strings ransomNote and magazine, return true if ransomNote can be
 * constructed by using the letters from magazine and false otherwise.
 *
 * Each letter in magazine can only be used once in ransomNote.
 *
 *
 * Example 1:
 * Input: ransomNote = "a", magazine = "b"
 * Output: false
 * Example 2:
 * Input: ransomNote = "aa", magazine = "ab"
 * Output: false
 * Example 3:
 * Input: ransomNote = "aa", magazine = "aab"
 * Output: true
 *
 *
 * Constraints:
 *
 *
 * 1 <= ransomNote.length, magazine.length <= 10^5
 * ransomNote and magazine consist of lowercase English letters.
 *
 *
 */

// @lc code=start
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    std::unordered_map<char, int> m;
    for (auto &ch : magazine) {
      m[ch]++;
    }

    for (auto &ch : ransomNote) {
      if (m.find(ch) == m.end()) {
        return false;
      }
      m[ch]--;
      if(m[ch] < 0)
      return false;
    }
    return true;
  }
};
// @lc code=end
