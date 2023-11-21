/*
 * @lc app=leetcode id=679 lang=cpp
 *
 * [679] 24 Game
 *
 * https://leetcode.com/problems/24-game/description/
 *
 * algorithms
 * Hard (49.22%)
 * Likes:    1423
 * Dislikes: 240
 * Total Accepted:    74.2K
 * Total Submissions: 150.8K
 * Testcase Example:  '[4,1,8,7]'
 *
 * You are given an integer array cards of length 4. You have four cards, each
 * containing a number in the range [1, 9]. You should arrange the numbers on
 * these cards in a mathematical expression using the operators ['+', '-', '*',
 * '/'] and the parentheses '(' and ')' to get the value 24.
 *
 * You are restricted with the following rules:
 *
 *
 * The division operator '/' represents real division, not integer
 * division.
 *
 *
 * For example, 4 / (1 - 2 / 3) = 4 / (1 / 3) = 12.
 *
 *
 * Every operation done is between two numbers. In particular, we cannot use
 * '-' as a unary operator.
 *
 * For example, if cards = [1, 1, 1, 1], the expression "-1 - 1 - 1 - 1" is not
 * allowed.
 *
 *
 * You cannot concatenate numbers together
 *
 * For example, if cards = [1, 2, 1, 2], the expression "12 + 12" is not
 * valid.
 *
 *
 *
 *
 * Return true if you can get such expression that evaluates to 24, and false
 * otherwise.
 *
 *
 * Example 1:
 *
 *
 * Input: cards = [4,1,8,7]
 * Output: true
 * Explanation: (8-4) * (7-1) = 24
 *
 *
 * Example 2:
 *
 *
 * Input: cards = [1,2,1,2]
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * cards.length == 4
 * 1 <= cards[i] <= 9
 *
 *
 */

// @lc code=start
#include <float.h>
#include <vector>

using namespace std;

class Solution {
  bool can = false;

public:
  void check(vector<double> &nums) {
    if (can)
      return;
    if (nums.size() == 1) {
      if (fabs(nums[0] - 24) < FLT_EPSILON)
        can = true;
      return;
    }

    for (int i = 0; i < nums.size(); i++) {
      for (int j = 0; j < nums.size(); j++) {
        if (i == j)
          continue;
        vector<double> temp;
        for (int k = 0; k < nums.size(); k++)
          if (k != i && k != j)
            temp.push_back(nums[k]); // 剩余数字直接放进数组
            // + * - /
        for (int k = 0; k < 4; k++) {
          if (k < 2 && i > j)
            continue; // + * 法满足交换律
          if (k == 0)
            temp.push_back(nums[i] + nums[j]);
          else if (k == 1)
            temp.push_back(nums[i] * nums[j]);
          else if (k == 2)
            temp.push_back(nums[i] - nums[j]);
          else
            temp.push_back(nums[i] / nums[j]);
          check(temp);
          temp.pop_back(); // 回溯
        }
      }
    }
  }

  bool judgePoint24(vector<int> &cards) {
    vector<double> number(4);
    for (int i = 0; i < 4; ++i)
      number[i] = double(cards[i]);
    check(number);
    return can;
  }
};
// @lc code=end
