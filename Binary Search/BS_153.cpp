#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;

/*Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.



Example 1:

Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.*/

int findMin(vector<int> &nums)
{
    int lo = 0;
    int hi = nums.size() - 1;
    int mid;

    // In the case that the array is rotated n times or 0 times
    if (nums[lo] < nums[hi])
    {
        return nums[lo];
    }

    while (lo < hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] > nums[mid + 1])
        {
            return nums[mid + 1];
        }
        else if (nums[mid - 1] > nums[mid])
        {
            return nums[mid];
        }
        else if (nums[mid] > nums[hi])
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid;
        }
    }
    return nums[lo];
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout <<  findMin(nums);
    return 0;
}