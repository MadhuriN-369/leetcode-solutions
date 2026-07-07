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
13    ListNode* reverseList(ListNode* head) {
14        if(!head || !head->next) return head;
15        ListNode* temp = head;
16        stack<int>st;
17        while(temp){
18            st.push(temp->val);
19            temp = temp->next;
20        }
21        temp = head;
22        while(!st.empty()){
23            temp->val = st.top();
24            temp = temp->next;
25            st.pop();
26        }
27        return head;
28    }
29};