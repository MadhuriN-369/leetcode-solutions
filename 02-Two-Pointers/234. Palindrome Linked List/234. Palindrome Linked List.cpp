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
14        vector<int>arr;
15        ListNode* temp = head;
16        while(temp != nullptr){
17            arr.push_back(temp->val);
18            temp = temp->next;
19        }
20        int start = 0, end = arr.size()-1;
21        while(start < end){
22            if(arr[start] != arr[end]) return false;
23            start++; end--;
24        }
25        return true;
26    }
27};