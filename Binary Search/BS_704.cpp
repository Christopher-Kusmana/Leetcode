#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;

/*Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.



Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
Example 2:

Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1*/

int search(vector<int> &nums, int target)
{
    sort(begin(nums), end(nums));
    int start = 0;
    int end = nums.size() - 1;
    int middle;

    while (start <= end)
    {
        middle = (start + end) / 2;
        if (nums[middle] == target)
        {
            return middle;
        }
        else if (nums[middle] < target)
        {
            start = middle + 1;
        }
        else if (nums[middle] > target)
        {
            end = middle - 1;
        }
        else
        {
            return -1;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    vector<int> bin = {-1,0,3,5,9,12};
    cout << search(bin, 9);
    return 0;
}
