#include <iostream>

using namespace std;

bool isPalindrome(string s) {

    bool res = false;
    size_t len = s.length();
    size_t ptr1, ptr2 = 0, len;
    while(s.at(ptr1) == s.at(ptr2) && ptr1 != ptr2) {
        ptr1++;
        ptr2--;
    }

    return res;

}

int main(int argc, char const *argv[])
{
    string pal = "tacocat";
    string npal = "notapalindrome";
    cout << isPalindrome(pal); 
    cout << isPalindrome(npal);
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