1class Solution {
2public:
3    bool isValidSudoku(vector<vector<char>>& board) {
4        //9 x 9 grid
5        for(int i = 0; i < 9; i++){
6            vector<int>vec(10, 0);
7            for(int j = 0; j < 9; j++) {
8                if(board[i][j] == '.') continue;
9                if(vec[board[i][j] - '0'] == 1) return false;
10                vec[board[i][j] - '0'] = 1;
11            }
12        }
13
14        for(int i = 0; i < 9; i++){
15            vector<int>vec(10, 0);
16            for(int j = 0; j < 9; j++) {
17                if(board[j][i] == '.') continue;
18                if(vec[board[j][i] - '0'] == 1) return false;
19                vec[board[j][i] - '0'] = 1;
20            }
21        }
22
23        for(int i = 0; i < 9; i+=3){
24            vector<int>vec1(10, 0);
25            for(int k = i; k < i+3; k++){
26                for(int j = 0; j < 3; j++){
27                    if(board[k][j] == '.') continue;
28                    if(vec1[board[k][j] - '0'] == 1) return false;
29                    vec1[board[k][j] - '0'] = 1;
30                }
31            }
32            vector<int>vec2(10, 0);
33            for(int k = i; k < i+3; k++){
34                for(int j = 3; j < 6; j++){
35                    if(board[k][j] == '.') continue;
36                    if(vec2[board[k][j] - '0'] == 1) return false;
37                    vec2[board[k][j] - '0'] = 1;
38                }
39            }
40            vector<int>vec3(10, 0);
41            for(int k = i; k < i+3; k++){
42                for(int j = 6; j < 9; j++){
43                    if(board[k][j] == '.') continue;
44                    if(vec3[board[k][j] - '0'] == 1) return false;
45                    vec3[board[k][j] - '0'] = 1;
46                }
47            }
48        }
49        return true;
50    }
51};