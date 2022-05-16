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
        Node* item=head,*front=head;
        
        while(item)
        {
            front = item->next;
            Node* t = new Node(item->val);
            item->next = t;
            t->next = front;
            item = front;
        }
        item = head;
        while(item)
        {
            if(item->random)
            item->next->random = item->random->next;
            item=item->next->next;
        }
        
        item = head;
        Node*res = new Node(0);
        Node* t = res;
        
        while(item)
        {
            front = item->next->next;
            t->next = item->next;
            item->next = front;
            t = t->next;
            item = front;
        }
        return res->next;
    }
};
