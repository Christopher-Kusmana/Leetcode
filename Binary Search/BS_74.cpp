#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;

/*You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.



Example 1:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true*/

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int start = 0;
    int end = matrix.size() * matrix[0].size() - 1;
    int mid;

    while (start <= end)
    {
        mid = (start + end) / 2;
        if (matrix[mid / matrix[0].size()][mid % matrix[0].size()] == target)
        {
            return true;
        }
        else if (matrix[mid / matrix[0].size()][mid % matrix[0].size()] < target)
        {
            start = mid + 1;
        }
        else if (matrix[mid / matrix[0].size()][mid % matrix[0].size()] > target)
        {
            end = mid - 1;
        }
        else
        {
            return false;
        }
    }
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> input = {{1, 1}};
    cout << searchMatrix(input, 2);
    return 0;
}
