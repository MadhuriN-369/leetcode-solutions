1class Solution {
2public:
3    unordered_map<string, vector<pair<string, double>>> buildGraph(vector<vector<string>>& pairs, vector<double>& rates) {
4        int n = pairs.size();
5        unordered_map<string, vector<pair<string, double>>>mp;
6        for(int i = 0; i < n; i++) {
7            string c1 = pairs[i][0];
8            string c2 = pairs[i][1];
9            mp[c1].push_back({c2, rates[i]});
10            mp[c2].push_back({c1, 1.0/rates[i]});
11        }
12        return mp;
13    }
14    void dfs(double val, const string &cur, unordered_map<string, vector<pair<string, double>>>&adj, unordered_map<string, double>&reach, unordered_set<string>&vis) {
15        vis.insert(cur);
16        reach[cur] = max(reach.count(cur) ? reach[cur] : 0.0, val);
17        for(auto &[next, rate]: adj[cur]){
18            if(!vis.count(next)){
19                dfs(val*rate, next, adj, reach, vis);
20            }
21        }
22    }
23    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
24        unordered_map<string, vector<pair<string, double>>>adj1 = buildGraph(pairs1, rates1);
25        unordered_map<string, vector<pair<string, double>>>adj2 = buildGraph(pairs2, rates2);
26
27        unordered_map<string, double>afterday1;
28        unordered_set<string>visited;
29        dfs(1.0, initialCurrency, adj1, afterday1, visited);
30
31        double best = 1.0;
32        for(auto&[currency, rate]: afterday1){
33            unordered_map<string, double>afterday2;
34            unordered_set<string>vis2;
35            dfs(rate, currency, adj2, afterday2, vis2);
36            if(afterday2.count(initialCurrency)){
37                best = max(best, afterday2[initialCurrency]);
38            }
39        }
40        return best;
41    }
42};