/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)
            return head;
        Node* res = new Node(head->val);
        Node* p = res;
        Node* q = head;
        unordered_map<Node*,Node*>mp;
        while(q)
        {
            Node* t = new Node(q->val);
            mp[q] = t;
            p->next = t;
            p=t;
            q=q->next;
        }
        
        res = res->next;
        
        
        Node* ans = res;
        p=res;
        q=head;
        while(p)
        {
            p->random = mp[q->random];
            q=q->next;
            p=p->next;
        }
        return ans;
    }
};