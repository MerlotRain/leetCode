/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        std::unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); ++i) {
            m.insert({nums.at(i), i});
        }

        vector<int> result;
        for (size_t i = 0; i < nums.size(); i++)
        {
            int diff = target - nums[i];
            auto it = m.find(diff);
            if(it != m.end() && it->second != i) {

                result.push_back(i);
                result.push_back(it->second);
                return result;
            }
        }
        return result;
    }
};
// @lc code=end
