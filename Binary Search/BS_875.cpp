#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;

/*Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.



Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30*/

int helper(vector<int> &piles, int h, int k)
{
    int time = 0;
    for (int pile : piles)
    {
        time += (pile + k - 1) / k;
    }
    return time;
}

int minEatingSpeed(vector<int> &piles, int h)
{
    int lo = 1, hi = *max_element(piles.begin(), piles.end());
    while (lo < hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (helper(piles, h, mid) <= h)
        {
            hi = mid; 
        }
        else
        {
            lo = mid + 1; 
        }
    }
    return lo;
}

int main(int argc, char const *argv[])
{
    vector<int> piles = {3, 6, 7, 11};
    cout << minEatingSpeed(piles, 8);
    return 0;
}
