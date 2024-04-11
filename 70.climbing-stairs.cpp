/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 *
 * https://leetcode.com/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (52.24%)
 * Likes:    20426
 * Dislikes: 697
 * Total Accepted:    2.8M
 * Total Submissions: 5.3M
 * Testcase Example:  '2'
 *
 * You are climbing a staircase. It takes n steps to reach the top.
 *
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can
 * you climb to the top?
 *
 *
 * Example 1:
 *
 *
 * Input: n = 2
 * Output: 2
 * Explanation: There are two ways to climb to the top.
 * 1. 1 step + 1 step
 * 2. 2 steps
 *
 *
 * Example 2:
 *
 *
 * Input: n = 3
 * Output: 3
 * Explanation: There are three ways to climb to the top.
 * 1. 1 step + 1 step + 1 step
 * 2. 1 step + 2 steps
 * 3. 2 steps + 1 step
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 45
 *
 *
 */

// @lc code=start
class Solution {
public:
  int steps(int n) {
    if (n == 1) {
      return 1;
    } else if (n == 2) {
      return 2;
    } else {
      return steps(n - 1) + steps(n - 2);
    }
  }

  int climbStairs(int n) { return steps(n); }
};

/**
 * @brief 
 * Qt 框架
 * 1、2.0 
 * 
 * 1、类的设计上
 * 
 * 
 */
// @lc code=end
