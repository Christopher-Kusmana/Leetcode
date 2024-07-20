#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

bool isPalindrome(string s)
{
    // Sanitizes the string (lowercase, remove nonalphanumeric, remove whitespaces)
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    s.erase(remove_if(s.begin(), s.end(), ::isspace), s.end());
    s.erase(remove_if(s.begin(), s.end(), [](char c)
                      { return !isalnum(c); }),
            s.end());

    size_t ptr1 = 0;
    size_t ptr2 = s.length() - 1;

    if (s.length() == 0)
    {
        return true;
    }

    while (ptr1 < ptr2)
    {
        if (s.at(ptr1) == s.at(ptr2))
        {
            ptr1++;
            ptr2--;
        }
        else
        {
            return false;
        }
    }

    return true;
}

int main(int argc, char const *argv[])
{
    // Testing purpose
    string pal = "tacocat";
    string pal2 = "Was it a car or a cat i saw";

    cout << isPalindrome(pal);
    cout << isPalindrome(pal2);
    return 0;
}

// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

// Given a string s, return true if it is a palindrome, or false otherwise.

// Example 1:

// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.
// Example 2:

// Input: s = "race a car"
// Output: false
// Explanation: "raceacar" is not a palindrome.