class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<double>maxh;
    priority_queue<double,vector<double>,greater<double>>minh;
    MedianFinder() 
    {}
    
    void addNum(int num) 
    {
        maxh.push(num);
        minh.push(maxh.top());
        maxh.pop();
        
        if(maxh.size()<minh.size())
        {
            maxh.push(minh.top());
            minh.pop();
        }
    }
    
    double findMedian() 
    {
        
        if(maxh.size()==0)
            return 0;
        if(maxh.size()==minh.size())
        {
            return (maxh.top()+minh.top())/2;
        }
        else
        {
            return maxh.top();
        }
            
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */