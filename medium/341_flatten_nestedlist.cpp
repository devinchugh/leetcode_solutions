#include <bits/stdc++.h>
using namespace std;

class NestedInteger
{
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator
{
public:
    vector<NestedInteger> mylist;
    queue<int> q;
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        mylist=nestedList;
        addlist(mylist);
    }

    void addlist(vector<NestedInteger> List){
        for (auto &&i : List)
        {
            if(i.isInteger()){
                q.push(i.getInteger());
            }
            else{
                addlist(i.getList());
            }
        }
    }

    int next()
    {
        int num = q.front();
        q.pop();
        return num;
        
    }

    bool hasNext()
    {
        return q.size();
    }
};