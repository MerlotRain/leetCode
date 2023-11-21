/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (40.21%)
 * Likes:    22654
 * Dislikes: 1565
 * Total Accepted:    4M
 * Total Submissions: 9.9M
 * Testcase Example:  '"()"'
 *
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 *
 * An input string is valid if:
 *
 *
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * Every close bracket has a corresponding open bracket of the same type.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: s = "()"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: s = "()[]{}"
 * Output: true
 *
 *
 * Example 3:
 *
 *
 * Input: s = "(]"
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^4
 * s consists of parentheses only '()[]{}'.
 *
 *
 */

// @lc code=start
#include <map>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  bool isValid(string s) {

//()[]{}
    std::map<char, char> mapping;
    mapping.insert({')', '('});
    mapping.insert({']', '['});
    mapping.insert({'}', '{'});
    if (s.empty())
      return true;

// (
    std::stack<char> stk;
    //stk.push(s.at(0));
    for (int i = 0; i < s.size(); i++) {
      char ch = s.at(i);
      if (!stk.empty() && stk.top() == mapping[ch]) {
        stk.pop();
      } else {
        stk.push(ch);
      }
    }
    return stk.empty();
  }
};
// @lc code=end
