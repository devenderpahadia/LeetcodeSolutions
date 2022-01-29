class Solution {
public:
    
    int solve(unsigned int n)
    {
        int count = 0;
        if (n && !(n & (n - 1)))
        return n;
     
        while( n != 0)
        {
            n >>= 1;
            count += 1;
        }
        return 1 << count;
    }
 
    vector<int> pathInZigZagTree(int label) {
        vector<vector<int>>res;
        
        int k=1;
        int x=0;
        int ext = solve(label);
        bool flag = false;
        while(k<=ext)
        {
            vector<int>temp;
            int y = pow(2,x);
            while(y--)
            {
                temp.push_back(k++);
            }
            if(flag==false)
            {
                flag=true;
            }
            else
            {
                reverse(temp.begin(),temp.end());
                flag=false;
            }
            res.push_back(temp);
            x++;
        }
        
        int a,b;
        
        for(int i=0;i<res.size();i++)
        {
            for(int j=0;j<res[i].size();j++)
            {
                if(res[i][j]==label)
                {
                    a=i;
                    b=j;
                    break;
                }
            }
        }
        vector<int>vec;
        
        while(a>=0)
        {
            vec.push_back(res[a][b]);
            a--;
            b/=2;
        }
        reverse(vec.begin(),vec.end());
        
        return vec;
    }
};