/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (33.56%)
 * Likes:    29042
 * Dislikes: 2629
 * Total Accepted:    3.1M
 * Total Submissions: 9.1M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an integer array nums, return all the triplets [nums[i], nums[j],
 * nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] +
 * nums[k] == 0.
 *
 * Notice that the solution set must not contain duplicate triplets.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [-1,0,1,2,-1,-4]
 * Output: [[-1,-1,2],[-1,0,1]]
 * Explanation:
 * nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
 * nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
 * nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
 * The distinct triplets are [-1,0,1] and [-1,-1,2].
 * Notice that the order of the output and the order of the triplets does not
 * matter.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0,1,1]
 * Output: []
 * Explanation: The only possible triplet does not sum up to 0.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [0,0,0]
 * Output: [[0,0,0]]
 * Explanation: The only possible triplet sums up to 0.
 *
 *
 *
 * Constraints:
 *
 *
 * 3 <= nums.length <= 3000
 * -10^5 <= nums[i] <= 10^5
 *
 *
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> result;

    if (nums.size() < 3)
      return result;

    std::sort(nums.begin(), nums.end());
// -4,-1,-1,0,1,2
    int n = nums.size();
    for (int i = 0; i < n - 2; i++) {
      if (i > 0 && nums[i - 1] == nums[i])
        continue;
      int a = nums[i];
      int low = i + 1;
      int high = n - 1;
      while (low < high) {
        int b = nums[low];
        int c = nums[high];
        if (a + b + c == 0) {
          vector<int> v;
          v.push_back(a);
          v.push_back(b);
          v.push_back(c);
          result.push_back(v);

          while (low < n - 1 && nums[low] == nums[low + 1])
            low++;
          while (high > 0 && nums[high] == nums[high - 1])
            high--;
          low++;
          high--;

        } else if (a + b + c > 0) {
          while (high > 0 && nums[high] == nums[high - 1])
            high--;
          high--;
        } else {
          while (low < n - 1 && nums[low] == nums[low + 1])
            low++;
          low++;
        }
      }
    }
    return result;
  }
};
// @lc code=end
