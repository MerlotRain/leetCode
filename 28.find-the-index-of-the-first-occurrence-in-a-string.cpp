/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Find the Index of the First Occurrence in a String
 *
 * https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
 *
 * algorithms
 * Easy (40.92%)
 * Likes:    5082
 * Dislikes: 305
 * Total Accepted:    2.1M
 * Total Submissions: 5.1M
 * Testcase Example:  '"sadbutsad"\n"sad"'
 *
 * Given two strings needle and haystack, return the index of the first
 * occurrence of needle in haystack, or -1 if needle is not part of
 * haystack.
 *
 *
 * Example 1:
 *
 *
 * Input: haystack = "sadbutsad", needle = "sad"
 * Output: 0
 * Explanation: "sad" occurs at index 0 and 6.
 * The first occurrence is at index 0, so we return 0.
 *
 *
 * Example 2:
 *
 *
 * Input: haystack = "leetcode", needle = "leeto"
 * Output: -1
 * Explanation: "leeto" did not occur in "leetcode", so we return -1.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= haystack.length, needle.length <= 10^4
 * haystack and needle consist of only lowercase English characters.
 *
 *
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {
public:
  int strStr(string haystack, string needle) {
    if (needle.size() < 1 || haystack.size() < needle.size()) {
      return -1;
    }

    int i1 = 0;
    int i2 = 0;
    std::vector<int> next = nextArray(needle);
    while (i1 < haystack.size() && i2 < needle.size()) {
      if (haystack.at(i1) == needle.at(i2)) {
        i1++;
        i2++;
      } else if (next[i2] == -1) {
        i1++;
      } else {
        i2 = next[i2];
      }
    }
    return i2 == needle.length() ? i1 - i2 : -1;
  }

  std::vector<int> nextArray(string str) {
    std::vector<int> res;
    if (str.length() == 1) {
      res.push_back(-1);
    }
    res.reserve(str.length());
    // a b b e a b b s
    //     b
    // a b
    int i = 2;
    int cur = 0;
    res[0] = -1;
    res[1] = 0;
    while (i < str.length()) {
      if (str.at(i - 1) == str.at(cur)) {
        res[i++] = ++cur;
      } else if (cur > 0) {
        cur = res[cur];
      } else {
        res[i++] = 0;
      }
    }
    return res;
  }
};
// @lc code=end
