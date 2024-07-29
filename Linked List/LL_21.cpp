#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;

/*You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

Example 1:

Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]*/

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        /*To solve this problem, we construct a ListNode called merged and uses the tail pointer
        to keep inserting elements in the appropriate order. Next a while loop that goes through list1 
        and list2 is executed which inserts elements until either list reaches its end. If there are leftover 
        elements due to one list finishing before the other, we just attach whatever list is left since it is
        already sorted in the appropriate order*/

        ListNode merged;
        ListNode* tail = &merged;
        merged.next = nullptr;

        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val <= list2->val)
            {
                tail->next = list1;
                list1 = list1->next;
            }
            else
            {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        if (list1 != nullptr)
        {
            tail->next = list1;
        }
        else
        {
            tail->next = list2;
        }
        return merged.next;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
