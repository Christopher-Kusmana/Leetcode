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
    /*The solution utilizes two pointers sliding window technique. The window first starts on the very beginning
    of the string with size 0. The window will stay valid as long as the size of the window subtracted by the 
    max frequency character in the window is less than or equal to k. If it exceeds k, then we shrink our window by
    moving our left pointer and decrementing our frequency hash map accordingly while also updating the 
    value of our largestWindow, which is then returned.
    */
    int leftP = 0;
    int largestWindow = 0;
    int maxF = 0;
    unordered_map<char, int> hm;
    int rightP = 0;
    for (rightP; rightP < s.length(); ++rightP)
    {
        hm[s[rightP]] += 1;
        maxF = max(maxF, hm[s[rightP]]);

        if ((rightP - leftP + 1) - maxF > k)
        {
            hm[s[leftP]] -= 1;
            leftP++;
        }

        largestWindow = max(largestWindow, rightP - leftP + 1);
    }

    return max(largestWindow, rightP - leftP);
}
int main(int argc, char const *argv[])
{
    string s = "IMNJJTRMJEGMSOLSCCQICIHLQIOGBJAEHQOCRAJQMBIBATGLJDTBNCPIFRDLRIJHRABBJGQAOLIKRLHDRIGERENNMJSDSSMESSTR";
    cout << characterReplacement(s, 2);
    return 0;
}
