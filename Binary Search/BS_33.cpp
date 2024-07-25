#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;

/*There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.



Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4*/

int search(vector<int> &nums, int target)
{
    int lo = 0;
    int hi = nums.size() - 1;
    int mid;

    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        // Divide and conquer search for sorted part
        if (nums[lo] <= nums[mid])
        {
            // Left part is sorted
            if (nums[lo] <= target && target < nums[mid])
            {
                hi = mid - 1; 
            }
            else
            {
                lo = mid + 1; 
            }
        }
        else
        {
            // Right part is sorted
            if (nums[mid] < target && target <= nums[hi])
            {
                lo = mid + 1; 
            }
            else
            {
                hi = mid - 1; 
            }
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << search(nums, 0);
    return 0;
}
