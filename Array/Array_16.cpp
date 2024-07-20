#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

// Return the sum of the three integers.

// You may assume that each input would have exactly one solution.

// Example 1:

// Input: nums = [-1,2,1,-4], target = 1
// Output: 2
// Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

// Two pointer technique pseudo: 

// 1. We have 2 main variables, minDiff and cSum. minDiff traks the closest diff of sum and target while cSum is the actual closest sum
// 2. Intialize the double pointer technique in the while loop and adjust j and k relative to how far sum is from target
// 3. The small nuance is if the target != sum at all which means you have to update cSum and minDiff every step along the way 
// 4. If it found the target == sum then simply return sum else let the loop finish and return cSum

int threeSumClosest(vector<int> &nums, int target)
{
    int minDiff = INT16_MAX;
    int cSum;
    std::sort(nums.begin(), nums.end());
    for (size_t i = 0; i < nums.size() - 2; i++)
    {
        int j = i + 1;
        int k = nums.size() - 1;
        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];

            int currentDiff = abs(sum - target);

            if (currentDiff < minDiff)
            {
                minDiff = currentDiff;
                cSum = sum;
            }

            if (sum > target)
            {
                k--;
            }
            else if (sum < target)
            {
                j++;
            }
            else
            {
                return sum;
            }
        }
    }
    return cSum;
}

int main(int argc, char const *argv[])
{

    vector<int> nums = {1, 1, 1, 0};
    cout << threeSumClosest(nums, -100);

    return 0;
}
