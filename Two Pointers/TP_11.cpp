#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;

/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.



Example 1:


Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1
*/

int maxArea(vector<int> &heights)
{
    size_t start = 0;
    size_t end = heights.size() - 1;
    int maxArea = 0;
    while(start <= end) { 
        if(maxArea < min(heights[start], heights[end]) * (end-start) )
        {
            maxArea = min(heights[start], heights[end]) * (end-start);
        }
        if(heights[start] > heights[end]) {
            end--;
        } else {
            start++;
        }
    }
    return maxArea;
}

int main(int argc, char const *argv[])
{
    vector<int> heights = {1,8,6,2,5,4,8,3,7};
    cout << maxArea(heights);
    return 0;
}
