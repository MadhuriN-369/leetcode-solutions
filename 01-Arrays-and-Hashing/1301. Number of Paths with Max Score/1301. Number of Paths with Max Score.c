1class Solution {
2public:
3    const long long MOD = 1e9+7;
4    int N;
5    vector<int> dp[101][101];
6    bool isvalid(int row, int col){
7        return row >= 0 && row < N && col >= 0 && col < N;
8    }
9    vector<int>solve(int i, int j, vector<string>&board) {
10        if(board[i][j] == 'E'){
11            return {0, 1};
12        }
13        if(board[i][j] == 'X'){
14            return {0, 0};
15        }
16        if(dp[i][j][0] != -1) return dp[i][j];
17        //up, left, upleft are there directions we can go
18
19        long long s1, s2, s3, count1, count2, count3;
20        s1 = s2 = s3 = -100000;
21        count1 = count2 = count3 = 0;
22        //go up
23        if(isvalid(i-1, j) && board[i-1][j] != 'X'){
24            auto temp = solve(i-1, j, board);
25            s1 = temp[0];
26            count1 = temp[1];
27        }
28        //go left
29        if(isvalid(i, j-1) && board[i][j-1] != 'X'){
30            auto temp = solve(i, j-1, board);
31            s2 = temp[0];
32            count2 = temp[1];
33        }
34        //go up left
35        if(isvalid(i-1, j-1) && board[i-1][j-1] != 'X'){
36            auto temp = solve(i-1, j-1, board);
37            s3 = temp[0];
38            count3 = temp[1];
39        }
40    
41        int val = 0;
42        if(board[i][j] != 'S') val = board[i][j]-'0';
43        int best = max(s1, max(s2, s3));
44        long long count = 0;
45        if(s1 == best) count += count1;
46        if(s2 == best) count += count2;
47        if(s3 == best) count += count3;
48        if(count < 0) return dp[i][j] = {0,0};
49        return dp[i][j] = {(int)(best+val) , (int)(count%MOD)};
50    }
51    vector<int> pathsWithMaxScore(vector<string>& board) {
52        int n = board.size();
53        N = n;
54        for(int i = 0; i < n; i++) {
55            for(int j = 0; j < n; j++) {
56                dp[i][j] = {-1, -1};
57            }
58        }
59        auto temp = solve(n-1, n-1, board);
60        int best = temp[0];
61        int count = temp[1];
62        if(best < 0 || count == 0) return {0,0};
63        return {best, count};
64    }
65};