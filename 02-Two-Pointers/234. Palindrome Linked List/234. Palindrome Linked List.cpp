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
13    bool isPalindrome(ListNode* head) {
14        ListNode*slow = head, *fast = head;
15        while(fast != nullptr && fast->next != nullptr){
16            fast = fast->next->next;
17            slow = slow->next;
18        }
19        //now the slow pointer is at the middle, let's reverse from middle to end
20        ListNode* cur = slow, *prev = nullptr;
21        while(cur != nullptr){
22            ListNode*next = cur->next;
23            cur->next = prev;
24            prev = cur;
25            cur = next;
26        }
27        ListNode* p1 = head, *p2 = prev;
28        while(p1 != nullptr && p2 != nullptr){
29            if(p1->val != p2->val) return false;
30            p1 = p1->next;
31            p2 = p2->next;
32        }
33        return true;
34    }
35};