1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode(int x) : val(x), next(NULL) {}
7 * };
8 */
9class Solution {
10public:
11    bool hasCycle(ListNode *head) {
12        ListNode* slow = head, *fast = head;
13        while(fast != nullptr && fast->next != nullptr){
14            fast = fast->next->next;
15            slow = slow->next;
16            if(fast == slow) return true;
17        }
18        return false;
19    }
20};