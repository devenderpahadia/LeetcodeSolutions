class Solution {
private:
    ListNode* root;
public:
    Solution(ListNode* head) {
        root=head;
    }
    
    int getRandom() {
       int len=0;
       ListNode* temp=root;
       vector<int> v;
       while(temp)
       {
           len++;
           v.push_back(temp->val);
           temp=temp->next;
       }
       return v[rand()%len];
    }
};