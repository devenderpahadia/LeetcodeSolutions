class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ctr=0;
        int n=tickets.size();
        for(int i=0;i<tickets.size();i = (i+1)%n)
        {
            if(tickets[i]==0)
            {
                continue;
            }
            else
            {
                tickets[i]--;
                ctr++;
                if(tickets[k]==0)
                return ctr;
            }
        }
        return ctr;
    }
};