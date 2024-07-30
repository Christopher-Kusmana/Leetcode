#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;

class Solution
{
    struct TreeNode
    {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

public:
    TreeNode *invertTree(TreeNode *root)
    {
        /*The idea is to  swap the left and the right child and call the function recursively on both 
        the right and left node as it returns the current node*/
        TreeNode *temp;
        TreeNode *curr = root;
        if (curr == nullptr)
        {
            return nullptr;
        }
        temp = curr->left;
        curr->left = curr->right;
        curr->right = temp;

        invertTree(curr->left);
        invertTree(curr->right);

        return root;
    }};

    int main(int argc, char const *argv[])
    {
        /* code */
        return 0;
    }
