#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>

using namespace std;

/*Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.


Example 1:

Input: s = "()"
Output: true*/

bool isValid(string s)
{

    stack<char> exp;
    for (char c : s)
    {
        if (c == '(')
        {
            exp.push(c);
        }
        else if (c == '{')
        {
            exp.push(c);
        }
        else if (c == '[')
        {
            exp.push(c);
        }

        if (c == ')')
        {
            if (exp.empty())
            {
                return false;
            }
            else if (exp.top() != '(')
            {
                return false;
            }
            else
            {
                exp.pop();
            }
        }
        else if (c == '}')
        {
            if (exp.empty())
            {
                return false;
            }
            else if (exp.top() != '{')
            {
                return false;
            }
            else
            {
                exp.pop();
            }
        }
        else if (c == ']')
        {
            if (exp.empty())
            {
                return false;
            }
            else if (exp.top() != '[')
            {
                return false;
            }
            else
            {
                exp.pop();
            }
        }
    }

    if (exp.size() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(int argc, char const *argv[])
{
    string expression = "(]";
    cout << isValid(expression);
    return 0;
}
