#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;

/*Given a string s, find the length of the longest
substring
 without repeating characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.*/

int lengthOfLongestSubstring(string s)
{
    /*The idea is to use hashmap to keep track of the character that has been seen and also their indices
    Once a dupe is found, we reset our left pointer to +1 index after the duplicate character to start
    a new substring*/
    int leftP = 0;
    int rightP = 0;
    unordered_map<char, int> hm;
    size_t longestSub = 0;
    
    while (rightP < s.length())
    {
        if (hm.count(s[rightP]) == 0)
        {
            hm[s[rightP]] = rightP;
            ++rightP;
            longestSub = max(longestSub, hm.size());
        }
        else
        {
            leftP = hm[s[rightP]] + 1;
            rightP = leftP;
            hm.clear();
        }
    }
    return static_cast<int>(longestSub);
}

int main(int argc, char const *argv[])
{
    string s = "dvdf";
    cout << lengthOfLongestSubstring(s);
    return 0;
}
