#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;

// Design an algorithm to encode a list of strings to a single string. The encoded string is then decoded back to the original list of strings.

// Please implement encode and decode

// Example 1:

// Input: ["neet","code","love","you"]

// Output:["neet","code","love","you"]
// Example 2:

// Input: ["we","say",":","yes"]

// Output: ["we","say",":","yes"]

vector<int> sizes;
string encode(vector<string> &strs)
{
    sizes.clear();
    string encoded = "";
    for (size_t i = 0; i < strs.size(); i++)
    {
        sizes.push_back(strs[i].length());
    }
    for (size_t i = 0; i < strs.size(); i++)
    {
        encoded = encoded + strs[i];
    }
    return encoded;
}

vector<string> decode(string s)
{
    vector<string> decoded;
    size_t start = 0;
    for (size_t i = 0; i < sizes.size(); i++)
    {
        decoded.push_back(s.substr(start, sizes[i]));
        start += (sizes[i]);
    }
    return decoded;
}

int main(int argc, char const *argv[])
{
    vector<string> encode_input = {"neet", "code", "love", "you"};
    string decode_input = "neetcodeloveyou";
    vector<string> decode_output = decode(encode(encode_input));
    for (size_t i = 0; i < decode_output.size(); i++)
    {
        cout << decode_output[i] << "\n";
    }
    for(size_t i = 0; i < sizes.size(); i++) {
        cout << sizes[i] << "\n";
    }
    return 0;
}
