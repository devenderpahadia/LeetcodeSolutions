class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n=num.size();
        string str = to_string(k);
        if(n<str.size())
        {
            
            vector<int>vec;
            for(auto it : str)
            {
                vec.push_back(it -'0');
            }
            int sum = 0;
            for(int i=0;i<n;i++)
            {
                sum*=10;
                sum+=num[i];
            }
            
            k=sum;
            num=vec;
            n=num.size();
        }
        
        int carry=0;
        for(int i=n-1;i>=0;i--)
        {
            if(carry==1)
            {
                if((num[i]+(k%10)+1) > 9)
                {
                    num[i] = (1+num[i]+(k%10))%10;
                    carry = 1;
                }
                else
                {
                    num[i] = 1+(num[i]+(k%10))%10;
                    carry = 0;
                }
            }
            else
            {
                if(num[i]+(k%10) > 9)
                {
                    num[i] = (num[i]+(k%10))%10;
                    carry = 1;
                }
                else
                {
                    num[i] = (num[i]+(k%10))%10;
                    carry = 0;
                }
            }
            k/=10;
        }
        
        
        
        if(carry==1)
        {
            num.insert(num.begin()+0,1);
        }
        return num;
    }
};