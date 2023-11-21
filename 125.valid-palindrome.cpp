/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (46.06%)
 * Likes:    8501
 * Dislikes: 8031
 * Total Accepted:    2.5M
 * Total Submissions: 5.3M
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * A phrase is a palindrome if, after converting all uppercase letters into
 * lowercase letters and removing all non-alphanumeric characters, it reads the
 * same forward and backward. Alphanumeric characters include letters and
 * numbers.
 *
 * Given a string s, return true if it is a palindrome, or false otherwise.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "A man, a plan, a canal: Panama"
 * Output: true
 * Explanation: "amanaplanacanalpanama" is a palindrome.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "race a car"
 * Output: false
 * Explanation: "raceacar" is not a palindrome.
 *
 *
 * Example 3:
 *
 *
 * Input: s = " "
 * Output: true
 * Explanation: s is an empty string "" after removing non-alphanumeric
 * characters.
 * Since an empty string reads the same forward and backward, it is a
 * palindrome.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 2 * 10^5
 * s consists only of printable ASCII characters.
 *
 *
 */

// @lc code=start

#include <deque>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
  bool isPalindrome(string s) {

    std::deque<char> deq;
    // race a car
    // r a c ea c a r
    for (int i = 0; i < s.size(); i++) {
      if (isalnum(s.at(i))) {
        deq.push_back(tolower(s.at(i)));
      }
    }

    if (deq.size() == 0 || deq.size() == 1)
      return true;

    while (deq.size() > 1) {
      char ch1 = deq.front();
      char ch2 = deq.back();
      if (ch1 != ch2)
        return false;
      deq.pop_front();
      deq.pop_back();
    }
    return true;
  }
};
// @lc code=end
