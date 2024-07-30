
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

/*You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

Example 1:

Input: head = [1,2,3,4]
Output: [1,4,2,3]*/

class Solution
{

    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

public:
    void reorderList(ListNode *head)
    {
        vector<ListNode *> nodes;
        ListNode *curr = head;
        while (curr != nullptr)
        {
            nodes.push_back(curr);
            curr = curr->next;
        }

        int rightP = nodes.size() - 1;
        int i = 0;
        while (i <= rightP)
        {
            if (i == j)
            {
                nodes.push_back(nodes[i]);

                break;
            }

            nodes.push_back(nodes[i]);
            nodes.push_back(nodes[j]);

            i++;
            j--;
        }
        head->next = nullptr;
        curr = head;
        for (int i = 0; i < nodes.size(); i++)
        {
            ListNode *t = new ListNode(nodes[i]->val);

            curr->next = t;

            curr = curr->next;
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<int> vec = {1, 2, 3, 4};
    // vec.insert(vec.begin() + 1, 100);
    // vec.pop_back();
    // for (auto c : vec)
    // {
    //     cout << c << endl;
    // }

    return 0;
}
