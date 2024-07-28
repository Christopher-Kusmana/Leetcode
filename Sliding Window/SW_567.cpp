#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;

/*Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
*/

bool checkInclusion(string s1, string s2)
{
    /*Solving this problem uses the two pointer sliding window technique. Since we know the exact
    characters that is permutated, we would also know the exact size of our window which is equal to the length
    of s1. For this solution, we use two hashmap where the first one becomes a point of comparison by keeping track
    of the character(s) and its frequenc(ies) of s1. Then as we slide our window through s2, we also build a 
    frequency hashmap which we then compare with the first hashmap. If they are equal then we have found a
    permutation and return true*/
    if (s2.length() < s1.length())
    {
        return false;
    }
    int leftP = 0;
    int rightP = s1.length() - 1;
    unordered_map<char, int> hm1;
    unordered_map<char, int> hm2;
    for (auto c : s1)
    {
        hm1[c] += 1;
    }

    for (rightP; rightP < s2.length(); rightP++)
    {
        for (int i = leftP; i < rightP + 1; i++)
        {
            hm2[s2[i]] += 1;
        }
        if (hm1 == hm2)
        {
            return true;
        }
        hm2.clear();
        leftP++;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    string s1 = "ab";
    string s2 = "eidbaooo";
    cout << checkInclusion(s1, s2);
    return 0;
}
