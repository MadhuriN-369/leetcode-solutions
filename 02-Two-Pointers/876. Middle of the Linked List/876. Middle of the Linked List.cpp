1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode() : val(0), next(nullptr) {}
7 *     ListNode(int x) : val(x), next(nullptr) {}
8 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
9 * };
10 */
11class Solution {
12public:
13    ListNode* middleNode(ListNode* head) {
14        ListNode*fast = head, *slow = head;
15        while(fast != nullptr && fast->next != nullptr) {
16            cout<<fast->val<< <<slow->val<<endl;
17            fast = fast->next->next;
18            slow = slow->next;
19        }
20        return slow;
21    }
22};