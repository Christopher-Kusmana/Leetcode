#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;

/*You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.*/

int characterReplacement(string s, int k)
{

    int leftP = 0;
    int largestWindow = 0;
    int maxF = 0;
    int rightP = 0;
    unordered_map<int, int> hm;

    for (rightP; rightP < s.length(); ++rightP)
    {
        hm[int(s[rightP])] += 1;
        for (auto c : "ABCDEFGHIJKLMNOPQRSTUVWXYZ")
        {
            maxF = max(maxF, hm[int(c)]);
        }
        
        if ((rightP - leftP + 1) - maxF > k)
        {
            
            largestWindow = max(largestWindow, (rightP - leftP));
            hm.erase(int(s[leftP]));
            ++leftP;

        }
    }
    return largestWindow;
}

int main(int argc, char const *argv[])
{
    string s = "ABAB";
    cout << characterReplacement(s, 2);
    return 0;
}
