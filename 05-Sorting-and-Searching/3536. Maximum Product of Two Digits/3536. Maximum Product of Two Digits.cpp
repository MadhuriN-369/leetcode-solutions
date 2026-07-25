1class Solution {
2public:
3    int maxProduct(int n) {
4        string str = to_string(n);
5        sort(str.begin(), str.end());
6        int m = str.size();
7        return (str[m-1]-'0')*(str[m-2]-'0');
8    }
9};