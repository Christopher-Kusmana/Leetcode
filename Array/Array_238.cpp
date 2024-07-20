#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;

// // Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

// You must write an algorithm that runs in O(n) time and without using the division operation.

// Example 1:

// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]
// Example 2:

// Input: nums = [-1,1,0,-3,3]
// Output: [0,0,9,0,0]

// Constraints:

// 2 <= nums.length <= 105
// -30 <= nums[i] <= 30
// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

vector<int> productExceptSelf(vector<int> &nums)
{

    vector<int> ans = nums;
    int total_prod = 1;
    int zero_count = 0;
    bool has_zero = false; 
    bool allZeros = std::all_of(nums.begin(), nums.end(), [](int i) { return i == 0; });
    if(allZeros){
        return ans;
    }
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0 && zero_count < 1)
        {
            has_zero = true;
            zero_count++;
        }
        else
        {
            total_prod *= nums[i];
        }
    }

    for (size_t i = 0; i < nums.size(); i++)
    {
        if (has_zero == true)
        {
            if(nums[i] == 0) {
                ans[i] = total_prod;
            } else{
                ans[i] = 0;
            }
        } else {
            ans[i] = total_prod / ans[i];
        }
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> input = {0,0};
    vector<int> ans = productExceptSelf(input);

    for(size_t i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "\n";
    }
    return 0;
}
