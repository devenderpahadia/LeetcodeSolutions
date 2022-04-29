/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<int>res;
    int i = 0;
    void solve(vector<NestedInteger>nums)
    {
        for(int j=0;j<nums.size();j++)
        {
            if(nums[j].isInteger())
            {
                res.push_back(nums[j].getInteger());
            }
            else
            {
                solve(nums[j].getList());
            }
        }
    }
    NestedIterator(vector<NestedInteger> &nums) {
        solve(nums);
    }
    
    int next() {
        i++;
        return res[i-1];
    }
    
    bool hasNext() {
        if(i<res.size())
            return true;
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */