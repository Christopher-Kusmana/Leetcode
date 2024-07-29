#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;

/*Given the head of a singly linked list, reverse the list, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]*/

class Solution
{
    /*The idea is to use two extra pointer: prev and current. The current pointer points to the Node that is 
    currently being modified while prev keeps track of the previous Node which is useful for the reversing process.
    Reversing the list involves setting the next of the current node to the prev Node pointer. As the current
    pointer traverses through the linked list, the entire ListNode will be reversed*/
    
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *current = head;
        ListNode *next = nullptr;
        ListNode *prev = nullptr;

        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
