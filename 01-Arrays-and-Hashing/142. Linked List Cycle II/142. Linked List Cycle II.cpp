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
11    ListNode *detectCycle(ListNode *head) {
12        if(head == nullptr || head->next == nullptr) return nullptr;
13        if(head->next->next == head) return head;
14        ListNode* slow = head, *fast = head;
15        while(fast != nullptr && fast->next != nullptr) {
16            fast = fast->next->next;
17            slow = slow->next;
18            if(fast == slow) break;
19        }
20        if(fast == nullptr || fast->next == nullptr) return nullptr;
21        slow = head;
22        while(slow != fast){
23            slow = slow->next;
24            fast = fast->next;
25        }
26        return slow;
27    }
28};