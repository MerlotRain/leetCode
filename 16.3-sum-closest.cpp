/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (45.49%)
 * Likes:    9970
 * Dislikes: 525
 * Total Accepted:    1.1M
 * Total Submissions: 2.4M
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an integer array nums of length n and an integer target, find three
 * integers in nums such that the sum is closest to target.
 *
 * Return the sum of the three integers.
 *
 * You may assume that each input would have exactly one solution.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [-1,2,1,-4], target = 1
 * Output: 2
 * Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0,0,0], target = 1
 * Output: 0
 * Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 =
 * 0).
 *
 *
 *
 * Constraints:
 *
 *
 * 3 <= nums.length <= 500
 * -1000 <= nums[i] <= 1000
 * -10^4 <= target <= 10^4
 *
 *
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  int threeSumClosest(vector<int> &nums, int target) {
    if (nums.size() < 3)
      return 0;

    std::sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n - 2; i++) {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
        int a = nums[i];
        int low = i+1;
        int high = n-1;
        while (low < high)
        {
            int b = nums[low];
            int c = nums[high];
            if(a+b+c == target) {
                return 0;
            } else if(a +b + c > target) {
                
            }
        }
        
    }
  }
};
// @lc code=end
