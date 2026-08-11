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
12        ListNode* temp = head;
13        unordered_set<ListNode*>st;
14        while(temp != nullptr){
15            if(st.find(temp) != st.end()){
16                return temp;
17            }
18            st.insert(temp);
19            temp = temp->next;
20        }
21        return nullptr;
22    }
23};