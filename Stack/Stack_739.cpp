#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>

using namespace std;

/*Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]*/

vector<int> dailyTemperatures(vector<int> &temperatures)
{
    vector<int> res(temperatures.size());
    stack<pair<int, int>> st;
    for (int i = 0; i < temperatures.size(); i++)
    {
        while (!st.empty() && st.top().first < temperatures[i])
        {
            res[st.top().second] = i - st.top().second;
            st.pop();
        }

        st.emplace(temperatures[i], i);
    }
    return res;
}

int main(int argc, char const *argv[])
{
    vector<int> temps = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> res = dailyTemperatures(temps);
    for (auto i : res)
    {
        cout << i << '\n';
    }
    return 0;
}
