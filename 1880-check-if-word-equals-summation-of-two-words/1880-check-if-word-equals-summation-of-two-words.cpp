class Solution {
public:
    int solve(string str)
    {
        int num = 0;
        for(int i=0;i<str.size();i++)
        {
            num*=10;
            num+=(str[i]-'a');
        }
        return num;
    }
    
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int num1 = 0;
        int num2 = 0;
        int num3 = 0;
        num1 = solve(firstWord);
        num2 = solve(secondWord);
        num3 = solve(targetWord);
        
        cout<<num1<<" "<<num2<<" "<<num3<<endl;
        
        return num1+num2==num3;
    }
};