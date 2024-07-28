#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;

/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
*/

vector<vector<int>> threeSum(vector<int> &nums)
{
    std::sort(nums.begin(), nums.end());
    set<vector<int>> set;
    vector<vector<int>> sol;
    for (size_t i = 0; i < nums.size(); i++)
    {
        size_t j = i + 1;
        size_t k = nums.size() - 1;
        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == 0)
            {
                set.insert({nums[i], nums[j], nums[k]});
                j++;
                k--;
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                j++;
            }
        }
    }
    for (auto triplets : set)
        sol.push_back(triplets);
    return sol;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
