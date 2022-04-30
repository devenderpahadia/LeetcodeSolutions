class Solution {
public:
    double check( string a , string b , unordered_map<string , unordered_map<string , double>> &mp , unordered_set<string> &vis ){
        if ( mp[a].find(b) != mp[a].end()) return mp[a][b];
        for ( auto i : mp[a]){
            if ( vis.find( i.first) == vis.end()){
                vis.insert(i.first);
                
                double temp = check( i.first , b , mp , vis);
                if ( temp ) return i.second*temp;
            }
        }
        return 0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> res;
        unordered_map<string , unordered_map<string , double>> mp;
        for ( int i = 0 ; i < values.size() ; i++){
            mp[equations[i][0]].insert({equations[i][1] , values[i]});   
            if ( values[i] != 0)
            mp[equations[i][1]].insert({equations[i][0] , 1 / values[i]});
        }
        for ( int i = 0 ; i < queries.size() ; i ++){
            unordered_set<string> vis;
            
            double temp = check ( queries[i][0] , queries[i][1] , mp , vis);   
            if( temp ) res.push_back(temp);
            else res.push_back(-1);
        }
        return res;
    }
};