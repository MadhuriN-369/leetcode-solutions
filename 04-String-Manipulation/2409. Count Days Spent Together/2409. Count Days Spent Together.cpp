1class Solution {
2public:
3    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
4        vector<int>days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
5        auto convert = [&](string date){
6            int month = stoi(date.substr(0, 2));
7            int day = stoi(date.substr(3));
8            int count = 0;
9            for(int i = 0; i < month-1; i++){
10                count += days[i];
11            }
12            return count+day;
13        };
14        int start = max(convert(arriveAlice), convert(arriveBob));
15        int end = min(convert(leaveAlice), convert(leaveBob));
16
17        return max(0, end-start+1);
18    }
19};