#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
using namespace std;
/*Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example 1:

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.*/

int trap(vector<int> &height)
{
    if (height.size() == 0)
    {
        return 0;
    }
    int totalWater = 0;
    vector<int> leftMax;;
    vector<int> rightMax;
    leftMax.resize(height.size());
    rightMax.resize(height.size());
    // Compute leftMax array
    leftMax[0] = height[0];
    for (int i = 1; i < height.size(); ++i)
    {
        leftMax[i] = max(leftMax[i - 1], height[i]);
    }

    // Compute rightMax array
    rightMax[height.size() - 1] = height[height.size() - 1];
    for (int i = height.size() - 2; i >= 0; --i)
    {
        rightMax[i] = max(rightMax[i + 1], height[i]);
    }

    for (size_t i = 0; i < height.size(); i++)
    {
        if (min(leftMax[i], rightMax[i]) - height[i] >= 0)
        {
            totalWater += min(leftMax[i], rightMax[i]) - height[i];
        }
    }

    return totalWater;
}

int main(int argc, char const *argv[])
{
    vector<int> heights = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trap(heights);
    return 0;
}
