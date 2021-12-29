class OrderedStream {
public:
    vector<string>vec;
    int ptr=0;
    OrderedStream(int n) {
        vector<string>str(n);
        vec=str;
    }
    
    vector<string> insert(int idKey, string value) {
        vec[idKey-1]=value;
        int i;
        for(i=ptr;i<vec.size();i++)
        {
            if(vec[i]=="")
                break;
        }
        if(i==ptr)
        {
            if(vec[i].size()==0)
                return {};
            else
                return {vec[i]};
        }
        vector<string> result(i - ptr );
        copy(vec.begin()+ptr, vec.begin()+i, result.begin());
        ptr=i;
        return result;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */