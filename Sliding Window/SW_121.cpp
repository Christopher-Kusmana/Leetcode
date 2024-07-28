#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;

/*You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.



Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.*/

int maxProfit(vector<int> &prices)
{

    /*The intuition is that max profit is achieved when we find the max and the min of our relative window
    So we first slide our window and check if we find a price lower than out left pointer. If we do, we update
    the left pointer and take the max of the current and previous profit. We repeat until we reach the end of
    the array.*/

    // Edge case
    if (prices.size() == 0)
    {
        return 0;
    }
    int maxProfit = 0;
    int leftP = 0;
    int rightP = 1;
    while (rightP < prices.size())
    {
        if (prices[rightP] < prices[leftP])
        {
            ++leftP;
        }
        else
        {
            maxProfit = max(maxProfit, prices[rightP] - prices[leftP]);
            ++rightP;
        }
    }
    return maxProfit;
}

int main(int argc, char const *argv[])
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices);
    return 0;
}
