#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;

// Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

// Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

// Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
// Return k.

// Example 1:

// Input: nums = [1,1,2]
// Output: 2, nums = [1,2,_]
// Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
// It does not matter what you leave beyond the returned k (hence they are underscores).


// Hashmap technique pesudo: 

// 1. Initialize hashmap and temp vector
// 2. Iterate through the nums and make a frequency hashmap
// 3. Everytime a new element is appended into the hashmap or the freq = 1 then append the element to the temp vector
// 4. Set nums = sol vector and return the size of the sol vector
int removeDuplicates(vector<int> &nums)
{
    unordered_map<int, int> um;
    vector<int> sol;
    for (size_t i = 0; i < nums.size(); i++)
    {
        um[nums[i]]++;
        if(um[nums[i]] == 1) {
            sol.push_back(nums[i]);
        }
    }

    nums = sol;

    return nums.size();
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    cout << removeDuplicates(nums) << '\n';
    for(auto i : nums) {
        cout << i << '\n';
    } 
    return 0;
}
