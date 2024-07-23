#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
#include <utility>
#include <string>

using namespace std;

/*You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.


Example 1:

Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9*/

int evalRPN(vector<string> &tokens)
{
    int arg1;
    int arg2;
    stack<int> st;
    if (tokens.size() == 1)
    {
        return stoi(tokens[0]);
    }
    for (int i = 0; i < tokens.size(); i++)
    {
        if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/")
        {
            st.push(std::stoi(tokens[i]));
        }
        else
        {
            if (tokens[i] == "+")
            {
                arg1 = st.top();
                st.pop();
                arg2 = st.top();
                st.pop();
                st.push(arg1 + arg2);
            }
            else if (tokens[i] == "-")
            {
                arg1 = st.top();
                st.pop();
                arg2 = st.top();
                st.pop();
                st.push(arg2 - arg1);
            }
            else if (tokens[i] == "*")
            {
                arg1 = st.top();
                st.pop();
                arg2 = st.top();
                st.pop();
                st.push(arg1 * arg2);
            }
            else if (tokens[i] == "/")
            {
                arg1 = st.top();
                st.pop();
                arg2 = st.top();
                st.pop();
                st.push(arg2 / arg1);
            }
        }
    }
    return st.top();
}

int main(int argc, char const *argv[])
{
    vector<string> tokens = {"1","2","+","3","*","4", "-"};
    cout << evalRPN(tokens);
    return 0;
}
