#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;

// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.

// Example 1:

// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

// Two pointer technique pseudo: 
// 1. Do the same thing as 3Sum problem but with nested for loop (O(N^3))

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    std::sort(nums.begin(), nums.end());
    set<vector<int>> s;
    vector<vector<int>> sol;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            int k = j + 1;
            int l = nums.size() - 1;
            while (k < l)
            {
                long long int sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];
                if (sum == target)
                {
                    s.insert({nums[i], nums[j], nums[k], nums[l]});
                    k++;
                    l--;
                }
                else if (sum < target)
                {
                    k++;
                }
                else
                {
                    l--;
                }
            }
        }
    }
    for (auto i : s)
    {
        sol.push_back(i);
    }
    return sol;
}

int main(int argc, char const *argv[])
{

    return 0;
}
