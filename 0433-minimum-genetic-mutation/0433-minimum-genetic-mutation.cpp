class Solution {
public:
    unordered_set<string>st;
    long long solve(string s,string e){
        if(s==e) {
            cout<<s<<endl;
            return 0;
        }
        long long l = INT_MAX;
        for(int i=0;i<8;i++){
                char c = s[i];
                if(c!='A'){
                    s[i] = 'A';
                    if(st.find(s)!=st.end())
                    l = min(l,1+solve(s,e));
                    s[i] = c;
                }
                if(c!='C'){
                    s[i] = 'C';
                    if(st.find(s)!=st.end())
                    l = min(l,1+solve(s,e));
                    s[i] = c;
                }
                if(c!='G'){
                    s[i] = 'G';
                    if(st.find(s)!=st.end())
                    l = min(l,1+solve(s,e));
                    s[i] = c;
                }
                if(c!='T'){
                    s[i] = 'T';
                    if(st.find(s)!=st.end())
                    l = min(l,1+solve(s,e));
                    s[i] = c;
                }
        }
        return l;
    }
    int minMutation(string start, string end, vector<string>& bank) {
        st.clear();
        for(auto it : bank){
            st.insert(it);
        }
        if(st.find(end)==st.end()) return -1;
        
        queue<string>q;
        unordered_set<string>vis;
        q.push(start);
        vis.insert(start);
        int ans = 0;
        
        while(q.size()){
            int sz = q.size();
            while(sz--){
                
                string curr = q.front();
                q.pop();
                
                if(curr==end) return ans;
                
                for(int i=0;i<curr.size();i++){
                    char c = curr[i];
                    
                    curr[i] = 'A';
                    if(st.find(curr)!=st.end()){
                        if(vis.find(curr)==vis.end()){
                            vis.insert(curr);
                            q.push(curr);
                        }
                    }
                    curr[i] = 'C';
                    if(st.find(curr)!=st.end()){
                        if(vis.find(curr)==vis.end()){
                            vis.insert(curr);
                            q.push(curr);
                        }
                    }
                    curr[i] = 'G';
                    if(st.find(curr)!=st.end()){
                        if(vis.find(curr)==vis.end()){
                            vis.insert(curr);
                            q.push(curr);
                        }
                    }
                    curr[i] = 'T';
                    if(st.find(curr)!=st.end()){
                        if(vis.find(curr)==vis.end()){
                            vis.insert(curr);
                            q.push(curr);
                        }
                    }
                    
                    curr[i] = c;
                    
                }
                
            }
            ans++;
        }
        return -1;
    }
};