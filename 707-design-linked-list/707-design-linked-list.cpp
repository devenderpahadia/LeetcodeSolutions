class MyLinkedList {
public:
    struct LList{
        int ele;
        LList* next;
        LList(int x)
        {
            ele=x;
            next=NULL;
        }
    };
    LList* head;
    LList* tail;
    int ctr;
    MyLinkedList() {
        head=tail=NULL;
        ctr=0;
    }
    
    int get(int index) {
        if(index>=ctr)
            return -1;
        int i=0;
        LList* p = head;
        while(i<index)
        {
            p=p->next;
            i++;
        }
        return p->ele;
    }
    
    void addAtHead(int val) {
        LList* t = new LList(val);
        if(head==NULL)
        {
            head=t;
            tail=t;
        }
        else
        {
            t->next = head;
            head=t;
        }
        ctr++;
        cout<<ctr<<endl;
    }
    
    void addAtTail(int val) {
        LList* t = new LList(val);
        if(tail==NULL)
        {
            head=t;
            tail=t;
        }
        else
        {
            tail->next = t;
            tail=t;
        }
        ctr++;
        cout<<ctr<<endl;
    }
    
    void addAtIndex(int index, int val) {
        if(index > ctr)
            return;
        if(index==ctr)
        {
            addAtTail(val);
            return;
        }
        if(index==0)
        {
            addAtHead(val);
            return;
        }
        LList* t = new LList(val);
        int i=0;
        LList* p = head;
        while(i<index-1)
        {
            p=p->next;
            i++;
        }
        
        t->next=p->next;
        p->next = t;
        ctr++;
        cout<<ctr<<endl;
    }
    
    void deleteAtIndex(int index) {
        if(index>=ctr)
            return;
        
        if(index==ctr-1)
        {
            LList* p = head;
            LList* q ;
            while(p->next)
            {
                q=p;
                p=p->next;
            }
            tail=q;
            tail->next=NULL;
            ctr--;
            cout<<ctr<<endl;
            return;
        }
        
        if(index==0)
        {
            head=head->next;
            ctr--;
            cout<<ctr<<endl;
            return;
        }
        
        int i=0;
        LList* p = head;
        while(i<index-1)
        {
            p=p->next;
            i++;
        }
        LList* q = p->next;
        p->next = p->next->next;
        delete q;
        ctr--;
        cout<<ctr<<endl;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */