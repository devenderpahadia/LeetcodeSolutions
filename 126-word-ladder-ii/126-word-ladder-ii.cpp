class Solution {
public:
    using p_t = pair<int, string>;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        unordered_set<string> dic(wordList.begin(), wordList.end());
        unordered_map<string, vector<string>> adj;
        unordered_map<string, int> dis;
        
        dic.insert(beginWord);
        dis[beginWord] = 0;
        int word_len = wordList[0].size();
        
        // construct adj graph
        for (auto& w : dic) {
            for (int i = 0; i < word_len; ++i) {
                string t = w;
                for (char c = 'a'; c <= 'z'; ++c) {
                    t[i] = c;
                    if (t != w && dic.count(t)) {
                        adj[w].push_back(t);
                    }
                }
            }
        }

        // do dijkstra
        priority_queue<p_t, vector<p_t>, greater<p_t>> pq;
        pq.push({0, beginWord});
        while (!pq.empty()) {
            auto [top_dis, top_word] = pq.top();
            pq.pop();
            
            if (dis[top_word] < top_dis) {
                continue;
            }
            
            for (auto& w : adj[top_word]) {
                const string& u = top_word;
                const string& v = w;
                if (!dis.count(v)) { // original dis is INF
                    dis[v] = top_dis + 1;
                    pq.push({dis[v], v});
                } else if (dis[v] > dis[u] + 1) {  // original dis is larger
                    dis[v] = dis[u] + 1;
                    pq.push({dis[v], v});
                }
            }
        }
        
        if (dis.find(endWord) == dis.end()) {
            // didn't find any available solution
            return ans;
        }

        // we have some solutions now.
        // construct it from the end to the begin
        int ans_depth = dis[endWord];
        vector<string> cur{endWord};
        function<void()> dfs = [&]() {
            string& at = cur.back();
            int depth = ans_depth - cur.size() + 1;

            // reached the beginning
            if (at == beginWord) {
                vector<string> tmp = cur;
                reverse(tmp.begin(), tmp.end());
                ans.push_back(move(tmp));
                return;
            }

            // go to the next level
            for (auto& w : adj[at]) {
                if (dis.count(w) && dis[w] == depth - 1) {
                    cur.push_back(w);
                    dfs();
                    cur.pop_back();
                }                
            }
        };
        dfs();
        
        return ans;
    }
};