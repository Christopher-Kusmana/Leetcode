#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <utility>
#include <climits>

using namespace std;

/*Given two strings s and t of lengths m and n respectively, return the minimum window
substring
 of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.



Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
*/

string minWindow(string s, string t)
{

    /*The idea is to use hashmap and sliding window technique. Hashmap stores the frequency of character
    of the target string while the sliding window minimizes the substring length as long as it is valid. 
    When the total count, which corresponds reaches zero, meaning that all characters in t is contained in the
    window, we keep track of the leftP that minimizes the window size and shift leftP to
    find potentially lower substring count. Then we continue with the loop until rightP traverses through the
    whole string*/

    unordered_map<char, int> freqTarget;
    for (char c : t)
    {
        freqTarget[c]++;
    }

    int leftP = 0, rightP = 0;
    int minLen = INT_MAX;
    int minStart = 0;
    int totalCount = t.size();

    while (rightP < s.size())
    {

        if (freqTarget[s[rightP]] > 0)
        {
            totalCount--;
        }
        freqTarget[s[rightP]]--;

        while (totalCount == 0)
        {

            if (rightP - leftP + 1 < minLen)
            {
                minLen = rightP - leftP + 1;
                minStart = leftP;
            }

            freqTarget[s[leftP]]++;
            if (freqTarget[s[leftP]] > 0)
            {
                totalCount++;
            }
            leftP++;
        }
        rightP++;
    }
    return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
}

int main(int argc, char const *argv[])
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << minWindow(s, t);
    return 0;
}
