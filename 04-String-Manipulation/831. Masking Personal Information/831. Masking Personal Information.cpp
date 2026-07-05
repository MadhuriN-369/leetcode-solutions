1class Solution {
2public:
3    string maskPII(string s) {
4        int n = s.size();
5        if(isalpha(s[0])){
6            //email!!!!
7            int at = s.find('@');
8            for(int i = 0; i < n; i++){
9                if(i == at) continue;
10                if(isupper(s[i])){
11                    s[i] = tolower(s[i]);
12                }
13            }
14            string str = ;
15            str += s[0];
16            str += *****;
17            if(at-1 != 0) str += s[at-1];
18            str += s.substr(at);
19            return str;
20
21        }
22        else{
23            //ph number!!!!!
24            int county_num = 0;
25            for(int i = 0; i < n; i++){
26                if(isdigit(s[i])) county_num++;
27            }
28            int county = county_num-10;
29            string str = ;
30
31            for(int i = 0; i < county; i++) {
32                if(i==0) str +=+;
33                str += *;
34                if(i == county-1) str +=-;
35            }
36            str += ***-***-;
37            int count = 0;
38            string str1 = ;
39            for(int i = n-1; i >= 0; i--){
40                if(count == 4) break;
41                if(isdigit(s[i])){
42                    str1 = s[i] + str1;
43                    count++;
44                }
45            }
46            str += str1;
47            return str;
48        }
49    }
50};